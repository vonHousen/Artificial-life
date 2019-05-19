
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

	Genotype crossOver(const Genotype& other) const;	// TODO
	Genotype& mutate();									// TODO

private:

	float alertness_;							///< Trait representing alertness, value in range [0.0; 10.0]
	float sightRange_;							///< Trait representing range of sight, value in range [0.0; 10.0]
	float stamina_;								///< Trait representing stamina, value in range [0.0; 10.0]
	float speed_;								///< Trait representing speed, value in range [0.0; 10.0]
	float lifespan_;							///< Trait representing lifespan, value in range [0.0; 10.0]

};


#endif //ARTIFICIAL_LIFE_GENOTYPE_H
