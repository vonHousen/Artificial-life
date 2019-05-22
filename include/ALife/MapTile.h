#ifndef ARTIFICIAL_LIFE_MAPTILE_H
#define ARTIFICIAL_LIFE_MAPTILE_H

/**
 * Represents one, atomic segment of a map, that can be either a cave or a grass.
 */

#include "include/ALife/Vector.h"

enum class TileType { GRASS, CAVE };

class MapTile
{
public:
	MapTile(TileType type, Vector position);

	TileType getType() const;
	Vector getPosition() const;
	float getGrassiness() const;

    static float getSize();

	void increaseGrassiness(float value);
	void decreaseGrassiness(float value);

private:
	TileType type_;
	Vector position_;
	float grassiness_;
    static float size_;
};

#endif //ARTIFICIAL_LIFE_MAPTILE_H