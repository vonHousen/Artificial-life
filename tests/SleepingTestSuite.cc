/**
 * File aggregating tests from SleepingTestSuite
 */

#include <include/ALife/Simulation.h>
#include <include/ALife/Genotype.h>
#include <include/ALife/Herbivore.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Vector.h>
#include <include/ALife/LeadingDesire.h>
#include <include/googletest/include/gtest/gtest.h>
#include <iostream>

/***
 * Shared code for all tests for hunting. Performs actual action of sleeping.
 * @param dummySimulation - Simulation in which hunting takes place.
 * @param sleepyOrganism - pointer for sleepy Organism.
 * @return pair<int,bool> - ( where Organism is sleeping?, has Organism slept at all? )
 */
std::pair<Vector,bool> performSleeping(Simulation& dummySimulation, Organism* sleepyOrganism)
{
	Vector positionOfSleeping;
	bool hasOrganismSlept = false;

	for( int iterationCounter = 0; iterationCounter<9999; ++iterationCounter)
	{
		dummySimulation.update();
		if (sleepyOrganism->getTiredness() <= 1)
		{
			hasOrganismSlept = true;
			positionOfSleeping = sleepyOrganism->getPosition();
			break;
		}
	}

	return {positionOfSleeping, hasOrganismSlept};
}

/***
 * Sleeping after eating: herbivore is at first eaten.
 * After easy hunt, carnivore should go for sleep.
 */
TEST (SleepingTestSuite, CarnivoreSleeping)
{
	Vector 		posCarni(0.5, 0.5);		// position on the right side of the map
	Simulation 	dummySimulation;
	Carnivore*	carni = new Carnivore(std::make_unique<Genotype>(), posCarni, &dummySimulation, LeadingDesire::SLEEPING);
	dummySimulation.addOrganism(carni);
	EXPECT_EQ(carni->getSuggestedAction(), LeadingDesire::SLEEPING);

	std::pair<Vector,bool> results = performSleeping(dummySimulation, carni);
	Vector positionOfSleeping = results.first;
	bool hasOrganismSlept = results.second;


	EXPECT_TRUE(hasOrganismSlept);
	EXPECT_LT(positionOfSleeping.getX(), 0.0);
}