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

	void update();										///< Flow of the information upside down.
	void addOrganism(Carnivore* const);					///< Adds concrete Organism (Carnivore) to Simulation.
	void addOrganism(Herbivore* const);					///< Adds concrete Organism (Herbivore) to Simulation.
	void addOrganismToQueue(Carnivore* const);
	void addOrganismToQueue(Herbivore* const);
	void registerView(SimulationView* const);			///< Registers Simulation in View layer.

	void reset(int carnivoreCount, int herbivoreCount);
	void initializeSimulation(int carnivoreCount, int herbivoreCount);

	int getCarnivoreCount() const;						///< Getter for count of alive Carnivores in Simulation.
	int getHerbivoreCount() const;						///< Getter for count of alive Herbivores in Simulation.


	/**
	 * Getter for pointer to nearest Herbivore edible for Carnivore.
	 * @param hungryCarnivore - Organism for which nearest location is calculated
	 * @param sightRange - Genotype value for sightRange, value in range [0.0; 10.0]
	 * @return Pointing nearest pray / null pointer if not found.
	 */
	Herbivore* getNearestPrey(Carnivore* hungryCarnivore, double sightRange) const;

	/**
	 * Getter for nearest Carnivore.
	 * @param herbi - Organism for which the nearest location is calculated.
	 * @param sightRange - Genotype value for sightRange, value in range [0.0; 10.0]
	 * @return nearest Carnivore pointer / nullptr if not found.
	 */
	Carnivore* getNearestPredator(Herbivore* herbi, double sightRange) const;

	/**
	 * Returns pointer to the nearest eatable grass, represented as a map tile
	 * @param herbi - Organism that is looking for the grass to eat
	 * @return
	 */
	MapTile* getNearestGrass(Herbivore* herbi);

	/**
	 * Getter for the nearest Cave for given herbi.
	 * @param herbi - Herbivore looking for the nearest Cave.
	 * @return std::pair<Vector, double> : position of Cave, radius of Cave.
	 */
	std::pair<Vector, double> getNearestCave(const Herbivore* herbi);

	/**
	 * Getter for Herbivore at given location.
	 * @param location - Vector pointing to location of an Organism.
	 * @param precision - radius defining precision for lookup. It has a default value.
	 * @return Organism at location / nullptr if not found.
	 */
	Herbivore* getHerbivoreAt(const Vector& location, double precision = 0.0001);

	/**
	 * Getter for Carnivore at given location.
	 * @param location - Vector pointing to location of an Organism.
	 * @param precision - radius defining precision for lookup. It has a default value.
	 * @return Organism at location / nullptr if not found.
	 */
	Carnivore* getCarnivoreAt(const Vector& location, double precision = 0.0001);

	/**
	 * Getter for the nearest Carnivore partner-to-be in sight range.
	 * @param lonelyCarnivore - Carnivore looking for partner to reproduce.
	 * @return Carnivore pointer for partner / nullptr if not found.
	 */
	Carnivore* getBestSeenPartner(const Carnivore* lonelyCarnivore);

	/**
	 * Getter for the nearest Herbivore partner-to-be in sight range.
	 * @param lonelyHerbivore - Herbivore looking for partner to reproduce.
	 * @return Herbivore pointer for partner / nullptr if not found.
	 */
	Herbivore* getBestSeenPartner(const Herbivore* lonelyHerbivore);

	/**
	 * Produces some number of children, depending on parents' fittness
	 * and adds them to the simulation.
	 * @param parentA - First parent
	 * @param parentA - Second parent
	 */
	void produceBabies(const Carnivore* parentA, const Carnivore* parentB);

	/**
	 * Produces some number of children, depending on parents' fittness
	 * and adds them to the simulation.
	 * @param parentA - First parent
	 * @param parentA - Second parent
	 */
	void produceBabies(const Herbivore* parentA, const Herbivore* parentB);

private:

	std::vector<Carnivore*> carnivores_;				///< Data structure for aggregation of Carnivores.
	std::vector<Herbivore*> herbivores_;				///< Data structure for aggregation of Herbivores.
	std::vector<Carnivore*> carnivoresToAdd_;			///< Data structure for aggregation of Carnivores.
	std::vector<Herbivore*> herbivoresToAdd_;			///< Data structure for aggregation of Herbivores.

	Map map_;											///< Map, that covers simulation's area.
	SimulationView* view_;								///< View layer of Simulation class.

};


#endif //ARTIFICIAL_LIFE_SIMULATION_H
