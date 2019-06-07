/**
 * Represents one, atomic segment of a map, that can be either a cave or a grass.
 */

#include <include/ALife/MapTile.h>
#include <include/ALife/MapTileView.h>
#include <include/ALife/Organism.h>

double MapTile::size_ = 3.0 * Organism::getRadius();

MapTile::MapTile(TileType type, Vector position): 
    type_(type), 
    position_(position),
    eater_(nullptr),
    view_(nullptr)
{
    if(type == TileType::CAVE)
    {
        grassiness_ = -1.0;
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

double MapTile::getSize()
{
    return size_;
}

const Herbivore* MapTile::getEater() const
{
    return eater_;
}

void MapTile::setEater(const Herbivore* eater)
{
    eater_ = eater;
}

void MapTile::registerView(MapTileView* view)
{
    view_ = view;
}

void MapTile::reset()
{
    grassiness_ = 10.0;
    if(view_) view_->update();
}

void MapTile::increaseGrassiness(float value)
{
    if(type_ != TileType::GRASS) return;
    
    grassiness_ += value;
    grassiness_ = std::min(grassiness_, 10.0f);
    if(view_) view_->update();
}

void MapTile::decreaseGrassiness(float value)
{
    if(type_ != TileType::GRASS) return;

    grassiness_ -= value;
    grassiness_ = std::max(grassiness_, 0.0f);
    if(view_) view_->update();
}