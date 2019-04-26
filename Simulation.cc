/*
 * Main class for simulation
 */

#include "Simulation.h"

void Simulation::addOrganism(Organism* const new_organism)
{
	organisms_.push_back(new_organism);
}

Vector Simulation::getVectorToNearestPrey(Organism *hunter) const
{
	std::vector<Organism*> tastyOrganisms;

	for(auto organism : organisms_)
		if(typeid(organism) != typeid(hunter))
			tastyOrganisms.push_back(organism);

	if(tastyOrganisms.empty())
		return Vector();

	Vector foodVector, nearestFoodVector(1,1);

	for(auto food : tastyOrganisms){

		foodVector = hunter->getPosition().getShortestVectorToPosition(food->getPosition());
		if(foodVector.getLength() <= nearestFoodVector.getLength())
			nearestFoodVector = foodVector;
	}

	return nearestFoodVector;
}

void Simulation::update()
{
	for(auto organism : organisms_)
		organism->update();
}
