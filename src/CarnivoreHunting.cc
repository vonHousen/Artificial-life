/**
 * Carnivore's (concrete) Action - eating
 */

#include "CarnivoreHunting.h"
#include "Carnivore.h"
#include "Simulation.h"
#include "Vector.h"

CarnivoreHunting::CarnivoreHunting(Carnivore* const owner, Simulation* const simulation) :
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
		auto correctionFactor = 1.0;	// - 2*Carnivore::getRadius()/foodVector.getLength();
		auto velocityFactor = 0.001;	//1.0;
		auto intendedVelocity = foodVector.getUnitVector()*velocityFactor*correctionFactor;

		//if Carnivore is about to "jump above" the food when it is moving too fast
		if(foodVector.getLength() - Carnivore::getRadius() < intendedVelocity.getLength())
		{
			intendedVelocity = foodVector.getUnitVector() * (foodVector.getLength() - Carnivore::getRadius());
			owner_->setVelocity(intendedVelocity);
			auto foodPosition = foodVector + owner_->getPosition();
			owner_->eatIt(foodPosition);
		}

		owner_->setVelocity(intendedVelocity);		//TODO change dummy velocity to real one
	}
}
