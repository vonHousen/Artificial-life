/*
 * Herbivore - deriving from Organism
 */

#include "Herbivore.h"

Herbivore::Herbivore(std::shared_ptr<Genotype> genes, const Vector &position, std::weak_ptr<Simulation> simulation) :
	Organism(std::move(genes), position, std::move(simulation))
{}

HerbivoreActionFactory* Herbivore::factory_ = &HerbivoreActionFactory::getInstance();