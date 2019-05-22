/**
 * Map consisting of MapTiles, that covers simulation's area.
 */

#include <include/ALife/Map.h>
#include <include/ALife/Vector.h>
#include <include/ALife/MapTile.h>

Map::Map()
{
    const int TILES_ACROSS_DIMENTION = 2.0 / MapTile::getSize() + 0.5;
    for(int ny = 0; ny < TILES_ACROSS_DIMENTION; ++ny)
    {
        for(int nx = 0; nx < TILES_ACROSS_DIMENTION; ++nx)
        {
            double posX = -1.0 + nx * MapTile::getSize();
            double posY = -1.0 + ny * MapTile::getSize();

            tiles_.emplace_back(std::make_shared<MapTile>(TileType::GRASS, Vector(posX, posY)));
        }
    }
}

void Map::update()
{
    for (auto tile : tiles_)
    {
        tile->increaseGrassiness(0.001);
    }
}

const std::vector<std::shared_ptr<MapTile>>& Map::getTiles() const
{
    return tiles_;
}