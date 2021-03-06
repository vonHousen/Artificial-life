/**
 * File aggregating tests from HuntingTestSuite
 */

#include <include/ALife/Simulation.h>
#include <include/ALife/Genotype.h>
#include <include/ALife/Herbivore.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Vector.h>
#include <include/googletest/include/gtest/gtest.h>
#include <iostream>

/***
 * Shared code for all tests for hunting. Performs actual action of hunting.
 * It assumes that there is only one carnivore and one herbivore on the beginning of the simulation.
 * @param dummySimulation - Simulation in which hunting takes place.
 * @param predator - pointer for Carnivore that hunts Carnivore.
 * @return pair<int,bool> - ( how many iterations Herbivore lived?, is Herbivore killed? )
 */
std::pair<int,bool> performHunting(Simulation& dummySimulation, Carnivore* predator)
{
	int iterationCounter = 0;
	bool isHerbiKilled = false;

	for( ; iterationCounter<9999; ++iterationCounter)
	{
		dummySimulation.update();
		if(dummySimulation.getCarnivoreCount() < 1)
			break;

		else if (dummySimulation.getHerbivoreCount() < 1 and predator->getHunger() < 5.5)
		{
			isHerbiKilled = true;
			break;
		}
	}

	return {iterationCounter, isHerbiKilled};
}


/***
 * Easiest hunting: herbivore is completely blind and carnivore is located just nearby it's pray
 */
TEST (HuntingTestSuite, HuntingBlindPray)
{
	const Vector posHerbi(0.4, 0.4), posCarni(0.5, 0.5);
	Simulation 	dummySimulation;

	Herbivore* 	herbiBlind = new Herbivore(std::make_unique<Genotype>(5,0,5,5,5), posHerbi, &dummySimulation);
	Carnivore*	carni = new Carnivore(std::make_unique<Genotype>(5,5,5,5,5), posCarni, &dummySimulation);

	dummySimulation.addOrganism(herbiBlind);
	dummySimulation.addOrganism(carni);

	dummySimulation.update();
	EXPECT_EQ(dummySimulation.getHerbivoreCount(), 1);
	EXPECT_EQ(carni->getSuggestedAction(), LeadingDesire::EATING);

	const std::pair<int,bool> results = performHunting(dummySimulation, carni);
	const int iterationCounter = results.first;
	const bool isHerbiKilled = results.second;

	EXPECT_TRUE(isHerbiKilled);
	ASSERT_LT(iterationCounter, 300);	// assert to be eaten in decent time

	EXPECT_EQ(dummySimulation.getCarnivoreCount(), 1);
	EXPECT_EQ(carni->getSuggestedAction(), LeadingDesire::REPRODUCTION);
}

/***
 * Both herbivore and carnivore have great sight range, but carnivore is super-fast
 */
TEST (HuntingTestSuite, HuntingSlowerPray)
{
	const Vector posHerbi(0.3, 0.3), posCarni(0.5, 0.5);
	Simulation 	dummySimulation;

	Herbivore* 	herbiSlow = new Herbivore(std::make_unique<Genotype>(5,9,5,0,5), posHerbi, &dummySimulation);
	Carnivore*	carniFast = new Carnivore(std::make_unique<Genotype>(5,9,5,9,5), posCarni, &dummySimulation);

	dummySimulation.addOrganism(herbiSlow);
	dummySimulation.addOrganism(carniFast);

	const std::pair<int,bool> results = performHunting(dummySimulation, carniFast);
	const int iterationCounter = results.first;
	const bool isHerbiKilled = results.second;

	EXPECT_TRUE(isHerbiKilled);
	EXPECT_EQ(dummySimulation.getCarnivoreCount(), 1);
	ASSERT_LT(iterationCounter, 500);	// assert to be eaten in decent time
}

/***
 * Both herbivore and carnivore have great sight range, but carnivore is too slow to hunt anything
 */
TEST (HuntingTestSuite, HuntingFasterPray)
{
	const Vector posHerbi(0.0, 0.0), posCarni(0.5, 0.5);
	Simulation 	dummySimulation;

	Herbivore* 	herbiFast = new Herbivore(std::make_unique<Genotype>(5,9,9,5,9), posHerbi, &dummySimulation);
	Carnivore*	carniSlow = new Carnivore(std::make_unique<Genotype>(5,9,3,1,5), posCarni, &dummySimulation);

	dummySimulation.addOrganism(herbiFast);
	dummySimulation.addOrganism(carniSlow);

	const std::pair<int,bool> results = performHunting(dummySimulation, carniSlow);
	const bool isHerbiKilled = results.second;

	EXPECT_FALSE(isHerbiKilled);
	EXPECT_EQ(dummySimulation.getHerbivoreCount(), 1);
}

/***
 * Pray is out of sight of Carnivore, but predator is expected to smell it anyway
 */
TEST (HuntingTestSuite, HuntingWithSmell)
{
	Vector 		posHerbi(-0.5, -0.5), posCarni(0.5, 0.5);
	Simulation 	dummySimulation;

	Herbivore* 	herbiBlind = new Herbivore(std::make_unique<Genotype>(5,0,5,0,5), posHerbi, &dummySimulation);
	Carnivore*	carniBlindButFast = new Carnivore(std::make_unique<Genotype>(9,1,5,9,5), posCarni, &dummySimulation);

	dummySimulation.addOrganism(herbiBlind);
	dummySimulation.addOrganism(carniBlindButFast);

	const std::pair<int,bool> results = performHunting(dummySimulation, carniBlindButFast);
	const int iterationCounter = results.first;
	const bool isHerbiKilled = results.second;

	EXPECT_TRUE(isHerbiKilled);
	EXPECT_EQ(dummySimulation.getCarnivoreCount(), 1);
	ASSERT_LT(iterationCounter, 3000);	// assert to be eaten in decent time
}

/***
 * Expected eating grass by Herbivore.
 */
TEST (HuntingTestSuite, GrassEating)
{
	Vector 		posHerbi(0.0, 0.0);
	Simulation 	dummySimulation;

	Herbivore* 	herbi = new Herbivore(std::make_unique<Genotype>(), posHerbi, &dummySimulation);

	dummySimulation.addOrganism(herbi);

	int iterationCounter = 0;
	bool isHerbiFull = false;

	for( ; iterationCounter<9999; ++iterationCounter)
	{
		dummySimulation.update();
		if(dummySimulation.getHerbivoreCount() < 1)
			break;

		else if (herbi->getSuggestedAction() != LeadingDesire::EATING)
		{
			isHerbiFull = true;
			break;
		}
	}

	EXPECT_TRUE(isHerbiFull);
	ASSERT_LT(iterationCounter, 3000);	// assert to finish in decent time
}

