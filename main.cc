/*
 * Main file, currently for testing
 */

#include "Window.h"
#include "Tests.h"

int main(int argc, char *argv[])
{
    Tests::runAll();

    QApplication app(argc, argv);

    std::shared_ptr<Simulation> simulation = std::make_shared<Simulation>();

    Vector 		posHerbi(0, 0), posCarni(0.1, 0.1);
	Herbivore*  herbi = new Herbivore(std::make_unique<Genotype>(), posHerbi, simulation.get());
	Carnivore*	carni = new Carnivore(std::make_unique<Genotype>(), posCarni, simulation.get());

    Window window(simulation, 720, 540);
    window.show();

	simulation->addOrganism(herbi);
	simulation->addOrganism(carni);

    return app.exec();
}