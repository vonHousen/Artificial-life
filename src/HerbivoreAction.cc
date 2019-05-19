/**
 * Herbivore's (concrete) Action - Strategy Design Pattern
 */

#include "HerbivoreAction.h"

HerbivoreAction::HerbivoreAction(Herbivore *const owner, Simulation *const simulation) :
	Action(owner, simulation),
	concreteOwner_(owner)
	{}