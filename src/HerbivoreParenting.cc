
#include "include/ALife/HerbivoreParenting.h"

HerbivoreParenting::HerbivoreParenting(Herbivore *const owner, Simulation *const simulation, Herbivore* partner):
    HerbivoreAction(owner, simulation),
    partner_(partner)
{}

void HerbivoreParenting::act()
{
    
}