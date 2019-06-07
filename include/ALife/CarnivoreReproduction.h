
#ifndef ARTIFICIAL_LIFE_CARNIVOREREPRODUCTION_H
#define ARTIFICIAL_LIFE_CARNIVOREREPRODUCTION_H

class Vector;

#include "CarnivoreAction.h"
#include <include/ALife/Vector.h>


/**
 * Carnivore's (concrete) Action of reproduction.
 */
class CarnivoreReproduction : public CarnivoreAction
{
public:

	/**
	 * A constructor.
	 * @param owner - Carnivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 */
	CarnivoreReproduction(Carnivore* const owner, Simulation* const simulation);

	virtual ~CarnivoreReproduction() = default; 		///< Default virtual destructor.

	virtual void act();								///< Universal for all Actions, executes particular Action.

private:
	unsigned int timeDuration_;						///< Duration of time passed since action has started.

	/**
	 * Method is a realisation of going for pointed Carnivore.
	 * @param partnerVector - Vector pointing from "owning" Carnivore to matched partner - Carnivore.
	 * @param matchedPartner - matched partner Carnivore to be followed by owner.
	 */
	void goForIt(const Vector& partnerVector, Carnivore* matchedPartner);

	unsigned int expectedBirthTime_;			///< Birth is predicted to happen after this time.
};

#endif //ARTIFICIAL_LIFE_CARNIVOREREPRODUCTION_H
