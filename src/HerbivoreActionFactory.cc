/**
 * Factory Design Pattern for Herbivore's actions. It's a singleton
 */

#include <include/ALife/HerbivoreActionFactory.h>
#include <include/ALife/HerbivoreEating.h>
#include <include/ALife/HerbivoreSleeping.h>
#include <include/ALife/HerbivoreReproduction.h>

HerbivoreActionFactory& HerbivoreActionFactory::getInstance()
{
	static HerbivoreActionFactory instance;
	return instance;
}

std::unique_ptr<HerbivoreEating> HerbivoreActionFactory::produceEatingAction(Herbivore* const owner, Simulation* const simulation)
{
	return std::make_unique<HerbivoreEating>(owner, simulation);
}

std::unique_ptr<HerbivoreSleeping> HerbivoreActionFactory::produceSleepingAction(Herbivore* const owner, Simulation* const simulation)
{
	return std::make_unique<HerbivoreSleeping>(owner, simulation);
}

std::unique_ptr<HerbivoreReproduction>
HerbivoreActionFactory::produceReproductionAction(Herbivore* const owner, Simulation* const simulation)
{
	return std::make_unique<HerbivoreReproduction>(owner, simulation);
}
