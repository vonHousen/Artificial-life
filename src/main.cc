/**
 * Main file designed for production code: initialises GUI
 */

#include <include/ALife/Simulation.h>
#include <include/ALife/Organism.h>
#include <include/ALife/Herbivore.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Window.h>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	std::shared_ptr<Simulation> simulation = std::make_shared<Simulation>();

	Window window(simulation, 640);
	window.show();

	simulation->initializeSimulation(0, 1);

	return app.exec();
}