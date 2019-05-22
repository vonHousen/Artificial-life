/**
 * Map consisting of MapTiles, that covers simulation's area.
 */

#include <include/ALife/Map.h>
#include <include/ALife/Vector.h>
#include <include/ALife/MapTile.h>

Map::Map()
{
    const int TILES_ACROSS_DIMENTION = 2.0 / MapTile::getSize();
    for(int ny = 0; ny < TILES_ACROSS_DIMENTION; ++ny)
    {
        for(int nx = 0; nx < TILES_ACROSS_DIMENTION; ++nx)
        {
            float positionX = -1 + nx * MapTile::getSize();
            float positionY = -1 + ny * MapTile::getSize();

            tiles_.emplace_back(std::make_shared<MapTile>(TileType::GRASS, Vector(positionX, positionY)));
        }
    }
}