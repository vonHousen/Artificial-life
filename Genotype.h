/*
 * Genotype represents individual organism's traits inherited from parents
 */

#ifndef ARTIFICIAL_LIFE_GENOTYPE_H
#define ARTIFICIAL_LIFE_GENOTYPE_H


class Genotype
{
public:
	Genotype();
	Genotype(const Genotype& inheritedGenes);

	Genotype crossOver(const Genotype& other) const;
	Genotype& mutate();

private:
	float alertness_;
	float sightRange_;
	float stamina_;
	float speed_;
	float lifespan_;
};


#endif //ARTIFICIAL_LIFE_GENOTYPE_H
