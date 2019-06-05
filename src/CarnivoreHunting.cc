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
	timeDuration_(0),
	smelledPray_(nullptr)
{}

void CarnivoreHunting::act()
{
	Vector foodVector;
	timeDuration_++;

	//Organism is hungry, it needs to find the nearest food
	Herbivore* pray = simulation_->getNearestPrey(concreteOwner_, owner_->getSightRange());

	if(pray)
	{
		//organism now uses sight instead of smell
		smelledPray_ = nullptr;

		//calculate vector to seen food
		foodVector = pray->getPosition() - owner_->getPosition();

	} else	//if there are no seen herbivores - try going for smell
	{
		if(smelledPray_)
		{
			//calculate vector to smelled food
			foodVector = smelledPray_->getPosition() - owner_->getPosition();

		} else
			smelledPray_ = this->smellPray();

	}


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

void CarnivoreHunting::goForIt(const Vector& foodVector, Herbivore* pray)
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

Herbivore* CarnivoreHunting::smellPray()
{
	if(timeDuration_%50 != 0)													// TODO adjust frequency
		return nullptr;

	const double PRECISION_OF_SMELL = owner_->getAlertness() * 0.1;				// TODO adjust precision
	const Vector SMELLED_POSITION = Vector();									// TODO randomise location
	Herbivore* smelledOrganism = simulation_->getOrganismAt(SMELLED_POSITION, PRECISION_OF_SMELL);

	return smelledOrganism;
}
