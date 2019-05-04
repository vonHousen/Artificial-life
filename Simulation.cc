/*
 * Main class for simulation
 */

#include "Simulation.h"
#include "SimulationView.h"
#include "Carnivore.h"
#include "Herbivore.h"

Simulation::Simulation():
	view_(nullptr)
{}

Simulation::~Simulation()
{
	for(auto organism : organisms_)
		delete organism;
}

void Simulation::addOrganism(Organism* const newOrganism)
{
	newOrganism->setSimulation(this);
	organisms_.push_back(newOrganism);
	if(view_) view_->notifyWhenOrganismAdded(newOrganism);
}

void Simulation::registerView(SimulationView* const simulationView)
{
	view_ = simulationView;
}

Vector Simulation::getVectorToNearestPrey(Carnivore *hunter) const
{
	std::vector<Organism*> tastyOrganisms;

	for(auto organism : organisms_)
		if(typeid(organism) != typeid(hunter))
			tastyOrganisms.push_back(organism);

	if(tastyOrganisms.empty())
		return {};

	Vector foodVector, nearestFoodVector(1,1);

	for(auto food : tastyOrganisms)
	{
		foodVector = hunter->getPosition().getShortestVectorToPosition(food->getPosition());
		if(foodVector.getLength() <= nearestFoodVector.getLength())
			nearestFoodVector = foodVector;
	}

	return nearestFoodVector;
}

void Simulation::update()
{
	if(view_) view_->update();

	for(auto organism : organisms_)
		organism->update();
}

Organism *Simulation::getOrganismAt(const Vector &position)
{
	for(auto organism : organisms_)
		if(organism->getPosition() == position)
			return organism;

	return nullptr;
}
