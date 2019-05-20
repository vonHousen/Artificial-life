/**
 * Carnivore's (concrete) Action - eating
 */

#include <include/ALife/CarnivoreHunting.h>

#include "CarnivoreHunting.h"
#include "Carnivore.h"
#include "Simulation.h"
#include "Vector.h"

CarnivoreHunting::CarnivoreHunting(Carnivore* const owner, Simulation* const simulation) :
	CarnivoreAction(owner, simulation),
	timeDuration_(0)
{}

void CarnivoreHunting::act()
{
	timeDuration_++;

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
		this->goForIt(foodVector);
	}
}

void CarnivoreHunting::goForIt(const Vector &foodVector)
{
	auto velocity = owner_->getIndividualSpeedValueAfter(timeDuration_);

	auto direction = foodVector.getUnitVector();
	auto intendedVelocity = direction * velocity;

	//if Carnivore is about to "jump above" the food when it is moving too fast
	if(foodVector.getLength() - Carnivore::getRadius() < intendedVelocity.getLength())
	{
		intendedVelocity = direction * (foodVector.getLength() - Carnivore::getRadius());
		owner_->setVelocity(intendedVelocity);
		auto foodPosition = foodVector + owner_->getPosition();
		owner_->eatIt(foodPosition);

	} else
		owner_->setVelocity(intendedVelocity);

}
