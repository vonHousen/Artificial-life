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
	view_(nullptr),
	timeDuration_(0)
{}

Simulation::~Simulation()
{
	for(auto organism : carnivores_)
		delete organism;

	for(auto organism : herbivores_)
		delete organism;

	for(auto organism : carnivoresToAdd_)
		delete organism;

	for(auto organism : herbivoresToAdd_)
		delete organism;
}

void Simulation::getStatistics(StatisticsVisitor& stats) const
{
	for(auto organism : carnivores_)
		organism->accept(stats);

	for(auto organism : herbivores_)
		organism->accept(stats);
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

void Simulation::addOrganismToQueue(Carnivore* const newOrganism)
{
	carnivoresToAdd_.push_back(newOrganism);
}

void Simulation::addOrganismToQueue(Herbivore* const newOrganism)
{
	herbivoresToAdd_.push_back(newOrganism);
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
		if(foodVector.getLength() <= nearestFoodVector.getLength()
			and not tastyOrganism->isHidden()
			and tastyOrganism->isAlive())
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
	++timeDuration_;

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

	for(auto newCarni : carnivoresToAdd_)
	{
		addOrganism(newCarni);
	}
	carnivoresToAdd_.clear();

	for(auto newHerbi : herbivoresToAdd_)
	{
		addOrganism(newHerbi);
	}
	herbivoresToAdd_.clear();

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

void Simulation::produceBabies(const Carnivore* parentA, const Carnivore* parentB)
{
	float avgLifespan = 0.5 * (parentA->getLifespan() + parentB->getLifespan());
	
	float bestLifespan = 0.0;
	for(auto carni : carnivores_)
	{
		if(carni->getLifespan() > bestLifespan)
			bestLifespan = carni->getLifespan();
	}

	float fitness = avgLifespan / bestLifespan;

	//Adding 0.5 to round result to nearest integer
	unsigned int numChildren = 1 + 2.0 * fitness + 0.5;

	for(unsigned int i = 0; i < numChildren; ++i)
	{
		addOrganismToQueue(parentA->reproduceWith(parentB));
	}
}

void Simulation::produceBabies(const Herbivore* parentA, const Herbivore* parentB)
{
	float avgLifespan = 0.5 * (parentA->getLifespan() + parentB->getLifespan());
	
	float bestLifespan = 0.0;
	for(auto herbi : herbivores_)
	{
		if(herbi->getLifespan() > bestLifespan)
			bestLifespan = herbi->getLifespan();
	}

	float fitness = avgLifespan / bestLifespan;

	//Adding 0.5 to round result to nearest integer
	unsigned int numChildren = 1 + 2.0 * fitness + 0.5;

	for(unsigned int i = 0; i < numChildren; ++i)
	{
		addOrganismToQueue(parentA->reproduceWith(parentB));
	}
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
		   and potentialPartner != lonelyCarnivore
		   and potentialPartner->getTimeAlive() > bestFitnessFunVal)
		{
			partner = potentialPartner;
			bestFitnessFunVal = partner->getLifespan();
		}
	}

	return partner;
}

Herbivore* Simulation::getBestSeenPartner(const Herbivore* lonelyHerbivore)	//TODO make it a template for unification of code
{
	if(herbivores_.empty())
		return nullptr;

	// set the maximal sight range
	Herbivore* partner = nullptr;
	double bestFitnessFunVal = 0.0;

	// look for potential partner
	for(const auto potentialPartner : herbivores_)
	{
		if(potentialPartner->getSuggestedAction() == LeadingDesire::REPRODUCTION
		   and potentialPartner != lonelyHerbivore
		   and potentialPartner->getTimeAlive() > bestFitnessFunVal)
		{
			partner = potentialPartner;
			bestFitnessFunVal = partner->getLifespan();
		}
	}

	return partner;
}

bool Simulation::isInCave(const Herbivore* herbi)
{
	bool isInCave = false;
	const auto caves = this->map_.getCaveLocations();
	const auto caveRadius = Map::getCaveRadius();

	for(const auto cave : caves)
	{
		if(Vector::getShortestVectorBetweenPositions(cave, herbi->getPosition()).getLength() < caveRadius)
		{
			isInCave = true;
			break;
		}
	}

	return isInCave;
}

unsigned int Simulation::getSimulationTime()
{
	return timeDuration_;
}
