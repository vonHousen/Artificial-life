
#ifndef ARTIFICIAL_LIFE_CARNIVOREHUNTING_H
#define ARTIFICIAL_LIFE_CARNIVOREHUNTING_H

class Vector;
class Herbivore;

#include "CarnivoreAction.h"

/**
 * Carnivore's (concrete) Action of eating (finding food) called hunting.
 */

class CarnivoreHunting : public CarnivoreAction
{
public:

	/**
	 * A constructor.
	 * @param owner - Carnivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 */
	CarnivoreHunting(Carnivore* const owner, Simulation* const simulation);

	virtual ~CarnivoreHunting() = default; ///< Default virtual destructor.

	virtual void act();							///< Universal for all Actions, executes particular Action.

private:

	unsigned int timeDuration_;					///< Duration of time passed since action has started.
	unsigned int runDuration_;					///< Duration of time passed since running has started.
	Herbivore* smelledPray_;					///< Herbivore theoretically out of plain sight, but targeted with smell

	/**
	 * Method is a realisation of going for pointed Herbivore.
	 * @param foodVector - Vector pointing from "owning" Carnivore to tasty Herbivore.
	 * @param pray - tasty Herbivore to be followed by Carnivore.
	 */
	void goForIt(const Vector& foodVector, Herbivore* pray);

	/**
	 * Predator may try to locate pray by smelling it
	 * @return pointer to Herbivore / nullptr if not found
	 */
	Herbivore* smellPray();

};


#endif //ARTIFICIAL_LIFE_CARNIVOREHUNTING_H
