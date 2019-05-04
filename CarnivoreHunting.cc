/*
 * Carnivore (concrete) Action - hunting
 */

#include "CarnivoreHunting.h"
#include "Carnivore.h"
#include "Simulation.h"
#include "Vector.h"

CarnivoreHunting::CarnivoreHunting(Carnivore *const owner, Simulation *const simulation) :
	CarnivoreAction(owner, simulation),
	concreteOwner_(owner)
{}

void CarnivoreHunting::act()
{
	//Organism is hungry, it needs to find the nearest food
	auto foodVector = simulation_->getVectorToNearestPrey(concreteOwner_);

	//if foodVector points to nowhere (length of zero) - do nothing
	if(foodVector == Vector())
		return;

	//if food is near enough - eat it!
	if(foodVector.getLength() <= Carnivore::getRadius())
	{
		auto foodPosition = foodVector + owner_->getPosition();
		owner_->eatIt(foodPosition);
	}
	else
		owner_->setVelocity(foodVector);		//TODO change dummy velocity to real one
}
