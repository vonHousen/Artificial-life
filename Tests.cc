//
// Created by Kamil Zych on 23.04.2019.
//

#include "Tests.h"
#include "Organism.h"

void Tests::constructSingleOrganism()
{
	Vector dummyPosition(0.0, 0.0);
	std::shared_ptr<Genotype> dummyGenes = std::make_shared<Genotype>(Genotype());
	std::weak_ptr<Simulation> dummySimulation = std::make_shared<Simulation>(Simulation());

	Organism dummyOrganism(dummyGenes, dummyPosition, dummySimulation);
}