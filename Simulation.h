/*
 * Main class for simulation
 */


#ifndef ARTIFICIAL_LIFE_SIMULATION_H
#define ARTIFICIAL_LIFE_SIMULATION_H

#include <vector>
#include <memory>
#include "Map.h"
#include "Organism.h"
#include "Herbivore.h"
#include "Carnivore.h"



class Organism;

class Simulation
{
public:
	Simulation() = default;

	void update();
	void addOrganism(Organism* const);

	Vector getNearestFoodLocation(Herbivore*) const;
	Vector getNearestPreyVector(Organism* const) const;

private:
	std::vector<Organism*> organisms_;
	Map map_;
};


#endif //ARTIFICIAL_LIFE_SIMULATION_H
