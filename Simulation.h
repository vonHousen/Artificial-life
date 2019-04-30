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
#include "SimulationView.h"

class SimulationView;
class Organism;

class Simulation
{
public:
	Simulation();
	~Simulation();

	void update();
	void addOrganism(Organism* const);
	void registerView(SimulationView* const);

	Vector getNearestFoodLocation(Herbivore*) const;
	Vector getVectorToNearestPrey(Carnivore*) const;
	Organism* getOrganismAt(const Vector &);

private:
	std::vector<Organism*> organisms_;
	Map map_;
	SimulationView* view_;
};


#endif //ARTIFICIAL_LIFE_SIMULATION_H
