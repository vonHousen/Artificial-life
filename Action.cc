/*
 * Action - abstract class for all types of actions organism can perform driven by needs
 */

#include "Action.h"

Action::Action(Organism* const owner, Simulation* const simulation) :
	owner_		(owner),
	simulation_	(simulation)
{}
