#ifndef ARTIFICIAL_LIFE_CARNIVOREPARENTING_H
#define ARTIFICIAL_LIFE_CARNIVOREPARENTING_H

#include "CarnivoreAction.h"
#include <include/ALife/Vector.h>
#include <memory>

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

	virtual std::unique_ptr<CarnivoreParenting> getCopyForPartner();

	virtual void act();										///< Universal for all Actions, executes particular Action.
private:
	CarnivoreParenting(Carnivore *const owner, Simulation *const simulation, Carnivore* partner, const Vector& birthLocation);

    Carnivore* partner_;	///< Partner in reproduction
	Vector birthLocation_;  ///< Location in which children will be borned
};

#endif //ARTIFICIAL_LIFE_CARNIVOREPARENTING_H