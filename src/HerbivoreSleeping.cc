/**
 * Herbivore's (concrete) Action - sleeping
 */

#include <include/ALife/HerbivoreSleeping.h>
#include <include/ALife/Herbivore.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Vector.h>
#include <include/ALife/RandomGenerator.h>

HerbivoreSleeping::HerbivoreSleeping(Herbivore* const owner, Simulation* const simulation) :
		HerbivoreAction(owner, simulation),
		timeDuration_(0),
		sleepingTime_(0),
		tiredness_(owner->getTiredness())
{
	const auto results = simulation_->getNearestCave(concreteOwner_);
	Vector positionInCave = Vector::getRandomVector(results.second);

	const double correctionFactor = RandomGenerator::getInstance()->getSampleUniform();
	positionInCave *= correctionFactor;

	sleepingPosition_ = results.first + positionInCave;

}

void HerbivoreSleeping::act()
{
	++timeDuration_;

	if(goToSleep(timeDuration_, sleepingTime_, sleepingPosition_))
	{
		if(not concreteOwner_->isHidden())
			concreteOwner_->hide();

		const unsigned int correctionFactor = tiredness_ * 100;
		const unsigned int timeToSleepWell = correctionFactor * owner_->getStamina();
		++sleepingTime_;

		if(sleepingTime_ >= timeToSleepWell)
			owner_->sleptWell();
	}
}