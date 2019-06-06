
#ifndef ARTIFICIAL_LIFE_CARNIVOREPAIRING_H
#define ARTIFICIAL_LIFE_CARNIVOREPAIRING_H

class Vector;

#include "CarnivoreAction.h"
#include <include/ALife/Vector.h>


/**
 * Carnivore's (concrete) Action of pairing.
 */
class CarnivorePairing : public CarnivoreAction
{
public:

	/**
	 * A constructor.
	 * @param owner - Carnivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 */
	CarnivorePairing(Carnivore* const owner, Simulation* const simulation);

	virtual ~CarnivorePairing() = default; 		///< Default virtual destructor.

	virtual void act();							///< Universal for all Actions, executes particular Action.

private:
	unsigned int timeDuration_;					///< Duration of time passed since action has started.
	unsigned int runDuration_;					///< Duration of time passed since running has started.
	Carnivore* smelledPartner_;					///< Carnivore theoretically out of plain sight, but targeted with smell

	/**
	 * Method is a realisation of going for pointed Carnivore.
	 * @param partnerVector - Vector pointing from "owning" Carnivore to matched partner - Carnivore.
	 * @param matchedPartner - matched partner Carnivore to be followed by owner.
	 */
	void goForIt(const Vector& partnerVector, Carnivore* matchedPartner);

	/**
	 * Carnivore may try to locate partner by smelling it
	 * @return pointer to Carnivore partner / nullptr if not found
	 */
	Carnivore* smellPartner();


};

#endif //ARTIFICIAL_LIFE_CARNIVOREPAIRING_H
