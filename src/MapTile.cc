/**
 * Represents one, atomic segment of a map, that can be either a cave or a grass.
 */

#include <include/ALife/MapTile.h>
#include <include/ALife/Organism.h>

float MapTile::size_ = 2.0f * Organism::getRadius();

MapTile::MapTile(TileType type, Vector position): 
    type_(type), 
    position_(position)
{
    if(type == TileType::CAVE)
    {
        grassiness_ = 0.0;
    }
    else //type == TileType::GRASS
    {
        grassiness_ = 10.0;
    }
}


TileType MapTile::getType() const
{
    return type_;
}

Vector MapTile::getPosition() const
{
    return position_;
}

float MapTile::getGrassiness() const
{
    return grassiness_;
}

float MapTile::getSize()
{
    return size_;
}

void MapTile::increaseGrassiness(float value)
{
    grassiness_ += value;
    grassiness_ = std::min(grassiness_, 10.0f);
}

void MapTile::decreaseGrassiness(float value)
{
    grassiness_ -= value;
    grassiness_ = std::max(grassiness_, 0.0f);
}