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

	//std::cout << std::endl;
	//std::cout << "Herbi: " << herbi.getPosition() << std::endl;
	//std::cout << "Carni: " << carni.getPosition() << std::endl;

}

void Tests::checkVectors()
{
	Vector posHerbi(-0.25, -0.25), posCarni(0.75, 0.75);

	assert(posHerbi.getVectorTo(posCarni) == Vector(-1.0, -1.0));

	//std::cout << std::endl;
	//std::cout << "Herbi: " << posHerbi << std::endl;
	//std::cout << "Carni: " << posCarni << std::endl;
	//std::cout << "posHerbi.getVectorTo(posCarni): " << posHerbi.getVectorTo(posCarni) << std::endl;

}

void Tests::runAll()
{
	constructFirstOrganisms();
	checkVectors();
}
