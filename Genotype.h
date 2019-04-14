/*
 * Genotype TODO
 */

#ifndef ARTIFICIAL_LIFE_GENOTYPE_H
#define ARTIFICIAL_LIFE_GENOTYPE_H



class Genotype
{
public:
	Genotype crossOver(const Genotype& other) const;
	Genotype& mutate(); 					//NOTE (KP): make it const or not?

private:
	float alertness_;						//NOTE (KP): is this variable's name good enough?
	float sightRange_;
	float stamina_;
	float speed_;
	float lifespan_;
};


#endif //ARTIFICIAL_LIFE_GENOTYPE_H
