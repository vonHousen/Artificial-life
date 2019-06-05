/**
 * Concrete species of an organism (derives from it)
 */

#include <include/ALife/Herbivore.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/HerbivoreActionFactory.h>
#include <include/ALife/HerbivoreEating.h>
#include <include/ALife/MapTile.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Action.h>


Herbivore::Herbivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation) :
	Organism(std::move(genes), position, simulation)
{
	this->updateAction();
}

void Herbivore::updateAction()
{
	suggestedAction_ = needs_->getLeadingDesire();

	switch(suggestedAction_)
	{
		case LeadingDesire::EATING:
			currentAction_ = std::make_unique<HerbivoreEating>(
					HerbivoreActionFactory::getInstance().produceEatingAction(this, simulation_));
			break;

		case LeadingDesire::REPRODUCTION:
			currentAction_ = nullptr;
			break;

		default:
			currentAction_ = nullptr;
			break;
	}

}

void Herbivore::eatIt(MapTile* grass) // TODO
{
	grass->decreaseGrassiness(1);
	grass->setBeingEaten(true);
	this->needs_->decreaseHungerBy(0.25);
}

double Herbivore::getIndividualSpeedValueAfter(unsigned int time) const
{
	return genes_->getBasicSpeed();		// TODO
}

void Herbivore::runAwayFrom(Carnivore* danger)
{
	if(not danger)
		return;

	auto velocity = this->getIndividualSpeedValueAfter(0);


	auto direction = (danger->getPosition() - this->getPosition()).getUnitVector();
	auto intendedVelocity = direction * velocity;

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