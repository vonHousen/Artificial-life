
#ifndef ARTIFICIAL_LIFE_CARNIVOREHUNTING_H
#define ARTIFICIAL_LIFE_CARNIVOREHUNTING_H

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

};


#endif //ARTIFICIAL_LIFE_CARNIVOREHUNTING_H
