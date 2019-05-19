
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
	 */
  	Organism(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation);

	virtual void updateAction() = 0;		///< after being notified, it uses ActionFactory to update currentAction_.
	virtual void update() = 0;				///< flow of the information upside down.

	/**
	 * With polymorphism one decides whether to eat grass or another Organism.
	 * @param position - position of food.
	 */
	virtual void eatIt(const Vector&) = 0;

	void setAcceleration(const Vector& acceleration);						///< Setter for private trait.
	void setVelocity(const Vector& velocity);								///< Setter for private trait.
	void setHealth(float health);											///< Setter for private trait.
	void setSimulation(Simulation* const simulation);						///< Setter for private trait.

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

protected:

	float 	health_;								///< basic trait of the Organism, value in range of [0.0, 10.0].
	unsigned int 	timeAlive_;						///< basic trait of the Organism, value of [0.0, inf].
	Vector 	position_;								///< basic state of the Organism represented by Vector.
	Vector 	velocity_;								///< basic state of the Organism represented by Vector.
	Vector 	acceleration_;							///< basic state of the Organism represented by Vector.
	static double radius_;							///< basic trait of the Organism, static value for every Organism.

	std::unique_ptr<Genotype> 		genes_;			///< represents individual Organism's traits inherited from parents.
	std::unique_ptr<Needs> 			needs_;			///< represents all Organism's physical and psychological Needs.
	std::unique_ptr<Action> 		currentAction_;	///< current Action Organism can perform driven by Needs.

	Simulation*						simulation_;	///< Simulation that Organism takes part in.
	LeadingDesire suggestedAction_;					///< LeadingDesire interpreted as suggested Action.

};


#endif //ARTIFICIAL_LIFE_ORGANISM_H
