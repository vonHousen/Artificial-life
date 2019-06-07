/**
 * Abstract class for all types of actions organism can perform driven by needs
 */

#include <include/ALife/Action.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Herbivore.h>

Action::Action(Organism* const owner, Simulation* const simulation) :
	owner_		(owner),
	simulation_	(simulation)
{}

Action::Action(Carnivore* const owner, Simulation* const simulation) :
	owner_		(owner),
	simulation_	(simulation)
{}

Action::Action(Herbivore* const owner, Simulation* const simulation) :
	owner_		(owner),
	simulation_	(simulation)
{}

bool Action::goToSleep(unsigned int timeDuration, unsigned int sleepingTime, const Vector& location, double tiredness)
{
	constexpr float EPS = 0.001;

	const auto sleepingVector = Vector::getShortestVectorBetweenPositions(owner_->getPosition(), location);

	if (sleepingVector.getLength() > EPS)
	{
		const auto velocity = owner_->getIndividualSpeedValueAfter(timeDuration);

		const auto direction = sleepingVector.getUnitVector();
		const auto intendedVelocity = direction * velocity;

		owner_->setVelocity(intendedVelocity);

		return false;

	} else
	{
		const unsigned int correctionFactor = tiredness * 100;
		const unsigned int timeToSleepWell = correctionFactor * owner_->getStamina();

		if(sleepingTime >= timeToSleepWell)
			owner_->sleepWell();

		return true;
	}
}
