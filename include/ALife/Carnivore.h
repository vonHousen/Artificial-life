
#ifndef ARTIFICIAL_LIFE_CARNIVORE_H
#define ARTIFICIAL_LIFE_CARNIVORE_H

class Simulation;

#include "Organism.h"


/**
 * Concrete species of an Organism (derives from it)
 */

class Carnivore : public Organism
{
public:

	Carnivore() = delete;					///< Deleted default constructor.
	Carnivore(const Organism&) = delete;	///< Deleted copying constructor.
	Carnivore(Organism&&) = delete;			///< Deleted moving constructor.
	virtual ~Carnivore() = default;			///< Default virtual destructor


	/**
	 * A constructor.
	 * @param genes - Genotype representing individual Organism's traits inherited from parents.
	 * @param position - Vector pointing to the position of the Organism on map.
	 * @param simulation - Simulation that Organism takes part in.
	 */
	Carnivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation);


	virtual void updateAction();			///< after being notified, it uses ActionFactory to update currentAction_.
	virtual void update();					///< flow of the information upside down.

	/**
	 * Carnivore eats an Organism of a position pointed by Vector.
	 * @param position - position of eaten Organism.
	 */
	virtual void eatIt(const Vector& position);

};


#endif //ARTIFICIAL_LIFE_CARNIVORE_H
