/**
 * Factory Design Pattern for Carnivore's actions. It's a singleton
 */

#include <include/ALife/CarnivoreActionFactory.h>
#include <include/ALife/CarnivoreHunting.h>
#include <include/ALife/CarnivoreSleeping.h>
#include <include/ALife/CarnivoreReproduction.h>

CarnivoreActionFactory& CarnivoreActionFactory::getInstance()
{
	static CarnivoreActionFactory instance;
	return instance;
}

std::unique_ptr<CarnivoreHunting>
CarnivoreActionFactory::produceEatingAction(Carnivore* const owner, Simulation* const simulation)
{
	return std::make_unique<CarnivoreHunting>(owner, simulation);
}

std::unique_ptr<CarnivoreSleeping>
CarnivoreActionFactory::produceSleepingAction(Carnivore* const owner, Simulation* const simulation)
{
	return std::make_unique<CarnivoreSleeping>(owner, simulation);
}

std::unique_ptr<CarnivoreReproduction>
CarnivoreActionFactory::produceReproductionAction(Carnivore* const owner, Simulation* const simulation)
{
	return std::make_unique<CarnivoreReproduction>(owner, simulation);
}
