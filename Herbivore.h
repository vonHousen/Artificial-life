/*
 * Herbivore - deriving from Organism
 */

#ifndef ARTIFICIAL_LIFE_HERBIVORE_H
#define ARTIFICIAL_LIFE_HERBIVORE_H

#include "Organism.h"
#include "HerbivoreAction.h"

class HerbivoreActionFactory;


class Herbivore : public Organism
{
private:
	static HerbivoreActionFactory 	actionFactory_;

	class HerbivoreActionFactory
	{

	};
};


#endif //ARTIFICIAL_LIFE_HERBIVORE_H
