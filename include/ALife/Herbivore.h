
#ifndef ARTIFICIAL_LIFE_HERBIVORE_H
#define ARTIFICIAL_LIFE_HERBIVORE_H

class Simulation;

#include "Organism.h"


/**
 * Concrete species of an Organism (derives from it)
 */

class Herbivore : public Organism
{
public:

	Herbivore() = delete;					///< Deleted default constructor.
	Herbivore(const Organism&) = delete;	///< Deleted copying constructor.
	Herbivore(Organism&&) = delete;			///< Deleted moving constructor.
	virtual ~Herbivore() = default;			///< Default virtual destructor


	/**
	 * A constructor.
	 * @param genes - Genotype representing individual Organism's traits inherited from parents.
	 * @param position - Vector pointing to the position of the Organism on map.
	 * @param simulation - Simulation that Organism takes part in.
	 */
	Herbivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation);

	virtual void updateAction();			///< after being notified, it uses ActionFactory to update currentAction_.

	/**
	 * Herbivore eats grass of a position pointed by Vector.
	 * @param position - position of eaten Organism.
	 */
	virtual void eatIt(const Vector&);

	/**
	 * Getter for individual for every Organism speed value, but tiredness is also taken into account.
	 * @param time passed after beginning of performed movement.
	 * @return individual speed value.
	 */
	virtual double getIndividualSpeedValueAfter(unsigned int time) const;

};


#endif //ARTIFICIAL_LIFE_HERBIVORE_H
