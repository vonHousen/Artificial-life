/**
 * Main file designed for production code: initialises GUI
 */

#include "Simulation.h"
#include "Organism.h"
#include "Herbivore.h"
#include "Carnivore.h"
#include "Window.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	std::shared_ptr<Simulation> simulation = std::make_shared<Simulation>();

	Vector 		posHerbi1(0, 0.9), posCarni1(0.5, 0.9);
	Vector 		posHerbi2(0, 0.7), posCarni2(0.4, 0.7);
	Vector 		posHerbi3(0, 0.5), posCarni3(0.3, 0.5);
	Vector 		posHerbi4(0, 0.3), posCarni4(0.2, 0.3);
	Vector 		posHerbi5(0, 0.0), posCarni5(0.1, 0.0);
	Vector 		evacuationVector(-1,0);
	Herbivore*  herbi1 = new Herbivore(std::make_unique<Genotype>(), posHerbi1, simulation.get());
	Herbivore*  herbi2 = new Herbivore(std::make_unique<Genotype>(), posHerbi2, simulation.get());
	Herbivore*  herbi3 = new Herbivore(std::make_unique<Genotype>(), posHerbi3, simulation.get());
	Herbivore*  herbi4 = new Herbivore(std::make_unique<Genotype>(), posHerbi4, simulation.get());
	Herbivore*  herbi5 = new Herbivore(std::make_unique<Genotype>(), posHerbi5, simulation.get());
	Carnivore*	carni1 = new Carnivore(std::make_unique<Genotype>(), posCarni1, simulation.get());
	Carnivore*	carni2 = new Carnivore(std::make_unique<Genotype>(), posCarni2, simulation.get());
	Carnivore*	carni3 = new Carnivore(std::make_unique<Genotype>(), posCarni3, simulation.get());
	Carnivore*	carni4 = new Carnivore(std::make_unique<Genotype>(), posCarni4, simulation.get());
	Carnivore*	carni5 = new Carnivore(std::make_unique<Genotype>(), posCarni5, simulation.get());

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