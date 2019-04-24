/*
 * Tests - simple class for aggregation all tests
 */

#include "Tests.h"
#include "Organism.h"
#include "Herbivore.h"
#include "Simulation.h"

void Tests::constructSingleOrganism()
{
	Vector 		dummyPosition;
	Simulation 	dummySimulation;
	Herbivore 	dummyOrganism(std::make_unique<Genotype>(), dummyPosition, &dummySimulation);

	dummySimulation.addOrganism(&dummyOrganism);
}