#ifndef ARTIFICIAL_LIFE_MAP_H
#define ARTIFICIAL_LIFE_MAP_H

#include <vector>
#include <memory>

class MapTile;

/**
 * Map consisting of MapTiles, that covers simulation's area.
 */

class Map
{
public:
	Map();
private:
	std::vector<std::shared_ptr<MapTile>> tiles_; ///< vector containing all MapTiles that the map is composed of
};


#endif //ARTIFICIAL_LIFE_MAP_H
