
#ifndef ARTIFICIAL_LIFE_GENOTYPE_H
#define ARTIFICIAL_LIFE_GENOTYPE_H

/**
 * Genotype represents individual Organism's traits inherited from parents
 */

class Genotype
{
public:

	/**
	 * A default constructor.
	 */
	Genotype();

	/**
	 * A constructor.
	 * @param inheritedGenes - Genotype representing individual Organism's traits inherited from parents.
	 */
	Genotype(const Genotype& inheritedGenes);

	/**
	 * Function that creates a new Genotype object by mixing this object with provided genotype.
	 * @param other - Genotype object to be mixed with.
	 * @return resultant genotype.
	 */
	Genotype crossOver(const Genotype& other) const;
	
	/**
	 * Introduces random changes in traits' values, mimicking mutation.
	 * @return reference to mutated genotype
	 */
	Genotype& mutate();

	/**
	 * Getter for individual for every Organism, basic value of calculated speed based on Genotype.
	 * @return individual, basic value of speed (avg: 0.001).
	 */
	double getBasicSpeed() const;

	/**
	 * Getter for individual for every Organism tiredness factor based on Genotype.
	 * @return individual tiredness value (avg: 0.5)
	 */
	double getTirednessFactor() const;

	float getAlertness() const;				///< Getter for alertness trait
	float getSightRange() const;			///< Getter for sight range trait
	float getStamina() const;				///< Getter for stamina trait
	float getSpeed() const;					///< Getter for speed trait
	float getLifespan() const;				///< Getter for lifespan trait

private:

	Genotype(float alertness, float sightRange, float stamina, float speed, float lifespan);	///< Private constructor that copies trait values, used in crossing-over

	float getRandomTraitValue() const;
	void perturbTraitValue(float& trait);

	float alertness_;							///< Trait representing alertness, value in range [0.0; 10.0]
	float sightRange_;							///< Trait representing range of sight, value in range [0.0; 10.0]
	float stamina_;								///< Trait representing stamina, value in range [0.0; 10.0]
	float speed_;								///< Trait representing speed, value in range [0.0; 10.0]
	float lifespan_;							///< Trait representing lifespan, value in range [0.0; 10.0]

	static double basicSpeedValue_;		///< basic, static value for every Organism, used for calculating actual speed.


};


#endif //ARTIFICIAL_LIFE_GENOTYPE_H
