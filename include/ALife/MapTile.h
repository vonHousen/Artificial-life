#ifndef ARTIFICIAL_LIFE_MAPTILE_H
#define ARTIFICIAL_LIFE_MAPTILE_H

/**
 * Represents one, atomic segment of a map, that can be either a cave or a grass.
 */

#include "include/ALife/Vector.h"

class MapTileView;

enum class TileType { GRASS, CAVE };

class MapTile
{
public:
	MapTile(TileType type, Vector position);

	TileType getType() const;
	Vector getPosition() const;
	float getGrassiness() const;

    static double getSize();

	void registerView(MapTileView* view);

	void reset();

	void increaseGrassiness(float value);
	void decreaseGrassiness(float value);

private:
	TileType type_;
	Vector position_;
	float grassiness_;
    static double size_;
	MapTileView* view_;
};

#endif //ARTIFICIAL_LIFE_MAPTILE_H