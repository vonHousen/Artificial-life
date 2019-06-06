
#ifndef ARTIFICIAL_LIFE_CARNIVORESLEEPING_H
#define ARTIFICIAL_LIFE_CARNIVORESLEEPING_H

class Vector;

#include "CarnivoreAction.h"

/**
 * Carnivore's (concrete) Action of sleeping.
 */

class CarnivoreSleeping : public CarnivoreAction
{
public:

	/**
	 * A constructor.
	 * @param owner - Carnivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 */
	CarnivoreSleeping(Carnivore* const owner, Simulation* const simulation);
	virtual ~CarnivoreSleeping() = default; 	///< Default virtual destructor.

	virtual void act();							///< Universal for all Actions, executes particular Action.

private:

	unsigned int timeDuration_;					///< Duration of time passed since action has started.

};

#endif //ARTIFICIAL_LIFE_CARNIVORESLEEPING_H
