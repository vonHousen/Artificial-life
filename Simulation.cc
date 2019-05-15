/*
 * Main class for simulation
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
		foodVector = getShortestVectorBetweenPositions(hunter->getPosition(), tastyOrganism->getPosition());
		if(foodVector.getLength() <= nearestFoodVector.getLength())
			nearestFoodVector = foodVector;
	}

	return nearestFoodVector;
}

void Simulation::update()
{
	if(view_) view_->update();

	for(auto organism : carnivores_)
		organism->update();

	for(auto organism : herbivores_)
		organism->update();

	// TODO implement deleting dead organisms
}

Organism *Simulation::getOrganismAt(const Vector &position)
{
	for(auto organism : carnivores_)
		if(organism->getPosition() == position)
			return organism;

	for(auto organism : herbivores_)
		if(organism->getPosition() == position)
			return organism;

	return nullptr;
}
