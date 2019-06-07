/**
 * Concrete species of an organism (derives from it)
 */

#include <include/ALife/Herbivore.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/HerbivoreActionFactory.h>
#include <include/ALife/HerbivoreEating.h>
#include <include/ALife/HerbivoreSleeping.h>
#include <include/ALife/HerbivoreReproduction.h>
#include <include/ALife/MapTile.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Action.h>


Herbivore::Herbivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation, LeadingDesire desire) :
	Organism(std::move(genes), position, simulation, desire)
{
	this->updateAction();
}

Herbivore* Herbivore::reproduceWith(const Herbivore* other) const
{
	Genotype childGenotype = genes_->crossOver(*other->genes_).mutate();
	Vector childPosition = position_;

	return new Herbivore(std::make_unique<Genotype>(childGenotype), childPosition, simulation_);
}

void Herbivore::updateAction()
{
	suggestedAction_ = needs_->getLeadingDesire();
	
	switch(suggestedAction_)
	{
		case LeadingDesire::EATING:
			currentAction_ = std::move(
					HerbivoreActionFactory::getInstance().produceEatingAction(this, simulation_));
			break;

		case LeadingDesire::REPRODUCTION:
			currentAction_ = std::move(
					HerbivoreActionFactory::getInstance().produceReproductionAction(this, simulation_));
			break;

		case LeadingDesire::SLEEPING:
			currentAction_ = std::move(
					HerbivoreActionFactory::getInstance().produceSleepingAction(this, simulation_));
			break;

		default:
			currentAction_ = nullptr;
			break;
	}

}

void Herbivore::eatIt(MapTile* grass)
{
	grass->decreaseGrassiness(0.1);
	grass->setEater(this);
	needs_->decreaseHungerBy(0.025);
}

double Herbivore::getIndividualSpeedValueAfter(unsigned int time) const
{
	return genes_->getBasicSpeed();
}

void Herbivore::runAwayFrom(Carnivore* danger)
{
	const auto velocity = this->getIndividualSpeedValueAfter(0);


	const auto direction = (this->getPosition() - danger->getPosition()).getUnitVector();
	const auto intendedVelocity = direction * velocity;

	this->setVelocity(intendedVelocity);
}

void Herbivore::update()
{
	this->newIteration();

	// determine the greatest danger
	Carnivore* danger = simulation_->getNearestPredator(this, this->getSightRange());

	// do actions only if not chased by predator
	if(danger)
	{
		this->runAwayFrom(danger);

	} else
	{
		if (currentAction_)
			currentAction_->act();
	}

	this->move();
	this->checkAge();
}