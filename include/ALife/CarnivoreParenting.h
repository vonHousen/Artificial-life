#ifndef ARTIFICIAL_LIFE_CARNIVOREPARENTING_H
#define ARTIFICIAL_LIFE_CARNIVOREPARENTING_H

#include "CarnivoreAction.h"
#include <include/ALife/Vector.h>

/**
 * Carnivore's (concrete) Action - parenting
 */

class CarnivoreParenting : public CarnivoreAction
{
public:
/**
	 * A constructor.
	 * @param owner - Carnivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
     * @param partner - Carnivore with which reproduction took place
	 */
	CarnivoreParenting(Carnivore *const owner, Simulation *const simulation, Carnivore* partner);

	virtual ~CarnivoreParenting() = default; ///< Default virtual destructor

	virtual void act();										///< Universal for all Actions, executes particular Action.
private:
    Carnivore* partner_;
	Vector birthLocation_;
};

#endif //ARTIFICIAL_LIFE_CARNIVOREPARENTING_H