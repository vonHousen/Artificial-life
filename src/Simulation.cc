/**
 * Main class responsible for simulation
 */

#include <include/ALife/Simulation.h>
#include <include/ALife/SimulationView.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Herbivore.h>

#include <algorithm>
#include <random>
#include <chrono>

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
	const double NORMALISATION_FACTOR = 0.5;

	// set the maximal sight range
	nearestFoodVector = nearestFoodVector * sightRange * NORMALISATION_FACTOR;
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
	const double NORMALISATION_FACTOR = 0.5;

	// set the maximal sight range
	nearestPredatorVector = nearestPredatorVector * sightRange * NORMALISATION_FACTOR;
	Carnivore* predator = nullptr;

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

void Simulation::update()
{
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

Organism* Simulation::getOrganismAt(const Vector& position)
{
	const double EPS = 0.0001;

	for(auto organism : carnivores_)
		if(fabs(organism->getPosition().getX() - position.getX()) < EPS and
		   fabs(organism->getPosition().getY() - position.getY()) < EPS)
			return organism;

	for(auto organism : herbivores_)
		if(fabs(organism->getPosition().getX() - position.getX()) < EPS and
		   fabs(organism->getPosition().getY() - position.getY()) < EPS)
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
	auto rng = std::default_random_engine(
		std::chrono::high_resolution_clock::now().time_since_epoch().count());
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
