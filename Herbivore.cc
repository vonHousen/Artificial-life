/*
 * Herbivore - deriving from Organism
 */

#include "Herbivore.h"

Herbivore::Herbivore(std::shared_ptr<Genotype> genes, const Vector &position, std::weak_ptr<Simulation> simulation) :
	Organism(genes, position, simulation)
{}

void Herbivore::update()
{
	//TODO
}

void Herbivore::updateAction()
{
	//TODO
}

