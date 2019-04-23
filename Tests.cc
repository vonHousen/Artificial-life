/*
 * Tests - simple class for aggregation all tests
 */

#include "Tests.h"
#include "Organism.h"
#include "Herbivore.h"

void Tests::constructSingleOrganism()
{
	Vector dummyPosition(0.0, 0.0);
	std::shared_ptr<Genotype> dummyGenes = std::make_shared<Genotype>();
	std::weak_ptr<Simulation> dummySimulation = std::make_shared<Simulation>();

	Herbivore dummyOrganism(dummyGenes, dummyPosition, dummySimulation);
}