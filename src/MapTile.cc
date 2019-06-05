/**
 * Represents one, atomic segment of a map, that can be either a cave or a grass.
 */

#include <include/ALife/MapTile.h>
#include <include/ALife/MapTileView.h>
#include <include/ALife/Organism.h>

double MapTile::size_ = 2.0f * Organism::getRadius();

MapTile::MapTile(TileType type, Vector position): 
    type_(type), 
    position_(position),
    isBeingEaten_(false),
    view_(nullptr)
{
    if(type == TileType::CAVE)
    {
        grassiness_ = 0.0;
    }
    else //type == TileType::GRASS
    {
        grassiness_ = 5.0;
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

bool MapTile::isBeingEaten() const
{
    return isBeingEaten_;
}

void MapTile::setBeingEaten(bool value)
{
    isBeingEaten_ = value;
}

void MapTile::registerView(MapTileView* view)
{
    view_ = view;
}

void MapTile::reset()
{
    grassiness_ = 5.0;
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