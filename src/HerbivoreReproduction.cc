/**
 * Herbivore's (concrete) Action of reproduction.
 */

#include <include/ALife/HerbivoreReproduction.h>
#include <include/ALife/Herbivore.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Vector.h>
#include <include/ALife/RandomGenerator.h>

HerbivoreReproduction::HerbivoreReproduction(Herbivore* const owner, Simulation* const simulation) :
		HerbivoreAction(owner, simulation),
		timeDuration_(0)
{}

void HerbivoreReproduction::act()
{
	++timeDuration_;
	Vector partnerVector;

	Herbivore* matchedPartner = simulation_->getBestSeenPartner(concreteOwner_);

	if(matchedPartner)
	{
		//calculate vector to seen food
		partnerVector =
				Vector::getShortestVectorBetweenPositions(owner_->getPosition(), matchedPartner->getPosition());

		//if partner is near enough - pair with it!
		if (partnerVector.getLength() <= 2 * Herbivore::getRadius())
		{
			//concreteOwner_->pairWith(matchedPartner);
			simulation_->produceBabies(concreteOwner_, matchedPartner);
			concreteOwner_->finishReproduction();
			matchedPartner->finishReproduction();
		}

			//go for distant partner
		else if (partnerVector != Vector())
			this->goForIt(partnerVector, matchedPartner);
	}
}

void HerbivoreReproduction::goForIt(const Vector& partnerVector, Herbivore* matchedPartner)
{
	const auto velocity = owner_->getIndividualSpeedValueAfter(owner_->getTimeAlive());

	const auto direction = partnerVector.getUnitVector();
	auto intendedVelocity = direction * velocity;

	//if Carnivore is about to "jump above" the partner when it is moving too fast
	if(partnerVector.getLength() - Herbivore::getRadius() < intendedVelocity.getLength())
	{
		intendedVelocity = direction * (partnerVector.getLength() - Herbivore::getRadius());
		owner_->setVelocity(intendedVelocity);
		//concreteOwner_->pairWith(matchedPartner);
		simulation_->produceBabies(concreteOwner_, matchedPartner);
		concreteOwner_->finishReproduction();
		matchedPartner->finishReproduction();
	} else
		owner_->setVelocity(intendedVelocity);
}
