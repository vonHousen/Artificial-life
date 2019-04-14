/*
 * Behaviour TODO
 */

#ifndef ARTIFICIAL_LIFE_BEHAVIOUR_H
#define ARTIFICIAL_LIFE_BEHAVIOUR_H

#include <memory>
#include "Simulation.h"


class Behaviour
{
public:
	void act(std::shared_ptr<Organism>, std::shared_ptr<Simulation>);
};


#endif //ARTIFICIAL_LIFE_BEHAVIOUR_H
