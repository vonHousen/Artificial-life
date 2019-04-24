/*
 * Organism - abstract (super) class for both species
 */

#include "Organism.h"

Organism::Organism(std::unique_ptr<Genotype> genes, const Vector &position, Simulation* const simulation) :
	health_			(10.0),
	timeAlive_		(0),
	position_		(position),
	velocity_		(Vector()),
	acceleration_	(Vector()),

	genes_ 			(std::move(genes)),
	needs_			(std::make_unique<Needs>(this)),
	currentAction_ 	(nullptr),
	simulation_ 	(simulation)
{}


bool Organism::isAlive() const
{
	return health_ <= 0.0;
}

const Vector& Organism::getPosition() const
{
	return position_;
}

