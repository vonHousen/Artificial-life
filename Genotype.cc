/*
 * Genotype represents individual organism's traits inherited from parents
 */

#include "Genotype.h"

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

