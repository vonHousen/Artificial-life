/**
 * Factory Design Pattern for Herbivore's actions. It's a singleton
 */

#include "HerbivoreActionFactory.h"

HerbivoreActionFactory& HerbivoreActionFactory::getInstance()
{
	static HerbivoreActionFactory instance;
	return instance;
}
