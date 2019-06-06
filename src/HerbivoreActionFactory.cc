/**
 * Factory Design Pattern for Herbivore's actions. It's a singleton
 */

#include <include/ALife/HerbivoreActionFactory.h>
#include <include/ALife/HerbivoreEating.h>

HerbivoreActionFactory& HerbivoreActionFactory::getInstance()
{
	static HerbivoreActionFactory instance;
	return instance;
}

std::unique_ptr<HerbivoreEating> HerbivoreActionFactory::produceEatingAction(Herbivore* const owner, Simulation* const simulation)
{
	return std::make_unique<HerbivoreEating>(owner, simulation);
}
