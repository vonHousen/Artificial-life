/**
 * Concrete species of an organism (derives from it)
 */

#include "Herbivore.h"
#include "HerbivoreActionFactory.h"
#include "Simulation.h"
#include "Action.h"


Herbivore::Herbivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation) :
	Organism(std::move(genes), position, simulation)
{}

void Herbivore::updateAction() // TODO
{

}