/**
 * Herbivore's (concrete) Action - Strategy Design Pattern
 */

#include "HerbivoreAction.h"

HerbivoreAction::HerbivoreAction(Organism* const owner, Simulation* const simulation) :
	Action(owner, simulation) {}