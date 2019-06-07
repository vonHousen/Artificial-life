/**
 * Main class responsible for simulation
 */

#include <include/ALife/Simulation.h>
#include <include/ALife/SimulationView.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Herbivore.h>
#include <include/ALife/RandomGenerator.h>

#include <algorithm>

Simulation::Simulation():
	view_(nullptr)
{}

Simulation::~Simulation()
{
	for(auto organism : carnivores_)
		delete organism;

	for(auto organism : herbivores_)
		delete organism;
}

void Simulation::addOrganism(Carnivore* const newOrganism)
{
	newOrganism->setSimulation(this);
	carnivores_.push_back(newOrganism);
	if(view_) view_->notifyWhenOrganismAdded(newOrganism);
}

void Simulation::addOrganism(Herbivore* const newOrganism)
{
	newOrganism->setSimulation(this);
	herbivores_.push_back(newOrganism);
	if(view_) view_->notifyWhenOrganismAdded(newOrganism);
}

void Simulation::registerView(SimulationView* const simulationView)
{
	view_ = simulationView;
	simulationView->createViewsForMap(&map_);
}

int Simulation::getCarnivoreCount() const
{
	return carnivores_.size();
}

int Simulation::getHerbivoreCount() const
{
	return herbivores_.size();
}

Herbivore* Simulation::getNearestPrey(Carnivore* hunter, double sightRange) const
{
	if(herbivores_.empty())
		return nullptr;

	Vector foodVector, nearestFoodVector(1, 0);
	const double normalizationFactor = 0.04 * sightRange + 0.2;

	// set the maximal sight range
	nearestFoodVector = nearestFoodVector * normalizationFactor;
	Herbivore* pray = nullptr;

	for(auto tastyOrganism : herbivores_)
	{
		foodVector = Vector::getShortestVectorBetweenPositions(hunter->getPosition(), tastyOrganism->getPosition());
		if(foodVector.getLength() <= nearestFoodVector.getLength() and tastyOrganism->isAlive())
		{
			nearestFoodVector = foodVector;
			pray = tastyOrganism;
		}
	}
	
	return pray;
}

Carnivore* Simulation::getNearestPredator(Herbivore* herbi, double sightRange) const
{
	if(carnivores_.empty())
		return nullptr;

	Vector predatorVector, nearestPredatorVector(1, 0);
	const double normalizationFactor = 0.04 * sightRange + 0.1;

	// set the maximal sight range
	nearestPredatorVector = nearestPredatorVector * normalizationFactor;
	Carnivore* predator = nullptr;

	// TODO add additional organisms for lookup due to alertness (may be random for simplicity?) (not here though)

	for(auto scaryHunter : carnivores_)
	{
		predatorVector = Vector::getShortestVectorBetweenPositions(herbi->getPosition(), scaryHunter->getPosition());

		if(predatorVector.getLength() <= nearestPredatorVector.getLength()
			and scaryHunter->getSuggestedAction() == LeadingDesire::EATING)
		{
			nearestPredatorVector = predatorVector;
			predator = scaryHunter;
		}
	}

	return predator;
}

MapTile* Simulation::getNearestGrass(Herbivore* herbi)
{
	return map_.getNearestMapTile(herbi);
}

void Simulation::update()
{
	map_.update();

	for(auto carnivoreIterator = carnivores_.begin(); carnivoreIterator != carnivores_.end();)
	{
		auto carnivore = *carnivoreIterator;

		if (carnivore->isAlive())
		{
			carnivore->update();
			++carnivoreIterator;

		} else		// remove organism from Simulation
		{
			carnivoreIterator = carnivores_.erase(carnivoreIterator);
			if(view_) view_->notifyWhenOrganismRemoved(carnivore);
			delete carnivore;
		}
	}

	for(auto herbivoreIterator = herbivores_.begin(); herbivoreIterator != herbivores_.end();)
	{
		auto herbivore = *herbivoreIterator;

		if (herbivore->isAlive())
		{
			herbivore->update();
			++herbivoreIterator;

		} else		// remove organism from Simulation
		{
			herbivoreIterator = herbivores_.erase(herbivoreIterator);
			if(view_) view_->notifyWhenOrganismRemoved(herbivore);
			delete herbivore;
		}
	}

	if(view_)
		view_->update();
}

Herbivore* Simulation::getHerbivoreAt(const Vector& position, double precision)
{
	if (precision <= 0.0)
		return nullptr;

	for(auto organism : herbivores_)
		if(fabs(organism->getPosition().getX() - position.getX()) < precision and
		   fabs(organism->getPosition().getY() - position.getY()) < precision)
			return organism;

	return nullptr;
}

