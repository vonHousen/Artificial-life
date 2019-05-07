/*
 * Herbivore - deriving from Organism
 */

#include "Herbivore.h"

Herbivore::Herbivore(std::unique_ptr<Genotype> genes, const Vector &position, Simulation* const simulation) :
	Organism(std::move(genes), position, simulation)
{}

void Herbivore::update()
{
	if(currentAction_)
		currentAction_->act();

	// Move
	velocity_ += acceleration_;
	position_ += velocity_;
}

void Herbivore::updateAction()
{
	//TODO
}

