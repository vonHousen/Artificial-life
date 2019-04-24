/*
 * Action - abstract class for all types of actions organism can perform driven by needs
 */

#ifndef ARTIFICIAL_LIFE_ACTION_H
#define ARTIFICIAL_LIFE_ACTION_H

#include "Simulation.h"

class Action
{
public:
	Action(Organism* const owner, Simulation* const simulation);

	virtual void act() = 0;

protected:
	Organism* const owner_;
	Simulation* const simulation_;
};


#endif //ARTIFICIAL_LIFE_ACTION_H
