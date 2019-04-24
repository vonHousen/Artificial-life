/*
 * Main class for simulation
 */

#include "Simulation.h"

void Simulation::addOrganism(Organism* const new_organism)
{
	organisms_.push_back(new_organism);
}
