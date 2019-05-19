/**
 * Main class responsible for simulation
 */


#ifndef ARTIFICIAL_LIFE_SIMULATION_H
#define ARTIFICIAL_LIFE_SIMULATION_H

class SimulationView;
class Organism;
class Herbivore;
class Carnivore;
class Vector;

#include <vector>
#include <memory>
#include "Map.h"

class Simulation
{
public:
	Simulation();
	~Simulation();

	void update();
	void addOrganism(Carnivore* const);
	void addOrganism(Herbivore* const);
	void registerView(SimulationView* const);

	int getCarnivoreCount() const;
	int getHerbivoreCount() const;

	Vector getNearestFoodLocation(Herbivore*) const;
	Vector getVectorToNearestPrey(Carnivore*) const;
	Organism* getOrganismAt(const Vector&);

private:
	int carnivoreCount_;
	int herbivoreCount_;

	std::vector<Carnivore*> carnivores_;
	std::vector<Herbivore*> herbivores_;

	Map map_;
	SimulationView* view_;
};


#endif //ARTIFICIAL_LIFE_SIMULATION_H
