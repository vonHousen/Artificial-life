
#ifndef ARTIFICIAL_LIFE_CARNIVOREACTION_H
#define ARTIFICIAL_LIFE_CARNIVOREACTION_H

#include "Action.h"

/**
 * Carnivore's (concrete) Action - Strategy Design Pattern
 */

class CarnivoreAction : public Action
{
public:

	/**
	 * A constructor.
	 * @param owner - Carnivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 */
	CarnivoreAction(Carnivore* const owner, Simulation* const simulation);

	virtual void act() = 0;									///< Universal for all Actions, executes particular Action.

protected:

	Carnivore* const concreteOwner_;						///< Carnivore "owning" this Action.

};


#endif //ARTIFICIAL_LIFE_CARNIVOREACTION_H
