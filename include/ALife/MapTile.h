#ifndef ARTIFICIAL_LIFE_MAPTILE_H
#define ARTIFICIAL_LIFE_MAPTILE_H

/**
 * Represents one, atomic segment of a map, that can be either a cave or a grass.
 */

#include "include/ALife/Vector.h"

class MapTileView;
class Herbivore;

enum class TileType { GRASS, CAVE };

class MapTile
{
public:
	MapTile(TileType type, Vector position); //TODO document

	TileType getType() const;
	Vector getPosition() const;
	float getGrassiness() const;

	const Herbivore* getEater() const;
	void setEater(const Herbivore* eater);

    static double getSize();

	void registerView(MapTileView* view);

	void reset();

	void increaseGrassiness(float value);
	void decreaseGrassiness(float value);

private:
	TileType type_;
	Vector position_;
	float grassiness_;
	const Herbivore* eater_;		//< Pointer to herbivore that is eating this tile (if it is a grass tile)
    static double size_;
	MapTileView* view_;
};

#endif //ARTIFICIAL_LIFE_MAPTILE_H