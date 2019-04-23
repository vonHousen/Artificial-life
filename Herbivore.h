/*
 * Herbivore - deriving from Organism
 */

#ifndef ARTIFICIAL_LIFE_HERBIVORE_H
#define ARTIFICIAL_LIFE_HERBIVORE_H

#include "Organism.h"
#include "HerbivoreAction.h"


class Herbivore : public Organism
{
private:
	class HerbivoreActionFactory;
	static HerbivoreActionFactory 	actionFactory_;

	class HerbivoreActionFactory
	{

	};
};


#endif //ARTIFICIAL_LIFE_HERBIVORE_H
