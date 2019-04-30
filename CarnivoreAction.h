/*
 * Carnivore (concrete) action - Strategy Design Pattern
 */

#ifndef ARTIFICIAL_LIFE_CARNIVOREACTION_H
#define ARTIFICIAL_LIFE_CARNIVOREACTION_H

#include "Action.h"

class Carnivore;


class CarnivoreAction : public Action
{
public:
	CarnivoreAction(Carnivore* const owner, Simulation* const simulation);

	virtual void act() = 0;


};


#endif //ARTIFICIAL_LIFE_CARNIVOREACTION_H
