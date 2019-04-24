/*
 * Carnivore - deriving from organism
 */

#include "Carnivore.h"

Carnivore::Carnivore(std::unique_ptr<Genotype> genes, const Vector &position, Simulation* const simulation) :
		Organism(std::move(genes), position, simulation)
{}

void Carnivore::update()
{
	//TODO
}

void Carnivore::updateAction()
{
	//TODO
}
