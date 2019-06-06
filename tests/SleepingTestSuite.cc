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
 * @return pair<Vector,bool> - ( where Organism is sleeping?, has Organism slept at all? )
 */
std::pair<Vector,bool> performSleeping(Simulation& dummySimulation, Organism* sleepyOrganism)
{
	Vector positionOfSleeping;
	bool hasOrganismSlept = false;

	for( int iterationCounter = 0; iterationCounter<9999; ++iterationCounter)
	{
		dummySimulation.update();
		if(not sleepyOrganism->isAlive())
			return {positionOfSleeping, hasOrganismSlept};

		if (sleepyOrganism->getTiredness() <= 1)
		{
			hasOrganismSlept = true;
			positionOfSleeping = sleepyOrganism->getPosition();
			return {positionOfSleeping, hasOrganismSlept};
		}
	}

	return {positionOfSleeping, hasOrganismSlept};
}

/***
 * Carnivore is born on the "wrong side" of the map with born-desire : SLEEPING.
 * Expected movement to "the right side" and sleeping.
 */
TEST (SleepingTestSuite, CarnivoreSleeping)
{
	const Vector posCarni(0.5, 0.5);		// position on the right side of the map
	Simulation 	dummySimulation;
	Carnivore*	carni = new Carnivore(std::make_unique<Genotype>(), posCarni, &dummySimulation, LeadingDesire::SLEEPING);
	dummySimulation.addOrganism(carni);
	EXPECT_EQ(carni->getSuggestedAction(), LeadingDesire::SLEEPING);

	const std::pair<Vector,bool> results = performSleeping(dummySimulation, carni);
	const Vector positionOfSleeping = results.first;
	const bool hasOrganismSlept = results.second;

	EXPECT_TRUE(hasOrganismSlept);
	ASSERT_LT(positionOfSleeping.getX(), 0.0);
	ASSERT_EQ(carni->getSuggestedAction(), LeadingDesire::EATING);
}

/***
 * Herbivore is born with born-desire : SLEEPING.
 * Expected movement to the cave and sleeping.
 */
TEST (SleepingTestSuite, HerbivoreSleeping)
{
	const Vector posHerbi;
	const Vector expectedCavePosition(-0.6, -0.34);
	Simulation 	dummySimulation;
	Herbivore*	herbi = new Herbivore(std::make_unique<Genotype>(), posHerbi, &dummySimulation, LeadingDesire::SLEEPING);
	dummySimulation.addOrganism(herbi);
	EXPECT_EQ(herbi->getSuggestedAction(), LeadingDesire::SLEEPING);

	const std::pair<Vector,bool> results = performSleeping(dummySimulation, herbi);
	const Vector positionOfSleeping = results.first;
	const bool hasOrganismSlept = results.second;

	EXPECT_TRUE(hasOrganismSlept);

	const Vector vecToExpectedCave = Vector::getShortestVectorBetweenPositions(expectedCavePosition,positionOfSleeping);
	ASSERT_NEAR(vecToExpectedCave.getLength(), 0.0, Map::getCaveRadius());
	ASSERT_EQ(herbi->getSuggestedAction(), LeadingDesire::EATING);
}