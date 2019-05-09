/*
 * Carnivore (concrete) Action - hunting
 */

#include "CarnivoreHunting.h"
#include "Carnivore.h"
#include "Simulation.h"
#include "Vector.h"

CarnivoreHunting::CarnivoreHunting(Carnivore *const owner, Simulation *const simulation) :
	CarnivoreAction(owner, simulation)
{}

void CarnivoreHunting::act()
{
	//Organism is hungry, it needs to find the nearest food
	auto foodVector = simulation_->getVectorToNearestPrey(concreteOwner_);

	//if foodVector points to nowhere (length of zero) - do nothing
	if(foodVector == Vector())
		return;

	//if food is near enough - eat it!
	if(foodVector.getLength() <= 2*Carnivore::getRadius())
	{
		auto foodPosition = foodVector + owner_->getPosition();
		owner_->eatIt(foodPosition);
	}
	else //go for it
	{
		auto correctionFactor = 1.0 - 2*Carnivore::getRadius()/foodVector.getLength();
		auto velocityFactor = 1.0;

		owner_->setVelocity(foodVector*velocityFactor*correctionFactor);		//TODO change dummy velocity to real one
	}
}
