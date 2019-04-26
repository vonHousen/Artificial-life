/*
 * Carnivore - deriving from organism
 */

#include "Carnivore.h"

Carnivore::Carnivore(std::unique_ptr<Genotype> genes, const Vector &position, Simulation* const simulation) :
		Organism(std::move(genes), position, simulation)
{}

void Carnivore::update()
{
	currentAction_->act();

	// Move
	position_ += velocity_;
}

void Carnivore::updateAction()
{
	//TODO
}
