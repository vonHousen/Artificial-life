
#ifndef ARTIFICIAL_LIFE_CARNIVOREHUNTING_H
#define ARTIFICIAL_LIFE_CARNIVOREHUNTING_H

class Vector;

#include "CarnivoreAction.h"

/**
 * Carnivore's (concrete) Action of eating (finding food) called hunting.
 */

class CarnivoreHunting : public CarnivoreAction
{
public:

	/**
	 * A constructor.
	 * @param owner - Carnivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 */
	CarnivoreHunting(Carnivore* const owner, Simulation* const simulation);

	virtual void act();										///< Universal for all Actions, executes particular Action.

private:

	unsigned int timeDuration_;								///< Duration of time passed since action has started.

	/**
	 * Method is a realisation of going for pointed Herbivore.
	 * @param foodVector - Vector pointing from "owning" Carnivore to tasty Herbivore.
	 */
	void goForIt(const Vector& foodVector);

};


#endif //ARTIFICIAL_LIFE_CARNIVOREHUNTING_H
