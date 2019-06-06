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
		sleepingTime_(0)
{
	const auto results = simulation_->getNearestCave(concreteOwner_);
	Vector positionInCave = Vector::getRandomVector(results.second);

	const double correctionFactor = RandomGenerator::getInstance()->getSampleUniform();
	positionInCave *= correctionFactor;

	sleepingPosition_ = Vector::getShortestVectorBetweenPositions(owner_->getPosition(), results.first + positionInCave);
}

void HerbivoreSleeping::act()
{
	++timeDuration_;

}