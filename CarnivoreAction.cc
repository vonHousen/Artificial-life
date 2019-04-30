/*
 * Carnivore (concrete) Action - Strategy Design Pattern
 */

#include "CarnivoreAction.h"

CarnivoreAction::CarnivoreAction(Carnivore* const owner, Simulation* const simulation) :
	Action(owner, simulation)
{}
