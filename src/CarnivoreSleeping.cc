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
		sleepingTime_(0),
		tiredness_(owner->getTiredness())
{
	constexpr int CORRECTION_FACTOR = 2;
	const double xRandCoord = - RandomGenerator::getInstance()->getSampleUniform();
	const double yRandCoord = CORRECTION_FACTOR * RandomGenerator::getInstance()->getSampleUniform();

	sleepingPosition_ = Vector(xRandCoord, yRandCoord);
}

void CarnivoreSleeping::act()
{
	++timeDuration_;

	if(goToSleep(timeDuration_, sleepingTime_, sleepingPosition_))
	{
		const unsigned int correctionFactor = tiredness_ * 100;
		const unsigned int timeToSleepWell = correctionFactor * owner_->getStamina();
		++sleepingTime_;

		if(sleepingTime_ >= timeToSleepWell)
			owner_->sleptWell();
	}
}
