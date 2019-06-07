
#ifndef ARTIFICIAL_LIFE_HERBIVOREREPRODUCTION_H
#define ARTIFICIAL_LIFE_HERBIVOREREPRODUCTION_H

class Vector;

#include "HerbivoreAction.h"
#include <include/ALife/Vector.h>


/**
 * Herbivore's (concrete) Action of reproduction.
 */
class HerbivoreReproduction : public HerbivoreAction
{
public:

	/**
	 * A constructor.
	 * @param owner - Herbivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 */
	HerbivoreReproduction(Herbivore* const owner, Simulation* const simulation);

	virtual ~HerbivoreReproduction() = default; 		///< Default virtual destructor.

	virtual void act();							///< Universal for all Actions, executes particular Action.

private:
	unsigned int timeDuration_;					///< Duration of time passed since action has started.

	/**
	 * Method is a realisation of going for pointed Herbivore.
	 * @param partnerVector - Vector pointing from "owning" Herbivore to matched partner - Herbivore.
	 * @param matchedPartner - matched partner Herbivore to be followed by owner.
	 */
	void goForIt(const Vector& partnerVector, Herbivore* matchedPartner);


};

#endif //ARTIFICIAL_LIFE_HERBIVOREREPRODUCTION_H
