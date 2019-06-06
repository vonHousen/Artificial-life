/**
 * Carnivore's (concrete) Action - eating
 */

#include <include/ALife/CarnivoreHunting.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Herbivore.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Vector.h>
#include <include/ALife/RandomGenerator.h>

CarnivoreHunting::CarnivoreHunting(Carnivore* const owner, Simulation* const simulation) :
	CarnivoreAction(owner, simulation),
	timeDuration_(0),
	runDuration_(0),
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
		if(smelledPray_ and smelledPray_->isAlive())
		{
			//calculate vector to smelled food
			foodVector = smelledPray_->getPosition() - owner_->getPosition();

		} else
			smelledPray_ = this->smellPray();
	}


	//if food is near enough - eat it!
	if(foodVector != Vector() and foodVector.getLength() <= 2*Carnivore::getRadius())
		concreteOwner_->eatPray(pray);

	//go for distant pray
	else if(foodVector != Vector())
		this->goForIt(foodVector, pray);

}

void CarnivoreHunting::goForIt(const Vector& foodVector, Herbivore* pray)
{
	const auto velocity = owner_->getIndividualSpeedValueAfter(runDuration_++);

	const auto direction = foodVector.getUnitVector();
	auto intendedVelocity = direction * velocity;

	//if Carnivore is about to "jump above" the food when it is moving too fast
	if(foodVector.getLength() - Carnivore::getRadius() < intendedVelocity.getLength())
	{
		intendedVelocity = direction * (foodVector.getLength() - Carnivore::getRadius());
		owner_->setVelocity(intendedVelocity);
		concreteOwner_->eatPray(pray);

	} else
		owner_->setVelocity(intendedVelocity);

}

Herbivore* CarnivoreHunting::smellPray()
{
	if(timeDuration_%40 != 0)
		return nullptr;

	constexpr double ALERTNESS_CORRECTION_FACTOR = 0.04;
	const double precisionOfSmell = owner_->getAlertness() * ALERTNESS_CORRECTION_FACTOR;

	constexpr double coordCorrectionFactor = 2.0;
	const double xRandCoord = coordCorrectionFactor * RandomGenerator::getInstance()->getSampleUniform();
	const double yRandCoord = coordCorrectionFactor * RandomGenerator::getInstance()->getSampleUniform();

	Herbivore* smelledOrganism = simulation_->getOrganismAt(Vector(xRandCoord, yRandCoord), precisionOfSmell);

	return smelledOrganism;
}
