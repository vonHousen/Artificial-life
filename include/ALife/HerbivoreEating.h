/*
 * Herbivore (concrete) Action - eating
 */

#ifndef ARTIFICIAL_LIFE_HERBIVOREEATING_H
#define ARTIFICIAL_LIFE_HERBIVOREEATING_H

#include "HerbivoreAction.h"


class HerbivoreEating : public HerbivoreAction
{
public:
	HerbivoreEating(Organism* const owner, Simulation* const simulation);

	virtual void act();
};


#endif //ARTIFICIAL_LIFE_HERBIVOREEATING_H