Carnivore* Simulation::getCarnivoreAt(const Vector& position,  double precision)
{
	if (precision <= 0.0)
		return nullptr;

	for(auto organism : carnivores_)
		if(fabs(organism->getPosition().getX() - position.getX()) < precision and
		   fabs(organism->getPosition().getY() - position.getY()) < precision)
			return organism;

	return nullptr;
}

void Simulation::reset(int carnivoreCount, int herbivoreCount)
{
	for(auto organism : carnivores_)
	{
		if(view_) view_->notifyWhenOrganismRemoved(organism);
		delete organism;
	}
	carnivores_.clear();

	for(auto organism : herbivores_)
	{
		if(view_) view_->notifyWhenOrganismRemoved(organism);
		delete organism;
	}
	herbivores_.clear();

	initializeSimulation(carnivoreCount, herbivoreCount);

	map_.reset();
}

void Simulation::initializeSimulation(int carnivoreCount, int herbivoreCount)
{
	const float CELL_SIZE = 2.2 * Organism::getRadius();
	const int CELLS_IN_ROW = 1.0 / CELL_SIZE;
	const int CELLS_IN_COLUMN = 2.0 / CELL_SIZE;
	const int NUM_CELLS = CELLS_IN_COLUMN * CELLS_IN_ROW;

	//Create pool of numbers (cell indexes from 0 to NUM_CELLS - 1) and shuffle them
	std::vector<int> pool(NUM_CELLS);
	std::iota(pool.begin(), pool.end(), 0);
	
	auto& rng = RandomGenerator::getInstance()->getGenerator();
	std::shuffle(pool.begin(), pool.end(), rng);

	for(int i = 0; i < carnivoreCount; ++i)
	{
		int cellIndex = pool[i];
		int cellY = cellIndex / CELLS_IN_ROW;
		int cellX = cellIndex - cellY*CELLS_IN_ROW;

		//Carnivores go to the left side of the window, hence there is a minus in organismX
		float organismX = -cellX * CELL_SIZE + 0.5*CELL_SIZE;
		float organismY = cellY * CELL_SIZE + 0.5*CELL_SIZE - 1;

		auto genes = std::make_unique<Genotype>();
		addOrganism(new Carnivore(std::move(genes), Vector(organismX, organismY), this));
	}

	std::shuffle(pool.begin(), pool.end(), rng);
	for(int i = 0; i < herbivoreCount; ++i)
	{
		int cellIndex = pool[i];
		int cellY = cellIndex / CELLS_IN_ROW;
		int cellX = cellIndex - cellY*CELLS_IN_ROW;

		float organismX = cellX * CELL_SIZE + 0.5*CELL_SIZE;
		float organismY = cellY * CELL_SIZE + 0.5*CELL_SIZE - 1;

		auto genes = std::make_unique<Genotype>();
		addOrganism(new Herbivore(std::move(genes), Vector(organismX, organismY), this));
	}
}

std::pair<Vector, double> Simulation::getNearestCave(const Herbivore* herbi)
{
	const Vector herbiPosition = herbi->getPosition();
	const auto caveVec = map_.getCaveLocations();
	std::pair<Vector, double> nearestCave(Vector(1,1), 2.0);

	std::for_each(caveVec.begin(), caveVec.end(),
			[&nearestCave, herbiPosition](const auto cave)
			{
				const auto distance = Vector::getShortestVectorBetweenPositions(herbiPosition, cave).getLength();
				if(distance < nearestCave.second)
					nearestCave = {cave, distance};
			} );

	return {nearestCave.first, Map::getCaveRadius()};
}

Carnivore* Simulation::getBestSeenPartner(const Carnivore* lonelyCarnivore)
{
	if(carnivores_.empty())
		return nullptr;

	// set the maximal sight range
	Carnivore* partner = nullptr;
	double bestFitnessFunVal = 0.0;

	// look for potential partner
	for(const auto potentialPartner : carnivores_)
	{
		if(potentialPartner->getSuggestedAction() == LeadingDesire::REPRODUCTION
		   and not potentialPartner->isParenting()
		   and potentialPartner != lonelyCarnivore
		   and potentialPartner->getTimeAlive() > bestFitnessFunVal)
		{
			partner = potentialPartner;
			bestFitnessFunVal = partner->getLifespan();
		}
	}

	return partner;
}
