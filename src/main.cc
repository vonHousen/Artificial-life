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

	Vector 		posHerbi(0, 0), posCarni(0.3, 0);
	Herbivore*  herbi = new Herbivore(std::make_unique<Genotype>(), posHerbi, simulation.get());
	Carnivore*	carni = new Carnivore(std::make_unique<Genotype>(), posCarni, simulation.get());

	Window window(simulation, 560);
	window.show();

	simulation->addOrganism(herbi);
	simulation->addOrganism(carni);

	return app.exec();
}