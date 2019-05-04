/*
 * Herbivore - deriving from Organism
 */

#include "Herbivore.h"
#include "HerbivoreActionFactory.h"
#include "Simulation.h"
#include "Action.h"


Herbivore::Herbivore(std::unique_ptr<Genotype> genes, const Vector &position, Simulation* const simulation) :
	Organism(std::move(genes), position, simulation)
{}

void Herbivore::update()
{
	if(currentAction_)
		currentAction_->act();

	// TODO
}

void Herbivore::updateAction()
{
	// TODO
}

void Herbivore::eatIt(const Vector &)
{
	// TODO
}

