
#ifndef ARTIFICIAL_LIFE_HERBIVORE_H
#define ARTIFICIAL_LIFE_HERBIVORE_H

class Simulation;
class MapTile;

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

	virtual void update();					///< flow of the information, called by Simulation

	/**
	 * A constructor.
	 * @param genes - Genotype representing individual Organism's traits inherited from parents.
	 * @param position - Vector pointing to the position of the Organism on map.
	 * @param simulation - Simulation that Organism takes part in.
	 * @param desire - First desire Herbivore is born with. Default value is LeadingDesire::EATING.
	 */
	Herbivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation, LeadingDesire desire = LeadingDesire::EATING);

	virtual void accept(StatisticsVisitor& visitor) const;
	
	/**
	 * Creates new Herbivore due to reproduction with supplied organism
	 * @param other - pointer to the partner in reproduction
	 * @return pointer to new Herbivore
	 */
	Herbivore* reproduceWith(const Herbivore* other) const;

	virtual void updateAction();			///< after being notified, it uses ActionFactory to update currentAction_.

	/**
	 * Herbivore eats grass in specified MapTile.
	 * @param grass - map tile with grass to be eaten.
	 */
	virtual void eatIt(MapTile* grass);

	/**
	 * Getter for individual for every Organism speed value, but tiredness is also taken into account.
	 * @param time passed after beginning of performed movement.
	 * @return individual speed value.
	 */
	virtual double getIndividualSpeedValueAfter(unsigned int time) const;

	/**
	 * Herbivore, when on Cave area, can hide in it.
	 */
	void hide();

	/**
	 * Herbivore, after coming out from Cave, is no longer hidden.
	 */
	void unhide();

	/**
	 * Defines if Herbivore is hidden in Cave.
	 * @return True / False.
	 */
	virtual bool isHidden();

private:

	/**
	 * Get away from the greatest danger.
	 * @param danger - pointer for the nearest Carnivore.
	 */
	void runAwayFrom(Carnivore* danger);

	bool isHidden_;							///< Defines if Herbivore is hidden in Cave.

};


#endif //ARTIFICIAL_LIFE_HERBIVORE_H
