/*
 * Main file, currently for testing
 *
 */

#include "Organism.h"

int main()
{
	Vector startPos(0.0, 0.0);
	auto testGen = std::shared_ptr<Genotype>(new Genotype());
	auto testSim = std::shared_ptr<Simulation>(new Simulation());

    Organism A(testGen, startPos, testSim);

    return 0;
}