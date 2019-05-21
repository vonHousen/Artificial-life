
#ifndef ARTIFICIAL_LIFE_MAP_H
#define ARTIFICIAL_LIFE_MAP_H

#include <vector>
#include <memory>

/**
 * Represents one, atomic segment of a map, that could be either a cave or a grass.
 */

class MapTile
{

};


/**
 * Map consisting of MapTiles, that covers simulation's area.
 */

class Map
{
private:
	std::vector<std::shared_ptr<MapTile>> tiles_; ///< vector containing all MapTiles that the map is composed of
};


#endif //ARTIFICIAL_LIFE_MAP_H
