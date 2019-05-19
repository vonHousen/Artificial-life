/**
 * Main class responsible for simulation
 */

#include "Simulation.h"
#include "SimulationView.h"
#include "Carnivore.h"
#include "Herbivore.h"

#include <algorithm>
#include <random>

Simulation::Simulation():
	carnivoreCount_(0),
	herbivoreCount_(0),
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
	carnivoreCount_ += 1;
	if(view_) view_->notifyWhenOrganismAdded(newOrganism);
}

void Simulation::addOrganism(Herbivore* const newOrganism)
{
	newOrganism->setSimulation(this);
	herbivores_.push_back(newOrganism);
	herbivoreCount_ += 1;
	if(view_) view_->notifyWhenOrganismAdded(newOrganism);
}

void Simulation::registerView(SimulationView* const simulationView)
{
	view_ = simulationView;
}

int Simulation::getCarnivoreCount() const
{
	return carnivoreCount_;
}

int Simulation::getHerbivoreCount() const
{
	return herbivoreCount_;
}

Vector Simulation::getVectorToNearestPrey(Carnivore* hunter) const
{
	if(herbivores_.empty())
		return {};

	Vector foodVector, nearestFoodVector(1, 1);

	for(auto tastyOrganism : herbivores_)
	{
		foodVector = Vector::getShortestVectorBetweenPositions(hunter->getPosition(), tastyOrganism->getPosition());
		if(foodVector.getLength() <= nearestFoodVector.getLength())
			nearestFoodVector = foodVector;
	}

	return nearestFoodVector;
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
			carnivoreCount_--;
			if(view_)
				view_->notifyWhenOrganismRemoved(carnivore);
			carnivoreIterator = carnivores_.erase(carnivoreIterator);
		}
	}

	for(auto herbivoreIterator=  herbivores_.begin(); herbivoreIterator != herbivores_.end();)
	{
		auto herbivore = *herbivoreIterator;

		if (herbivore->isAlive())
		{
			herbivore->update();
			++herbivoreIterator;

		} else		// remove organism from Simulation
		{
			herbivoreCount_--;
			if(view_)
				view_->notifyWhenOrganismRemoved(herbivore);
			herbivoreIterator = herbivores_.erase(herbivoreIterator);
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

void Simulation::initializeSimulation(int carnivores, int herbivores)
{
	const float CELL_SIZE = 1.5 * Organism::getRadius();
	const int CELLS_IN_ROW = 1.0 / CELL_SIZE;
	const int CELLS_IN_COLUMN = 2.0 / CELL_SIZE;
	const int NUM_CELLS = CELLS_IN_COLUMN * CELLS_IN_ROW;

	//Create pool of numbers (cell indexes from 0 to NUM_CELLS - 1) and shuffle them
	std::vector<int> pool(NUM_CELLS);
	std::iota(pool.begin(), pool.end(), 0);
	auto rng = std::default_random_engine(std::random_device()());
	std::shuffle(pool.begin(), pool.end(), rng);

	for(int i = 0; i < carnivores; ++i)
	{
		int cellIndex = pool[i];
		int cellY = cellIndex / CELLS_IN_ROW;
		int cellX = cellIndex - cellY*CELLS_IN_ROW;

		//Carnivores go to the left side of window, hence there is a minus in organismX
		float organismX = -cellX * CELL_SIZE + 0.5*CELL_SIZE;
		float organismY = cellY * CELL_SIZE + 0.5*CELL_SIZE - 1;

		auto genes = std::make_unique<Genotype>();
		addOrganism(new Carnivore(std::move(genes), Vector(organismX, organismY), this));
	}

	std::shuffle(pool.begin(), pool.end(), rng);
	for(int i = 0; i < herbivores; ++i)
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
