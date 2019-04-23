/*
 * Action - abstract class for all types of actions organism can perform driven by needs
 */

#include "Action.h"

Action::Action(std::weak_ptr<Organism> owner, std::weak_ptr<Simulation> simulation) : 	owner_(owner),
																						simulation_(simulation)
{}
