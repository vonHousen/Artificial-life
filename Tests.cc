/*
 * Tests - simple class for aggregation all tests
 */

#include "Tests.h"
#include "Simulation.h"

void Tests::constructSingleOrganism()
{
	Vector 		posHerbi(-0.5, -0.5), posCarni(0.5, 0.5);
	Simulation 	dummySimulation;
	Herbivore 	herbi(std::make_unique<Genotype>(), posHerbi, &dummySimulation);
	Carnivore	carni(std::make_unique<Genotype>(), posCarni, &dummySimulation);

	dummySimulation.addOrganism(&herbi);
	dummySimulation.addOrganism(&carni);
}