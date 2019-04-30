/*
 * CarnivoreActionFactory - Factory Design Pattern for Carnivore's actions. It's a singleton
 */

#include "CarnivoreActionFactory.h"

CarnivoreActionFactory& CarnivoreActionFactory::getInstance()
{
	static CarnivoreActionFactory instance;
	return instance;
}

CarnivoreActionFactory::CarnivoreActionFactory()
{
	//TODO
}

CarnivoreHunting CarnivoreActionFactory::produceEatingAction(Carnivore* const owner, Simulation* const simulation)
{
	return CarnivoreHunting(owner, simulation);
}
