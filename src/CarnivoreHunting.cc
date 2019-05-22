/**
 * Carnivore's (concrete) Action - eating
 */

#include <include/ALife/CarnivoreHunting.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Herbivore.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Vector.h>

CarnivoreHunting::CarnivoreHunting(Carnivore* const owner, Simulation* const simulation) :
	CarnivoreAction(owner, simulation),
	timeDuration_(0)
{}

void CarnivoreHunting::act()
{
	timeDuration_++;

	//Organism is hungry, it needs to find the nearest food
	Herbivore* pray = simulation_->getNearestPrey(concreteOwner_, owner_->getSightRange());

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
		this->goForIt(foodVector, pray);
	}
}

void CarnivoreHunting::goForIt(const Vector &foodVector, Herbivore *pray)
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
		concreteOwner_->eatPray(pray);

	} else
		owner_->setVelocity(intendedVelocity);

}
