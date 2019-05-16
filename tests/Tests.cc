/*
 * Tests - simple class for aggregation all tests
 */

#include "Simulation.h"
#include "Genotype.h"
#include "Herbivore.h"
#include "Carnivore.h"
#include "Vector.h"
#include "gtest/gtest.h"
#include <iostream>
#include <cassert>

TEST (BasicTestSuite, OrganismsConstruction)
{
	Vector 		posHerbi(-0.5, -0.5), posCarni(0.5, 0.5);
	Simulation 	dummySimulation;
	Herbivore* 	herbi = new Herbivore(std::make_unique<Genotype>(), posHerbi, &dummySimulation);
	Carnivore*	carni = new Carnivore(std::make_unique<Genotype>(), posCarni, &dummySimulation);

	dummySimulation.addOrganism(herbi);
	dummySimulation.addOrganism(carni);

	EXPECT_EQ(herbi->getPosition(), posHerbi);
	EXPECT_EQ(carni->getPosition(), posCarni);
}

TEST (BasicTestSuite, VectorBasicOperations)
{
	Vector posHerbi(-0.25, -0.25), posCarni(0.75, 0.75);
	EXPECT_EQ(getShortestVectorBetweenPositions(posHerbi, posCarni), Vector(-1.0, -1.0));

	Vector outOfRange(2,-3);
	EXPECT_EQ(outOfRange, Vector(0.0, -1.0));

	Vector experimental(0.5, -0.5);
	EXPECT_EQ((experimental + Vector(1,1)), Vector(-0.5, 0.5));

	experimental.setX(6);
	EXPECT_EQ(experimental, Vector(0.0, -0.5));

	experimental.setY(-5);
	EXPECT_EQ(experimental, Vector(0.0, -1.0));
	EXPECT_EQ(experimental.getLength(), 1.0);

	experimental += Vector(1,0);
	EXPECT_NEAR(experimental.getLength(), 1.41, 0.01);

	experimental = experimental + Vector(1.5,0);
	EXPECT_EQ(experimental, Vector(0.5, -1.0));

	experimental = Vector(0.5,0.5);
	experimental *= 2;

	EXPECT_EQ(experimental, Vector(1.0, 1.0));

	experimental *= 2;
	EXPECT_EQ(experimental, Vector(2.0, 2.0));	//in fact both vectors are: (0.0, 0.0)
}

TEST (ActionsTestSuite, Hunting)
{
	Vector 		posHerbi(-0.5, -0.5), posCarni(0.5, 0.5);
	Simulation 	dummySimulation;
	Herbivore* 	herbi = new Herbivore(std::make_unique<Genotype>(), posHerbi, &dummySimulation);
	Carnivore*	carni = new Carnivore(std::make_unique<Genotype>(), posCarni, &dummySimulation);

	dummySimulation.addOrganism(herbi);
	dummySimulation.addOrganism(carni);

	dummySimulation.update();
	ASSERT_TRUE(herbi->isAlive());

	dummySimulation.update();
	//EXPECT_FALSE((herbi->isAlive())); // TODO adjust test case for real velocity
}
