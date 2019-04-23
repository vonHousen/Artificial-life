/*
 * Action - abstract class for all types of actions organism can perform driven by needs
 */

#ifndef ARTIFICIAL_LIFE_ACTION_H
#define ARTIFICIAL_LIFE_ACTION_H

#include <memory>
#include "Simulation.h"


class Action
{
public:
	Action(std::weak_ptr<Organism> owner, std::weak_ptr<Simulation> simulation);

	virtual void act() = 0;

protected:
	std::weak_ptr<Organism> owner_;
	std::weak_ptr<Simulation> simulation_;
};


#endif //ARTIFICIAL_LIFE_ACTION_H
