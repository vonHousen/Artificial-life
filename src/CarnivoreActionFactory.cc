/**
 * Factory Design Pattern for Carnivore's actions. It's a singleton
 */

#include <include/ALife/CarnivoreActionFactory.h>
#include <include/ALife/CarnivoreHunting.h>

CarnivoreActionFactory& CarnivoreActionFactory::getInstance()
{
	static CarnivoreActionFactory instance;
	return instance;
}

CarnivoreHunting CarnivoreActionFactory::produceEatingAction(Carnivore* const owner, Simulation* const simulation)
{
	return {owner, simulation};
}
