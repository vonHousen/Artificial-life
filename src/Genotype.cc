/**
 * Genotype represents individual organism's traits inherited from parents
 */

#include <include/ALife/Genotype.h>
#include <include/ALife/RandomGenerator.h>

double Genotype::basicSpeedValue_ = 0.0002;

Genotype::Genotype()
{
	alertness_ = getRandomTraitValue();
	sightRange_ = 10.0 - alertness_;

	stamina_ = getRandomTraitValue();
	speed_ = 10.0 - stamina_;

	//Disturb the balance a little by introducing random variation
	perturbTraitValue(alertness_);
	perturbTraitValue(sightRange_);
	perturbTraitValue(stamina_);
	perturbTraitValue(speed_);

	//Independent trait
	lifespan_ = getRandomTraitValue();
}


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


Genotype Genotype::crossOver(const Genotype& other) const
{
	float alertness = alertness_; 
	float sightRange =  sightRange_;
	float stamina = stamina_;
	float speed = speed_;

	float lifespan = 0.5*(lifespan_ + other.lifespan_);
		
	int inheritedPair = std::ceil(RandomGenerator::getInstance()->getSampleUniform() * 2.0);
	switch(inheritedPair)
	{
		case 1:
			alertness = other.alertness_;
			sightRange = other.sightRange_;
			break;
		case 2:
			stamina = other.stamina_;
			speed = other.speed_;
			break;
	}

	return Genotype(alertness, sightRange, stamina, speed, lifespan);
}

Genotype& Genotype::mutate()
{
	int affectedGene = std::ceil(RandomGenerator::getInstance()->getSampleUniform() * 5.0);
	switch(affectedGene)
	{
		case 1:
			perturbTraitValue(alertness_);
			break;
		case 2:
			perturbTraitValue(sightRange_);
			break;
		case 3:
			perturbTraitValue(stamina_);
			break;
		case 4:
			perturbTraitValue(speed_);
			break;
		case 5:
			perturbTraitValue(lifespan_);
			break;
	}
	return *this;
}

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

void Genotype::perturbTraitValue(float& trait)
{
	trait += RandomGenerator::getInstance()->getSampleNormal() * 0.5;
	trait = std::min(10.0f, std::max(0.0f, trait));
}
