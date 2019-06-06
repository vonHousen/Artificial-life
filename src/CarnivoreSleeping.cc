/**
 * Carnivore's (concrete) Action - sleeping
 */

#include <include/ALife/CarnivoreSleeping.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Vector.h>
#include <include/ALife/RandomGenerator.h>

CarnivoreSleeping::CarnivoreSleeping(Carnivore* const owner, Simulation* const simulation) :
		CarnivoreAction(owner, simulation),
		timeDuration_(0)
{}

void CarnivoreSleeping::act() {}
