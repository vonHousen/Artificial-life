/**
 * Carnivore's (concrete) Action - sleeping
 */

#include <include/ALife/CarnivoreSleeping.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Vector.h>
#include <include/ALife/RandomGenerator.h>

CarnivoreSleeping::CarnivoreSleeping(Carnivore* const owner, Simulation* const simulation) :
		CarnivoreAction(owner, simulation),
		timeDuration_(0),
		sleepingTime_(0)
{
	constexpr int CORRECTION_FACTOR = 2;
	const double X_RAND_COORD = - RandomGenerator::getInstance()->getSampleUniform();
	const double Y_RAND_COORD = CORRECTION_FACTOR * RandomGenerator::getInstance()->getSampleUniform();

	sleepingPosition_ = Vector(X_RAND_COORD, Y_RAND_COORD);
}

void CarnivoreSleeping::act()
{
	++timeDuration_;
	constexpr float EPS = 0.001;

	const auto sleepingVector = sleepingPosition_ - owner_->getPosition();

	if(sleepingVector.getLength() > EPS)
	{
		const auto velocity = owner_->getIndividualSpeedValueAfter(timeDuration_);

		const auto direction = sleepingVector.getUnitVector();
		const auto intendedVelocity = direction * velocity;

		owner_->setVelocity(intendedVelocity);

	} else // if Carnivore is on sleeping position
	{
		constexpr unsigned int CORRECTION_FACTOR = 100;
		const unsigned int timeToSleepWell = CORRECTION_FACTOR * owner_->getStamina();

		if(++sleepingTime_ >= timeToSleepWell)
			concreteOwner_->sleepWell();
	}
}
