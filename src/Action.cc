/**
 * Abstract class for all types of actions organism can perform driven by needs
 */

#include <include/ALife/Action.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Herbivore.h>

Action::Action(Organism* const owner, Simulation* const simulation) :
	owner_		(owner),
	simulation_	(simulation)
{}

Action::Action(Carnivore* const owner, Simulation* const simulation) :
	owner_		(owner),
	simulation_	(simulation)
{}

Action::Action(Herbivore* const owner, Simulation* const simulation) :
	owner_		(owner),
	simulation_	(simulation)
{}
