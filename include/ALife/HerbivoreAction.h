
#ifndef ARTIFICIAL_LIFE_HERBIVOREACTION_H
#define ARTIFICIAL_LIFE_HERBIVOREACTION_H

#include "Action.h"

/**
 * Herbivore's (concrete) Action - Strategy Design Pattern
 */

class HerbivoreAction : public Action
{
public:

	/**
	 * A constructor.
	 * @param owner - Herbivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 */
	HerbivoreAction(Herbivore *const owner, Simulation *const simulation);

	virtual ~HerbivoreAction() = default; ///< Default virtual destructor.

	virtual void act() = 0;									///< Universal for all Actions, executes particular Action.

protected:

	Herbivore* const concreteOwner_;						///< Herbivore "owning" this Action.

};


#endif //ARTIFICIAL_LIFE_HERBIVOREACTION_H
