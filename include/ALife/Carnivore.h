
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

	virtual void update();					///< Flow of the information, called by Simulation


	/**
	 * A constructor.
	 * @param genes - Genotype representing individual Organism's traits inherited from parents.
	 * @param position - Vector pointing to the position of the Organism on map.
	 * @param simulation - Simulation that Organism takes part in.
	 * @param desire - First desire Carnivore is born with. Default value is LeadingDesire::EATING.
	 */
	Carnivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation, LeadingDesire desire = LeadingDesire::EATING);

	/**
	 * Creates new Carnivore due to reproduction with supplied organism
	 * @param other - pointer to the partner in reproduction
	 * @return pointer to new Carnivore
	 */
	Carnivore* reproduceWith(const Carnivore* other) const;

	virtual void updateAction();			///< After being notified, it uses ActionFactory to update currentAction_.

	/**
	 * Carnivore eats a Herbivore.
	 * @param pray - eaten Herbivore.
	 */
	void eatPray(Herbivore* pray);

	/**
	 * Getter for individual for every Organism speed value, but tiredness is also taken into account.
	 * @param time passed after beginning of performed movement.
	 * @return individual speed value.
	 */
	virtual double getIndividualSpeedValueAfter(unsigned int time) const;

	/**
	 * Defines if Organism is hidden.
	 * @return True / False.
	 */
	virtual bool isHidden();
};


#endif //ARTIFICIAL_LIFE_CARNIVORE_H
