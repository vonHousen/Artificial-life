/**
 * Class for aggregating all tests
 */

#include <include/ALife/Simulation.h>
#include <include/ALife/Genotype.h>
#include <include/ALife/Herbivore.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Vector.h>
#include <include/googletest/include/gtest/gtest.h>
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
	ASSERT_EQ(herbi->getSuggestedAction(), LeadingDesire::EATING);
	ASSERT_EQ(carni->getSuggestedAction(), LeadingDesire::EATING);
}

TEST (BasicTestSuite, VectorBasicOperations)
{
	Vector posHerbi(-0.25, -0.25), posCarni(0.75, 0.75);
	EXPECT_EQ(Vector::getShortestVectorBetweenPositions(posHerbi, posCarni), Vector(-1.0, -1.0));

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
	EXPECT_EQ(dummySimulation.getHerbivoreCount(), 1);
	EXPECT_EQ(carni->getSuggestedAction(), LeadingDesire::EATING);


	int iterationCounter = 0;
	bool isEaten = false;
	for( ; iterationCounter<9999; ++iterationCounter)
	{
		dummySimulation.update();
		if (dummySimulation.getHerbivoreCount() < 1)
		{
			isEaten = true;
			break;
		}
	}

	EXPECT_TRUE(isEaten);
	ASSERT_LT(iterationCounter, 2100);	// assert to be eaten in decent time

	dummySimulation.update();
	EXPECT_EQ(carni->getSuggestedAction(), LeadingDesire::REPRODUCTION);
}

#include <include/ALife/Window.h>

int calibratingStamina(int argc, char* argv[])		// TODO make a test out of it
{
	QApplication app(argc, argv);

	std::shared_ptr<Simulation> simulation = std::make_shared<Simulation>();

	Vector 		posHerbi1(0, 0.9), posCarni1(0.5, 0.9);
	Vector 		posHerbi2(0, 0.7), posCarni2(0.4, 0.7);
	Vector 		posHerbi3(0, 0.5), posCarni3(0.3, 0.5);
	Vector 		posHerbi4(0, 0.3), posCarni4(0.2, 0.3);
	Vector 		posHerbi5(0, 0.0), posCarni5(0.1, 0.0);
	Vector 		evacuationVector(-1,0);
	Herbivore*  herbi1 = new Herbivore(std::make_unique<Genotype>(5.0, 5.0, 9.0, 5.0, 5.0), posHerbi1, simulation.get());
	Herbivore*  herbi2 = new Herbivore(std::make_unique<Genotype>(5.0, 5.0, 9.0, 5.0, 5.0), posHerbi2, simulation.get());
	Herbivore*  herbi3 = new Herbivore(std::make_unique<Genotype>(5.0, 5.0, 9.0, 5.0, 5.0), posHerbi3, simulation.get());
	Herbivore*  herbi4 = new Herbivore(std::make_unique<Genotype>(5.0, 5.0, 9.0, 5.0, 5.0), posHerbi4, simulation.get());
	Herbivore*  herbi5 = new Herbivore(std::make_unique<Genotype>(5.0, 5.0, 9.0, 5.0, 5.0), posHerbi5, simulation.get());
	Carnivore*	carni1 = new Carnivore(std::make_unique<Genotype>(5.0, 5.0, 9.0, 5.0, 5.0), posCarni1, simulation.get());
	Carnivore*	carni2 = new Carnivore(std::make_unique<Genotype>(5.0, 5.0, 9.0, 5.0, 5.0), posCarni2, simulation.get());
	Carnivore*	carni3 = new Carnivore(std::make_unique<Genotype>(5.0, 5.0, 9.0, 5.0, 5.0), posCarni3, simulation.get());
	Carnivore*	carni4 = new Carnivore(std::make_unique<Genotype>(5.0, 5.0, 9.0, 5.0, 5.0), posCarni4, simulation.get());
	Carnivore*	carni5 = new Carnivore(std::make_unique<Genotype>(5.0, 5.0, 9.0, 5.0, 5.0), posCarni5, simulation.get());

	Window window(simulation, 560);
	window.show();

	simulation->addOrganism(herbi1);
	simulation->addOrganism(herbi2);
	simulation->addOrganism(herbi3);
	simulation->addOrganism(herbi4);
	simulation->addOrganism(herbi5);
	simulation->addOrganism(carni1);
	simulation->addOrganism(carni2);
	simulation->addOrganism(carni3);
	simulation->addOrganism(carni4);
	simulation->addOrganism(carni5);

	herbi1->setVelocity( evacuationVector.getUnitVector() * herbi1->getIndividualSpeedValueAfter(0) );
	herbi2->setVelocity( evacuationVector.getUnitVector() * herbi2->getIndividualSpeedValueAfter(0) );
	herbi3->setVelocity( evacuationVector.getUnitVector() * herbi3->getIndividualSpeedValueAfter(0) );
	herbi4->setVelocity( evacuationVector.getUnitVector() * herbi4->getIndividualSpeedValueAfter(0) );
	herbi5->setVelocity( evacuationVector.getUnitVector() * herbi5->getIndividualSpeedValueAfter(0) );

	return app.exec();
}