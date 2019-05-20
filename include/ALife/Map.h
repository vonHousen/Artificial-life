
#ifndef ARTIFICIAL_LIFE_MAP_H
#define ARTIFICIAL_LIFE_MAP_H

#include <vector>
#include <memory>

/**
 * MapTile TODO
 */

class MapTile
{

};


/**
 * Map TODO
 */

class Map
{
private:
	std::vector<std::shared_ptr<MapTile>> tiles_;
};


#endif //ARTIFICIAL_LIFE_MAP_H
