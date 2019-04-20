/*
 * Herbivore (concrete) Action - Strategy Design Pattern
 */

#ifndef ARTIFICIAL_LIFE_HERBIVOREACTION_H
#define ARTIFICIAL_LIFE_HERBIVOREACTION_H

#include "Action.h"


class HerbivoreAction : public Action
{
public:
	HerbivoreAction(std::shared_ptr<Organism> owner, std::shared_ptr<Simulation> simulation) :
		Action(owner,simulation) {}

};


#endif //ARTIFICIAL_LIFE_HERBIVOREACTION_H
