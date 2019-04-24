/*
 * Tests - simple class for aggregation all tests
 */

#include "Tests.h"
#include "Simulation.h"
#include <iostream>
#include <cassert>

void Tests::constructFirstOrganisms()
{
	Vector 		posHerbi(-0.5, -0.5), posCarni(0.5, 0.5);
	Simulation 	dummySimulation;
	Herbivore 	herbi(std::make_unique<Genotype>(), posHerbi, &dummySimulation);
	Carnivore	carni(std::make_unique<Genotype>(), posCarni, &dummySimulation);

	dummySimulation.addOrganism(&herbi);
	dummySimulation.addOrganism(&carni);

	assert(herbi.getPosition() == posHerbi);
	assert(carni.getPosition() == posCarni);

	std::cout << std::endl;
	std::cout << "Herbi: " << herbi.getPosition() << std::endl;
	std::cout << "Carni: " << carni.getPosition() << std::endl;

}