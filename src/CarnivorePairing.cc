/**
 * Carnivore's (concrete) Action of pairing.
 */

#include <include/ALife/CarnivorePairing.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Vector.h>
#include <include/ALife/RandomGenerator.h>

CarnivorePairing::CarnivorePairing(Carnivore* const owner, Simulation* const simulation) :
		CarnivoreAction(owner, simulation),
		timeDuration_(0)
{}

void CarnivorePairing::act()
{
	++timeDuration_;
}
