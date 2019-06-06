#ifndef ARTIFICIAL_LIFE_MAP_H
#define ARTIFICIAL_LIFE_MAP_H

#include <vector>
#include <memory>

class MapTile;
class Vector;
class Herbivore;

/**
 * Map consisting of MapTiles, that covers simulation's area.
 */

class Map
{
public:
	Map(); ///< A constructor. Creates map tiles of appropriate type that fill the map area.

	void update(); ///< Updates all map tiles
	void reset(); ///< Resets all map tiles

	const std::vector<std::shared_ptr<MapTile>>& getTiles() const; ///< Returns reference to vector of MapTiles

	MapTile* getNearestMapTile(const Herbivore* herbi);  ///< Returns pointer to the nearest grassy map tile, that is not being eaten by other organism

	/**
	 * Returns all cave locations in the simulation.
	 * @return vector<Vector> - vector of positions (centers) of caves.
	 */
	std::vector<Vector> getCaveLocations();

	static double getCaveRadius();	///< Getter for Cave radius.

private:
	static const double CAVE_RADIUS; ///< Radius of caves that are placed in this map

	std::vector<std::shared_ptr<MapTile>> tiles_; ///< Vector containing all MapTiles that the map is composed of
	std::vector<Vector> caveLocations_; ///< Vector container storing all the locations where caves were placed
};


#endif //ARTIFICIAL_LIFE_MAP_H
