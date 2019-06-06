
#ifndef ARTIFICIAL_LIFE_HERBIVORESLEEPING_H
#define ARTIFICIAL_LIFE_HERBIVORESLEEPING_H

#include <include/ALife/HerbivoreAction.h>
#include <include/ALife/Vector.h>


/**
 * Herbivore's (concrete) Action of sleeping.
 */
class HerbivoreSleeping : public HerbivoreAction
{
public:

	/**
	 * A constructor.
	 * @param owner - Herbivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 */
	HerbivoreSleeping(Herbivore *const owner, Simulation *const simulation);

	virtual ~HerbivoreSleeping() = default;    		///< Default virtual destructor.

	virtual void act();                            	///< Universal for all Actions, executes particular Action.

private:

	unsigned int timeDuration_;                    	///< Duration of time passed since action has started.
	unsigned int sleepingTime_;                    	///< Duration of sleeping time.
	Vector sleepingPosition_;                    	///< Location where Herbivore is going to sleep.
};

#endif //ARTIFICIAL_LIFE_HERBIVORESLEEPING_H
