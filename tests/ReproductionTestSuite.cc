/**
 * File aggregating tests from ReproductionTestSuite
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
 * Two Carnivores are far one from another
 * Expected movement to each other reproduction.
 */
TEST (ReproductionTestSuite, CarnivoreEasyPairing)
{
	const Vector posFirst(0.5, 0.5), posSecond(-0.5, -0.5);
	Simulation 	dummySimulation;
	Carnivore*	first = new Carnivore(std::make_unique<Genotype>(), posFirst, &dummySimulation, LeadingDesire::REPRODUCTION);
	Carnivore*	second = new Carnivore(std::make_unique<Genotype>(), posSecond, &dummySimulation, LeadingDesire::REPRODUCTION);
	dummySimulation.addOrganism(first);
	dummySimulation.addOrganism(second);

	EXPECT_EQ(first->getSuggestedAction(), LeadingDesire::REPRODUCTION);
	EXPECT_EQ(second->getSuggestedAction(), LeadingDesire::REPRODUCTION);
	EXPECT_FALSE(first->isParenting());
	EXPECT_FALSE(second->isParenting());
	const double beforePairingDistance = Vector::getShortestVectorBetweenPositions(first->getPosition(), second->getPosition()).getLength();

	const Vector positionOfFirst = first->getPosition();
	const Vector positionOfSecond = second->getPosition();
	const double afterPairingDistance = Vector::getShortestVectorBetweenPositions(positionOfFirst, positionOfSecond).getLength();

	ASSERT_GT(beforePairingDistance, afterPairingDistance);
	ASSERT_NEAR(afterPairingDistance, 2*Organism::getRadius(), 0.01);
	ASSERT_TRUE(first->isParenting());
	ASSERT_TRUE(second->isParenting());
}
