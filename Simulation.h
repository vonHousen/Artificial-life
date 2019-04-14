/*
 * Main class for simulation
 */

#ifndef ARTIFICIAL_LIFE_SIMULATION_H
#define ARTIFICIAL_LIFE_SIMULATION_H

#include <vector>
#include <memory>

#include "Map.h"

class Organism;

class Simulation
{
private:
	void update(float dt);				//NOTE (KP): not so sure about that dt argument, but it probably be needed

private:
	std::vector<std::shared_ptr<Organism>> organisms_;
	Map map_;
};


#endif //ARTIFICIAL_LIFE_SIMULATION_H
