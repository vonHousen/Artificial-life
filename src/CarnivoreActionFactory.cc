/**
 * Factory Design Pattern for Carnivore's actions. It's a singleton
 */

#include <include/ALife/CarnivoreActionFactory.h>
#include <include/ALife/CarnivoreHunting.h>
#include <include/ALife/CarnivoreSleeping.h>
#include <include/ALife/CarnivoreParenting.h>
#include <include/ALife/CarnivorePairing.h>

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

std::unique_ptr<CarnivoreParenting>
CarnivoreActionFactory::produceParentingAction(Carnivore* const owner, Simulation* const simulation, Carnivore* partner)
{
	return std::make_unique<CarnivoreParenting>(owner, simulation, partner);
}

std::unique_ptr<CarnivorePairing>
CarnivoreActionFactory::producePairingAction(Carnivore* const owner, Simulation* const simulation)
{
	return std::make_unique<CarnivorePairing>(owner, simulation);
}
