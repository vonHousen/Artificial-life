/*
 * Organism - abstract (super) class for both species
 */

#include "Organism.h"

Organism::Organism(std::shared_ptr<Genotype> genes, const Vector &position, std::weak_ptr<Simulation> simulation) :
	health_			(10.0),
	timeAlive_		(0),
	position_		(position),
	velocity_		(Vector()),
	acceleration_	(Vector()),

	genes_ 			(std::move(genes)),
	needs_			(std::shared_ptr<Needs>(nullptr)),
	currentAction_ 	(nullptr),

	simulation_ 	(std::move(simulation))
{
	std::weak_ptr<Organism> organismPtr = std::shared_ptr<Organism>(this);
	needs_ =		std::make_shared<Needs>(Needs(organismPtr));
}