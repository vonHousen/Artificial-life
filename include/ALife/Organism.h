
#ifndef ARTIFICIAL_LIFE_ORGANISM_H
#define ARTIFICIAL_LIFE_ORGANISM_H

class Simulation;

#include <memory>
#include "Action.h"
#include "Needs.h"
#include "Genotype.h"
#include "Vector.h"
#include "LeadingDesire.h"

/**
 * Abstract (base) class for both species
 */

class Organism
{
public:

	Organism() = delete;													///< Deleted default constructor.
	Organism(const Organism&) = delete;										///< Deleted copying constructor.
	Organism(Organism&&) = delete;											///< Deleted moving constructor.
	Organism& operator=(const Organism&) = delete;							///< Deleted assignment operator.
	Organism& operator=(Organism&&) = delete;								///< Deleted moving assignment operator.
	virtual ~Organism() = default;											///< Default virtual destructor


	/**
	 * A constructor.
	 * @param genes - Genotype representing individual Organism's traits inherited from parents.
	 * @param position - Vector pointing to the position of the Organism on map.
	 * @param simulation - Simulation that Organism takes part in.
	 * @param desire - First desire Organism is born with. Default value is LeadingDesire::EATING.
	 */
  	Organism(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation, LeadingDesire desire = LeadingDesire::EATING);

	virtual void updateAction() = 0;		///< After being notified, it uses ActionFactory to update currentAction_.
	virtual void update() = 0;				///< Flow of the information, called by Simulation

	void setAcceleration(const Vector& acceleration);						///< Setter for private trait.
	void setVelocity(const Vector& velocity);								///< Setter for private trait.
	void decreaseHealthByValue(float value);								///< Decreases health by given value.
	void setSimulation(Simulation* const simulation);						///< Setter for private trait.

	/**
	 * Decides if an Organism is alive (or dead).
	 * @return True/False.
	 */
	bool isAlive() const;

	/**
	 * Decides if an Organism is going to have a child after reproduction.
	 * @return True/False.
	 */
	bool isParenting() const;

	/**
	 * Getter for a position of an Organism.
	 * @return Vector pointing to the position of the Organism on map.
	 */
	const Vector& getPosition() const;

	float getHealth() const;				///< Getter for organism's trait
	unsigned int getTimeAlive() const;		///< Returns value indicating for how long the organism is alive
	float getAlertness() const;				///< Getter for organism's trait
	float getSightRange() const;			///< Getter for organism's trait
	float getStamina() const;				///< Getter for organism's trait
	float getSpeed() const;					///< Getter for organism's trait
	float getLifespan() const;				///< Getter for organism's trait
	float getHunger() const;				///< Getter for organism's trait
	float getTiredness() const;				///< Getter for organism's trait
	float getLoneliness() const;			///< Getter for organism's trait

	/**
	 * Static getter for a radius.
	 * @return Radius of a model representing an Organism.
	 */
	static double getRadius();


	/**
	 * Getter for a suggested Action equal to LeadingDesire.
	 * @return LeadingDesire interpreted as suggested Action.
	 */
	LeadingDesire getSuggestedAction() const;

	/**
	 * Getter for individual for every Organism speed value, but tiredness is also taken into account.
	 * @param time passed after beginning of performed movement.
	 * @return individual speed value.
	 */
	virtual double getIndividualSpeedValueAfter(unsigned int time) const = 0;

	/**
	 * Organism does not feel tired at all, although it is hungry after sleep.
	 */
	void sleepWell();

	/**
	 * Finalizes parenting action, fulfilling organism's needs
	 */
	void finishParenting();

protected:

	float 	health_;							///< Basic, actual trait of the Organism, value in range of [0.0, 10.0].
	unsigned long int 	timeAlive_;				///< Basic, actual trait of the Organism, value of [0.0, inf].
	Vector 	position_;							///< Basic, actual state of the Organism represented by Vector.
	Vector 	velocity_;							///< Basic, actual state of the Organism represented by Vector.
	Vector 	acceleration_;						///< Basic, actual state of the Organism represented by Vector.
	static double radius_;						///< Basic trait of the Organism, static value for every Organism.
	bool isParenting_;							///< Decides whether Organism is parenting.

	std::unique_ptr<Genotype> 	genes_;			///< Represents individual Organism's traits inherited from parents.
	std::unique_ptr<Needs> 		needs_;			///< Represents all Organism's physical and psychological Needs.
	std::unique_ptr<Action> 	currentAction_;	///< Current Action Organism can perform driven by Needs.

	Simulation*	simulation_;					///< Simulation that Organism takes part in.
	LeadingDesire suggestedAction_;				///< LeadingDesire interpreted as suggested Action.

	void move();								///< Organism moves.
	void newIteration();						///< Sequence of actions at the begging of new iteration.
	void checkAge();							///< Organism ages.

};


#endif //ARTIFICIAL_LIFE_ORGANISM_H
