#ifndef ARTIFICIAL_LIFE_MAP_H
#define ARTIFICIAL_LIFE_MAP_H

#include <vector>
#include <memory>

class MapTile;
class Vector;

/**
 * Map consisting of MapTiles, that covers simulation's area.
 */

class Map
{
public:
	Map();	//TODO: document

	void update();
	void reset();

	const std::vector<std::shared_ptr<MapTile>>& getTiles() const;

	MapTile* getNearestMapTile(const Vector& position);

private:
	std::vector<std::shared_ptr<MapTile>> tiles_; ///< vector containing all MapTiles that the map is composed of
	std::vector<Vector> caveLocations_;
};


#endif //ARTIFICIAL_LIFE_MAP_H
