/**
 * Herbivore's (concrete) Action - Strategy Design Pattern
 */

#include <include/ALife/HerbivoreAction.h>

HerbivoreAction::HerbivoreAction(Herbivore *const owner, Simulation *const simulation) :
	Action(owner, simulation),
	concreteOwner_(owner)
	{}