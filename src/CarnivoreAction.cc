/**
 * Carnivore's (concrete) action - Strategy Design Pattern
 */

#include <include/ALife/CarnivoreAction.h>

CarnivoreAction::CarnivoreAction(Carnivore* const owner, Simulation* const simulation) :
	Action(owner, simulation),
	concreteOwner_(owner)
{}
