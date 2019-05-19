/**
 * Herbivore's (concrete) Action - eating
 */

#include "HerbivoreEating.h"

HerbivoreEating::HerbivoreEating(Herbivore *const owner, Simulation *const simulation) :
	HerbivoreAction(owner, simulation)
{}

void HerbivoreEating::act() //TODO
{
	//Organism is hungry, it needs to find the nearest food
	//simulation_->getNearestFoodLoc(this);
}