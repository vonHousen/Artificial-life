/*
 * Main class for simulation
 */

#include "Simulation.h"

void Simulation::addOrganism(Organism* const new_organism)
{
	organisms_.push_back(new_organism);
}

Vector Simulation::getNearestFoodLocation(const Carnivore& hunter) const
{
	std::vector<Organism*> tastyOrganisms;

	for(auto organism : organisms_)
		if(typeid(organism) != typeid(hunter))
			tastyOrganisms.push_back(organism);

	if(!tastyOrganisms.size())
		return hunter.getPosition();

	Vector nearestFoodLocation;
	double distance, shortestDistance = 2.0;	// 2.0 is actually way longer than any possible distance on the map


	for(auto food : tastyOrganisms){

		distance = (food->getPosition() - hunter.getPosition()).getLength();	// TODO
		if(distance <= shortestDistance){
			shortestDistance = distance;
			nearestFoodLocation = food->getPosition();
		}
	}

	return nearestFoodLocation;
}
