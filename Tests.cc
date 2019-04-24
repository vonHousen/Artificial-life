/*
 * Tests - simple class for aggregation all tests
 */

#include "Tests.h"
#include "Simulation.h"

void Tests::constructSingleOrganism()
{
	Vector 		dummyPosition;
	Simulation 	dummySimulation;
	Herbivore 	herbi(std::make_unique<Genotype>(), dummyPosition, &dummySimulation);
	Carnivore	carni(std::make_unique<Genotype>(), dummyPosition, &dummySimulation);

	dummySimulation.addOrganism(&herbi);
	dummySimulation.addOrganism(&carni);
}