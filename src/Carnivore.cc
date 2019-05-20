/**
 * Concrete species of an organism (derives from it)
 */

#include "Carnivore.h"
#include "Herbivore.h"
#include "CarnivoreActionFactory.h"
#include "CarnivoreHunting.h"
#include "Simulation.h"

Carnivore::Carnivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation) :
		Organism(std::move(genes), position, simulation)
{
	this->updateAction();
}

void Carnivore::updateAction()
{
	suggestedAction_ = needs_->getLeadingDesire();

	// TODO check first if there are no other factors that may change suggestedAction

	switch(suggestedAction_)
	{
		case LeadingDesire::EATING:
			currentAction_ = std::make_unique<CarnivoreHunting>(
					CarnivoreActionFactory::getInstance().produceEatingAction(this, simulation_)
					);
			break;

		default:
			break;
	}
}

void Carnivore::eatPray(Herbivore* pray)
{
	if(pray)
	{
		pray->setHealth(0.0);
		this->needs_->decreaseHungerBy(5.0);
		this->needs_->increaseLonelinessBy(2.0);
	}

}
