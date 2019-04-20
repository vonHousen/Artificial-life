/*
 * Carnivore (concrete) action - Strategy Design Pattern
 */

#ifndef ARTIFICIAL_LIFE_CARNIVOREACTION_H
#define ARTIFICIAL_LIFE_CARNIVOREACTION_H

#include "Action.h"


class CarnivoreAction : public Action
{
public:
	CarnivoreAction(std::shared_ptr<Organism> owner, std::shared_ptr<Simulation> simulation) :
		Action(owner,simulation) {}

};


#endif //ARTIFICIAL_LIFE_CARNIVOREACTION_H
