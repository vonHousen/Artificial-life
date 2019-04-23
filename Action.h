/*
 * Action TODO
 */

#ifndef ARTIFICIAL_LIFE_ACTION_H
#define ARTIFICIAL_LIFE_ACTION_H

#include <memory>
#include "Simulation.h"


class Action
{
public:
	Action(std::shared_ptr<Organism> owner,std::shared_ptr<Simulation> simulation);

	virtual void act() = 0;

protected:
	std::shared_ptr<Organism> owner_;
	std::shared_ptr<Simulation> simulation_;
};


#endif //ARTIFICIAL_LIFE_ACTION_H
