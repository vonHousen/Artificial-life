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
#include <cassert>

/***
 * Shared code for all tests for hunting. Performs actual action of hunting.
 * It assumes that there is only one carnivore and one herbivore on the beginning of the simulation.
 * @param dummySimulation - Simulation in which hunting takes place.
 * @param predator - pointer for Carnivore that hunts Carnivore.
 * @return pair<int,bool> - ( is Herbivore dead? , how many iterations lived Herbivore? )
 */
std::pair<int,bool> performHunting(Simulation& dummySimulation, Carnivore* predator)
{
	int iterationCounter = 0;
	bool isHerbiDead = false;

	for( ; iterationCounter<9999; ++iterationCounter)
	{
		dummySimulation.update();
		if(dummySimulation.getCarnivoreCount() < 1)
			break;

		else if (dummySimulation.getHerbivoreCount() < 1 and predator->getHunger() < 5.0)
		{
			isHerbiDead = true;
			break;
		}
	}

	return {iterationCounter, isHerbiDead};
}


/***
 * Easiest hunting: herbivore is completely blind and carnivore is located just nearby it's pray
 */
TEST (HuntingTestSuite, HuntingBlindPray)
{
	Vector 		posHerbi(0.4, 0.4), posCarni(0.5, 0.5);
	Simulation 	dummySimulation;

	Herbivore* 	herbiBlind = new Herbivore(std::make_unique<Genotype>(5,0,5,5,5), posHerbi, &dummySimulation);
	Carnivore*	carni = new Carnivore(std::make_unique<Genotype>(), posCarni, &dummySimulation);

	dummySimulation.addOrganism(herbiBlind);
	dummySimulation.addOrganism(carni);

	dummySimulation.update();
	EXPECT_EQ(dummySimulation.getHerbivoreCount(), 1);
	EXPECT_EQ(carni->getSuggestedAction(), LeadingDesire::EATING);

	std::pair<int,bool> results = performHunting(dummySimulation, carni);
	int iterationCounter = results.first;
	bool isHerbiDead = results.second;

	EXPECT_TRUE(isHerbiDead);
	ASSERT_LT(iterationCounter, 300);	// assert to be eaten in decent time

	dummySimulation.update();
	EXPECT_EQ(dummySimulation.getCarnivoreCount(), 1);
	EXPECT_EQ(carni->getSuggestedAction(), LeadingDesire::REPRODUCTION);
}

/***
 * Both herbivore and carnivore have great sight range, but carnivore is super-fast
 */
TEST (HuntingTestSuite, HuntingSlowerPray)
{
	Vector 		posHerbi(0.0, 0.0), posCarni(0.5, 0.5);
	Simulation 	dummySimulation;

	Herbivore* 	herbiSlow = new Herbivore(std::make_unique<Genotype>(5,9,5,0,5), posHerbi, &dummySimulation);
	Carnivore*	carniFast = new Carnivore(std::make_unique<Genotype>(5,9,5,9,5), posCarni, &dummySimulation);

	dummySimulation.addOrganism(herbiSlow);
	dummySimulation.addOrganism(carniFast);

	std::pair<int,bool> results = performHunting(dummySimulation, carniFast);
	int iterationCounter = results.first;
	bool isHerbiDead = results.second;

	EXPECT_TRUE(isHerbiDead);
	EXPECT_EQ(dummySimulation.getCarnivoreCount(), 1);
	ASSERT_LT(iterationCounter, 500);	// assert to be eaten in decent time
}

/***
 * Both herbivore and carnivore have great sight range, but carnivore is too slow to hunt anything
 */
TEST (HuntingTestSuite, HuntingFasterPray)
{
	Vector 		posHerbi(0.0, 0.0), posCarni(0.5, 0.5);
	Simulation 	dummySimulation;

	Herbivore* 	herbiFast = new Herbivore(std::make_unique<Genotype>(5,9,5,5,5), posHerbi, &dummySimulation);
	Carnivore*	carniSlow = new Carnivore(std::make_unique<Genotype>(5,9,5,1,5), posCarni, &dummySimulation);

	dummySimulation.addOrganism(herbiFast);
	dummySimulation.addOrganism(carniSlow);

	std::pair<int,bool> results = performHunting(dummySimulation, carniSlow);
	bool isHerbiDead = results.second;

	EXPECT_FALSE(isHerbiDead);
	EXPECT_EQ(dummySimulation.getHerbivoreCount(), 1);
}

/***
 * Pray is out of sight of Carnivore, but predator is expected to smell it anyway
 */
TEST (HuntingTestSuite, HuntingWithSmell)
{
	Vector 		posHerbi(-0.5, -0.5), posCarni(0.5, 0.5);
	Simulation 	dummySimulation;

	Herbivore* 	herbiBlind = new Herbivore(std::make_unique<Genotype>(5,0,5,5,5), posHerbi, &dummySimulation);
	Carnivore*	carniBlindButFast = new Carnivore(std::make_unique<Genotype>(5,0,5,9,5), posCarni, &dummySimulation);

	dummySimulation.addOrganism(herbiBlind);
	dummySimulation.addOrganism(carniBlindButFast);

	std::pair<int,bool> results = performHunting(dummySimulation, carniBlindButFast);
	int iterationCounter = results.first;
	bool isHerbiDead = results.second;

	EXPECT_TRUE(isHerbiDead);
	EXPECT_EQ(dummySimulation.getCarnivoreCount(), 1);
	ASSERT_LT(iterationCounter, 500);	// assert to be eaten in decent time
}
