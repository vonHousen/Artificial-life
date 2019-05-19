/**
 * Concrete species of an organism (derives from it)
 */

#include "Herbivore.h"
#include "HerbivoreActionFactory.h"
#include "Simulation.h"
#include "Action.h"


Herbivore::Herbivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation) :
	Organism(std::move(genes), position, simulation)
{}

void Herbivore::update() // TODO
{
	needs_->update();
	if(currentAction_)
		currentAction_->act();

	// Move
	// deltaS = v*dt + 1/2*a*dt^2
	// deltaV = a*dt
	// where dt = 1
	position_ += velocity_ + acceleration_*0.5; 
	velocity_ += acceleration_;
}

void Herbivore::updateAction() // TODO
{

}

void Herbivore::eatIt(const Vector &) // TODO
{

}

