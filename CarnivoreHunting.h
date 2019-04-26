/*
 * Carnivore (concrete) Action - eating
 */

#ifndef ARTIFICIAL_LIFE_CARNIVOREEATING_H
#define ARTIFICIAL_LIFE_CARNIVOREEATING_H

#include "CarnivoreAction.h"


class CarnivoreHunting : public CarnivoreAction
{
public:
	CarnivoreHunting(Organism* const owner, Simulation* const simulation);

	virtual void act();

};


#endif //ARTIFICIAL_LIFE_CARNIVOREEATING_H
