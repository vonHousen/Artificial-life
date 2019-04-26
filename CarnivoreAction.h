/*
 * Carnivore (concrete) action - Strategy Design Pattern
 */

#ifndef ARTIFICIAL_LIFE_CARNIVOREACTION_H
#define ARTIFICIAL_LIFE_CARNIVOREACTION_H

#include "Action.h"


class CarnivoreAction : public Action
{
public:
	CarnivoreAction(Organism* const owner, Simulation* const simulation) :
		Action(owner, simulation) {}

};


#endif //ARTIFICIAL_LIFE_CARNIVOREACTION_H
