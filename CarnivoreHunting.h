/*
 * Carnivore (concrete) Action - eating
 */

#ifndef ARTIFICIAL_LIFE_CARNIVOREHUNTING_H
#define ARTIFICIAL_LIFE_CARNIVOREHUNTING_H

#include "CarnivoreAction.h"


class CarnivoreHunting : public CarnivoreAction
{
public:
	CarnivoreHunting(Carnivore* const owner, Simulation* const simulation);

	virtual void act();

private:
	Carnivore* const concreteOwner_;

};


#endif //ARTIFICIAL_LIFE_CARNIVOREHUNTING_H
