/**
 * Carnivore's (concrete) Action - eating
 */

#include "CarnivoreHunting.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include "Simulation.h"
#include "Vector.h"

CarnivoreHunting::CarnivoreHunting(Carnivore* const owner, Simulation* const simulation) :
	CarnivoreAction(owner, simulation)
{}

void CarnivoreHunting::act()
{
	//Organism is hungry, it needs to find the nearest food
	Herbivore* pray = simulation_->getNearestPrey(concreteOwner_);

	//if pray points to nowhere (there are no herbivores) - do nothing
	if(pray == nullptr)
		return;

	//calculate vector to food
	auto foodVector = owner_->getPosition() - pray->getPosition();

	//if food is near enough - eat it!
	if(foodVector.getLength() <= 2*Carnivore::getRadius())
	{
		concreteOwner_->eatPray(pray);
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
			concreteOwner_->eatPray(pray);
		}

		owner_->setVelocity(intendedVelocity);		//TODO change dummy velocity to real one
	}
}
