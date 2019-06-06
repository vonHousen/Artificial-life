#ifndef ARTIFICIAL_LIFE_HERBIVOREPARENTING_H
#define ARTIFICIAL_LIFE_HERBIVOREPARENTING_H

#include "HerbivoreAction.h"

/**
 * Herbivore's (concrete) Action - parenting
 */

class HerbivoreParenting : public HerbivoreAction
{
public:
/**
	 * A constructor.
	 * @param owner - Herbivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
     * @param partner - Herbivore with which reproduction took place
	 */
	HerbivoreParenting(Herbivore *const owner, Simulation *const simulation, Herbivore* partner);

	virtual ~HerbivoreParenting() = default; ///< Default virtual destructor

	virtual void act();										///< Universal for all Actions, executes particular Action.
private:
    Herbivore* partner_;
};

#endif //ARTIFICIAL_LIFE_HERBIVOREPARENTING_H