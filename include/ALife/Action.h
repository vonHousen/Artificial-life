
#ifndef ARTIFICIAL_LIFE_ACTION_H
#define ARTIFICIAL_LIFE_ACTION_H

class Organism;
class Simulation;
class Carnivore;
class Herbivore;

/**
 * Abstract class for all types of Actions Organism can perform driven by Needs.
 */

class Action
{
public:
	/**
	 * A constructor.
	 *
	 * @param owner - Organism "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 */
	Action(Organism* const owner, Simulation* const simulation);

	/**
	 * A constructor.
	 *
	 * @param owner - Carnivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 */
	Action(Carnivore* const owner, Simulation* const simulation);

	/**
	 * A constructor.
	 *
	 * @param owner - Herbivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 */
	Action(Herbivore* const owner, Simulation* const simulation);

	virtual ~Action() = default; ///< Default virtual destructor.

	virtual void act() = 0;									///< Universal for all Actions, executes particular Action.

protected:
	Organism* const owner_;									///< Organism "owning" this Action.
	Simulation* const simulation_;							///< Simulation that Action makes an impact on.
};


#endif //ARTIFICIAL_LIFE_ACTION_H
