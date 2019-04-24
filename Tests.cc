/*
 * Tests - simple class for aggregation all tests
 */

#include "Tests.h"
#include "Organism.h"
#include "Herbivore.h"

void Tests::constructSingleOrganism()
{
	Vector dummyPosition(0.0, 0.0);

	Simulation dummySimulation;

	Organism dummyOrganism(std::make_unique<Genotype>(), dummyPosition, &dummySimulation);
}