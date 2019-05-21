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


/**
 * Main class responsible for simulation.
 */

class Simulation
{
public:

	Simulation();										///< A default constructor.
	~Simulation();										///< A destructor.

	void update();										///< flow of the information upside down.
	void addOrganism(Carnivore* const);					///< adds concrete Organism (Carnivore) to Simulation.
	void addOrganism(Herbivore* const);					///< adds concrete Organism (Herbivore) to Simulation.
	void registerView(SimulationView* const);			///< registers Simulation in View layer.

	void reset(int carnivoreCount, int herbivoreCount);
	void initializeSimulation(int carnivoreCount, int herbivoreCount);

	int getCarnivoreCount() const;						///< Getter for count of alive Carnivores in Simulation.
	int getHerbivoreCount() const;						///< Getter for count of alive Herbivores in Simulation.

	/**
	 * Getter for location of nearest food edible for Herbivore.
	 * @param hungryHerbivore - Organism for which nearest location is calculated
	 * @return Vector pointing to location of nearest food / Vector of length zero if not found.
	 */
	Vector getNearestFoodLocation(Herbivore* hungryHerbivore) const;

	/**
	 * Getter for pointer to nearest Herbivore edible for Carnivore.
	 * @param hungryCarnivore - Organism for which nearest location is calculated
	 * @return Pointing nearest pray / null pointer if not found.
	 */
	Herbivore* getNearestPrey(Carnivore* hungryCarnivore) const;

	/**
	 * Getter for Organism at given location.
	 * @param location - Vector pointing to location of an Organism.
	 * @return Organism at location / nullptr if not found.
	 */
	Organism* getOrganismAt(const Vector&);

private:

	int carnivoreCount_;								///< count of alive Carnivores in Simulation.
	int herbivoreCount_;								///< count of alive Herbivores in Simulation.

	std::vector<Carnivore*> carnivores_;				///< data structure for aggregation of Carnivores.
	std::vector<Herbivore*> herbivores_;				///< data structure for aggregation of Herbivores.

	Map map_;											///< Map, that covers simulation's area. TODO
	SimulationView* view_;								///< View layer of Simulation class.

};


#endif //ARTIFICIAL_LIFE_SIMULATION_H
