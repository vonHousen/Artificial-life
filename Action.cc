/*
 * Action TODO
 */

#include "Action.h"

Action::Action(std::shared_ptr<Organism> owner, std::shared_ptr<Simulation> simulation) : 	owner_(owner),
																							simulation_(simulation)
{}
