
#ifndef ARTIFICIAL_LIFE_HERBIVOREEATING_H
#define ARTIFICIAL_LIFE_HERBIVOREEATING_H

class MapTile;

#include "HerbivoreAction.h"

/**
 * Herbivore's (concrete) Action - eating
 */

class HerbivoreEating : public HerbivoreAction
{
public:

	/**
	 * A constructor.
	 * @param owner - Herbivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 */
	HerbivoreEating(Herbivore *const owner, Simulation *const simulation);

	~HerbivoreEating();

	virtual void act();										///< Universal for all Actions, executes particular Action.
private:
	MapTile* eatenTile_;
};


#endif //ARTIFICIAL_LIFE_HERBIVOREEATING_H
