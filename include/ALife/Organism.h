
#ifndef ARTIFICIAL_LIFE_ORGANISM_H
#define ARTIFICIAL_LIFE_ORGANISM_H

class Simulation;
class StatisticsVisitor;

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
	 */
  	Organism(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation);

	virtual void accept(StatisticsVisitor& visitor) const = 0;

	virtual void updateAction() = 0;		///< after being notified, it uses ActionFactory to update currentAction_.

	void setAcceleration(const Vector& acceleration);						///< Setter for private trait.
	void setVelocity(const Vector& velocity);								///< Setter for private trait.
	void setHealth(float health);											///< Setter for private trait.
	void setSimulation(Simulation* const simulation);						///< Setter for private trait.

	void update();							///< updates organism's fields such as position; called by Simulation
	
	/**
	 * Decides if an Organism is alive (or dead).
	 * @return True/False.
	 */
	bool isAlive() const;

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


protected:

	float 	health_;							///< basic, actual trait of the Organism, value in range of [0.0, 10.0].
	unsigned int 	timeAlive_;					///< basic, actual trait of the Organism, value of [0.0, inf].
	Vector 	position_;							///< basic, actual state of the Organism represented by Vector.
	Vector 	velocity_;							///< basic, actual state of the Organism represented by Vector.
	Vector 	acceleration_;						///< basic, actual state of the Organism represented by Vector.
	static double radius_;						///< basic trait of the Organism, static value for every Organism.

	std::unique_ptr<Genotype> 	genes_;			///< represents individual Organism's traits inherited from parents.
	std::unique_ptr<Needs> 		needs_;			///< represents all Organism's physical and psychological Needs.
	std::unique_ptr<Action> 	currentAction_;	///< current Action Organism can perform driven by Needs.

	Simulation*	simulation_;					///< Simulation that Organism takes part in.
	LeadingDesire suggestedAction_;				///< LeadingDesire interpreted as suggested Action.

};


#endif //ARTIFICIAL_LIFE_ORGANISM_H
