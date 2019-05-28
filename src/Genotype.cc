/**
 * Genotype represents individual organism's traits inherited from parents
 */

#include <include/ALife/Genotype.h>
#include <include/ALife/RandomGenerator.h>

double Genotype::basicSpeedValue_ = 0.0002;

Genotype::Genotype()
{
	alertness_ = getRandomTraitValue();
	sightRange_ = getRandomTraitValue();
	stamina_ = getRandomTraitValue();
	speed_ = getRandomTraitValue();
	lifespan_ = getRandomTraitValue();
}

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

float Genotype::getRandomTraitValue() const
{
	const float MEAN = 5.0;
	const float STD_DEVIATION = 1.0;

	float value = STD_DEVIATION * RandomGenerator::getInstance()->getSampleNormal() + MEAN;

	//keep the value in [0, 10] range
	return std::min(10.0f, std::max(0.0f, value));
}
