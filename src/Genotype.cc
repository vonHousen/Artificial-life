/**
 * Genotype represents individual organism's traits inherited from parents
 */

#include <include/ALife/Genotype.h>

double Genotype::basicSpeedValue_ = 0.0002;

Genotype::Genotype() :
	alertness_(5.0),
	sightRange_(5.0),
	stamina_(5.0),
	speed_(5.0),
	lifespan_(5.0)
{}

Genotype::Genotype(const Genotype& inheritedGenes) :
	alertness_(inheritedGenes.alertness_),
	sightRange_(inheritedGenes.sightRange_),
	stamina_(inheritedGenes.stamina_),
	speed_(inheritedGenes.speed_),
	lifespan_(inheritedGenes.lifespan_)
{}

double Genotype::getBasicSpeed() const
{
	return basicSpeedValue_ * speed_;
}

double Genotype::getTirednessFactor() const
{
	return stamina_ * 0.1;
}

