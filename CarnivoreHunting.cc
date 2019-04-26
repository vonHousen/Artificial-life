/*
 * Carnivore (concrete) Action - hunting
 */

#include "CarnivoreHunting.h"
#include "Simulation.h"

CarnivoreHunting::CarnivoreHunting(Organism *const owner, Simulation *const simulation) :
	CarnivoreAction(owner, simulation)
{}

void CarnivoreHunting::act()
{
	//Organism is hungry, it needs to find the nearest food
	auto foodVector = simulation_->getNearestPreyVector(owner_);

	//if food is near enough - eat it!
	if(foodVector.getLength() <= Carnivore::getRadius())
		//owner_->eatIt() TODO
	{}
	else
		owner_->setVelocity(foodVector);
}
