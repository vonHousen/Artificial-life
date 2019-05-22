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


Genotype::Genotype(float alertness, float sightRange, float stamina, float speed, float lifespan) :
	alertness_(alertness),
	sightRange_(sightRange),
	stamina_(stamina),
	speed_(speed),
	lifespan_(lifespan)
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

float Genotype::getAlertness() const
{
	return alertness_;
}

float Genotype::getSightRange() const
{
	return sightRange_;
}

float Genotype::getStamina() const
{
	return stamina_;
}

float Genotype::getSpeed() const
{
	return speed_;
}

float Genotype::getLifespan() const
{
	return	lifespan_;
}


