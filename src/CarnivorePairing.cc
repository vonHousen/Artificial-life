/**
 * Carnivore's (concrete) Action of pairing.
 */

#include <include/ALife/CarnivorePairing.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Vector.h>
#include <include/ALife/RandomGenerator.h>

CarnivorePairing::CarnivorePairing(Carnivore* const owner, Simulation* const simulation) :
		CarnivoreAction(owner, simulation),
		timeDuration_(0),
		smelledPartner_(nullptr)
{}

void CarnivorePairing::act()
{
	++timeDuration_;
	Vector partnerVector;

	Carnivore* matchedPartner = simulation_->getBestSeenPartner(concreteOwner_);

	if(matchedPartner)
	{
		//organism now uses sight instead of smell
		smelledPartner_ = nullptr;

		//calculate vector to seen food
		partnerVector =
				Vector::getShortestVectorBetweenPositions(owner_->getPosition(), matchedPartner->getPosition());

	} else //if there are no seen carnivores - try going for smell
	{
		if(smelledPartner_ and smelledPartner_->isAlive())
		{
			//calculate vector to smelled food
			partnerVector =
					Vector::getShortestVectorBetweenPositions(owner_->getPosition(), smelledPartner_->getPosition());

		} else
			smelledPartner_ = this->smellPartner();
	}


	//if partner is near enough - pair with it!
	if(partnerVector != Vector() and partnerVector.getLength() <= 2*Carnivore::getRadius())
		concreteOwner_->pairWith(matchedPartner);

		//go for distant partner
	else if(partnerVector != Vector())
		this->goForIt(partnerVector, matchedPartner);

}

void CarnivorePairing::goForIt(const Vector& partnerVector, Carnivore* matchedPartner)
{
	const auto velocity = owner_->getIndividualSpeedValueAfter(owner_->getTimeAlive());

	const auto direction = partnerVector.getUnitVector();
	auto intendedVelocity = direction * velocity;

	//if Carnivore is about to "jump above" the partner when it is moving too fast
	if(partnerVector.getLength() - Carnivore::getRadius() < intendedVelocity.getLength())
	{
		intendedVelocity = direction * (partnerVector.getLength() - Carnivore::getRadius());
		owner_->setVelocity(intendedVelocity);
		concreteOwner_->pairWith(matchedPartner);

	} else
		owner_->setVelocity(intendedVelocity);
}

Carnivore* CarnivorePairing::smellPartner()
{
	if(timeDuration_%40 != 0)
		return nullptr;

	constexpr double ALERTNESS_CORRECTION_FACTOR = 0.05;
	const double precisionOfSmell = owner_->getAlertness() * ALERTNESS_CORRECTION_FACTOR;

	constexpr double coordCorrectionFactor = 2.0;
	const double xRandCoord = coordCorrectionFactor * RandomGenerator::getInstance()->getSampleUniform();
	const double yRandCoord = coordCorrectionFactor * RandomGenerator::getInstance()->getSampleUniform();

	Carnivore* smelledOrganism = simulation_->getCarnivoreAt(Vector(xRandCoord, yRandCoord), precisionOfSmell);
	if( smelledOrganism != nullptr
		and smelledOrganism->getSuggestedAction() == LeadingDesire::REPRODUCTION
	    and not smelledOrganism->isParenting()
	    and smelledOrganism != owner_)

	return smelledOrganism;
}
