/**
 * Main class responsible for simulation
 */

#include "Simulation.h"
#include "SimulationView.h"
#include "Carnivore.h"
#include "Herbivore.h"

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

	Vector foodVector, nearestFoodVector(1,1);

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
	for(auto carnivoreIterator=carnivores_.begin(); carnivoreIterator!=carnivores_.end(); )
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

	for(auto herbivoreIterator=herbivores_.begin(); herbivoreIterator!=herbivores_.end(); )
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
	for(auto organism : carnivores_)
		if(organism->getPosition() == position)
			return organism;

	for(auto organism : herbivores_)
		if(organism->getPosition() == position)
			return organism;

	return nullptr;
}
