/**
 * Concrete species of an organism (derives from it)
 */

#include <include/ALife/Carnivore.h>
#include <include/ALife/Herbivore.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/CarnivoreActionFactory.h>
#include <include/ALife/CarnivoreHunting.h>
#include <include/ALife/CarnivoreSleeping.h>
#include <include/ALife/CarnivoreParenting.h>
#include <include/ALife/CarnivorePairing.h>
#include <include/ALife/Simulation.h>

Carnivore::Carnivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation, LeadingDesire desire) :
		Organism(std::move(genes), position, simulation, desire)
{
	this->updateAction();
}

Carnivore* Carnivore::reproduceWith(const Carnivore* other) const
{
	Genotype childGenotype = genes_->crossOver(*other->genes_).mutate();
	Vector childPosition = position_;

	return new Carnivore(std::make_unique<Genotype>(childGenotype), childPosition, simulation_);
}

void Carnivore::updateAction()
{
	if(this->isParenting())
		return;

	suggestedAction_ = needs_->getLeadingDesire();

	switch(suggestedAction_)
	{
		case LeadingDesire::EATING:
			currentAction_ = std::move(
					CarnivoreActionFactory::getInstance().produceEatingAction(this, simulation_));
			break;

		case LeadingDesire::REPRODUCTION:
			currentAction_ = std::move(
					CarnivoreActionFactory::getInstance().producePairingAction(this, simulation_));
			break;

		case LeadingDesire::SLEEPING:
			currentAction_ = std::move(
					CarnivoreActionFactory::getInstance().produceSleepingAction(this, simulation_));
			break;

		default:
			break;
	}
}

void Carnivore::eatPray(Herbivore* pray)
{
	if(pray)
	{
		pray->decreaseHealthByValue(10.0);
		needs_->decreaseHungerBy(5.0);
		needs_->increaseLonelinessBy(2.0);
		needs_->update();
	}

}

double Carnivore::getIndividualSpeedValueAfter(unsigned int time) const
{
	const double tirednessFactor = genes_->getTirednessFactor();
	const double basicSpeed = genes_->getBasicSpeed();

	const int intendedRunDuration = 1000 * tirednessFactor;
	constexpr double PSEUDO_NORMALIZATION_FACTOR = 0.000002;
	const double speedDeviation =
			static_cast<double>(intendedRunDuration - static_cast<int>(time)) * PSEUDO_NORMALIZATION_FACTOR;

	//if run takes too long, organism is tired, but is not stopping!
	if(speedDeviation < -0.5*speedDeviation)
		return 0.5* basicSpeed;
	else
		return speedDeviation + basicSpeed;
}

void Carnivore::update()
{
	this->newIteration();

	if(currentAction_)
		currentAction_->act();

	this->move();
	this->checkAge();
}

void Carnivore::pairWith(Carnivore* partner)
{
	isParenting_ = true;
	std::unique_ptr<CarnivoreParenting> action = std::move(CarnivoreActionFactory::getInstance().produceParentingAction(this, simulation_, partner));
	std::unique_ptr<CarnivoreParenting> actionForPartner = action->getCopyForPartner();
	currentAction_ = std::move(action);
	partner->acceptPairing(this, std::move(actionForPartner));
}

void Carnivore::acceptPairing(Carnivore* partner, std::unique_ptr<CarnivoreParenting> action)
{
	isParenting_ = true;
	currentAction_ = std::move(action);
}

