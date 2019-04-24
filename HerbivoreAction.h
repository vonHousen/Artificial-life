/*
 * Herbivore (concrete) Action - Strategy Design Pattern
 */

#ifndef ARTIFICIAL_LIFE_HERBIVOREACTION_H
#define ARTIFICIAL_LIFE_HERBIVOREACTION_H

#include "Action.h"


class HerbivoreAction : public Action
{
public:
	HerbivoreAction(Organism* const owner, Simulation* const simulation) :
		Action(owner, simulation) {}

};


#endif //ARTIFICIAL_LIFE_HERBIVOREACTION_H
