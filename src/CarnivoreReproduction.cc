/**
 * Carnivore's (concrete) Action of reproduction.
 */

#include <include/ALife/CarnivoreReproduction.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Vector.h>
#include <include/ALife/RandomGenerator.h>

CarnivoreReproduction::CarnivoreReproduction(Carnivore* const owner, Simulation* const simulation) :
		CarnivoreAction(owner, simulation),
		timeDuration_(0)
{
	constexpr unsigned int NORMALISATION_FACTOR = 500;
	expectedBirthTime_ = owner_->getSpeed() * NORMALISATION_FACTOR;
}

void CarnivoreReproduction::act()
{
	++timeDuration_;
	Vector partnerVector;


	Carnivore* matchedPartner = simulation_->getBestSeenPartner(concreteOwner_);

	if(matchedPartner)
	{
		//calculate vector to seen food
		partnerVector =
				Vector::getShortestVectorBetweenPositions(owner_->getPosition(), matchedPartner->getPosition());

		//if partner is near enough - pair with it!
		if (partnerVector.getLength() <= 2 * Carnivore::getRadius() and timeDuration_ > expectedBirthTime_)
		{
			simulation_->produceBabies(concreteOwner_, matchedPartner);
			concreteOwner_->finishReproduction();
			matchedPartner->finishReproduction();
		}
			//go for distant partner
		else if (partnerVector != Vector())
			this->goForIt(partnerVector, matchedPartner);
	}
}

void CarnivoreReproduction::goForIt(const Vector& partnerVector, Carnivore* matchedPartner)
{
	const auto velocity = owner_->getIndividualSpeedValueAfter(owner_->getTimeAlive());

	const auto direction = partnerVector.getUnitVector();
	auto intendedVelocity = direction * velocity;

	//if Carnivore is about to "jump above" the partner when it is moving too fast
	if(partnerVector.getLength() - Carnivore::getRadius() < intendedVelocity.getLength())
	{
		intendedVelocity = direction * (partnerVector.getLength() - Carnivore::getRadius());
		owner_->setVelocity(intendedVelocity);
		if(timeDuration_ > expectedBirthTime_)
		{
			simulation_->produceBabies(concreteOwner_, matchedPartner);
			concreteOwner_->finishReproduction();
			matchedPartner->finishReproduction();
		}
	} else
		owner_->setVelocity(intendedVelocity);
}