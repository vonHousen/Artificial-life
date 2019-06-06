/**
 * Map consisting of MapTiles, that covers simulation's area.
 */

#include <include/ALife/Map.h>
#include <include/ALife/Vector.h>
#include <include/ALife/MapTile.h>
#include <include/ALife/Herbivore.h>
#include <cmath>

const double Map::CAVE_RADIUS = 0.13;

Map::Map()
{
    const int TILES_ACROSS_DIMENTION = std::ceil(2.0 / MapTile::getSize());

    const int CAVE_COUNT = 3;
    caveLocations_.reserve(CAVE_COUNT);
    caveLocations_.push_back(Vector(0.4, 0.7));
    caveLocations_.push_back(Vector(-0.6, -0.34));
    caveLocations_.push_back(Vector(0.65, -0.76));

    for(int ny = 0; ny < TILES_ACROSS_DIMENTION; ++ny)
    {
        for(int nx = 0; nx < TILES_ACROSS_DIMENTION; ++nx)
        {
            //0.5 is added to nx and ny so as to place the middle of the tile in chosen position
            double posX = -1.0 + (nx + 0.5) * MapTile::getSize();
            double posY = -1.0 + (ny + 0.5) * MapTile::getSize();

            Vector tilePosition = Vector(posX, posY);

            //Check if tile is inside a cave
            TileType type = TileType::GRASS;
            for(auto it = caveLocations_.begin(); it < caveLocations_.end(); ++it)
            {
                double distance = (tilePosition - *it).getLength();
                if(distance < CAVE_RADIUS)
                {
                    type = TileType::CAVE;
                    break;
                }
            }

            tiles_.emplace_back(std::make_shared<MapTile>(type, tilePosition));
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

void Map::reset()
{
    for (auto tile : tiles_)
    {
        tile->reset();
    }
}

const std::vector<std::shared_ptr<MapTile>>& Map::getTiles() const
{
    return tiles_;
}

MapTile* Map::getNearestMapTile(const Herbivore* herbi)
{
    MapTile* nearestTile = nullptr;
    //distance to the nearest grassy tile will never be greater than 2
    //due to simulation's coordinates system nature
    double smallestDistance = 2;
    for (auto tile : tiles_)
    {   
        //Searched tile must meet certain conditions;
        //Apart from the obvious ones, it cannot be eaten by herbivore other than the one
        //that is looking for the food
        const Herbivore* eater = tile->getEater();
        if(tile->getType() == TileType::GRASS && (!eater || eater == herbi) && tile->getGrassiness() > 5.0)
        {
            double distance = (herbi->getPosition() - tile->getPosition()).getLength();
            if(distance < smallestDistance)
            {
                smallestDistance = distance;
                nearestTile = tile.get();
            }
        }
    }
    return nearestTile;
}

const std::vector<Vector>& Map::getCaveLocations()
{
    return caveLocations_;
}

double Map::getCaveRadius()
{
	return CAVE_RADIUS;
}
