#ifndef ARTIFICIAL_LIFE_MAPTILE_H
#define ARTIFICIAL_LIFE_MAPTILE_H

/**
 * Represents one, atomic segment of a map, that can be either a cave or a grass.
 */

#include "include/ALife/Vector.h"

class MapTileView;
class Herbivore;

/**
 * Enum class representing type of a tile
 */
enum class TileType { GRASS, CAVE };


/**
 * Class representing tile that the map is consisting of. 
 * It is either a cave type of tile, or a grassy tile.
 */

class MapTile
{
public:
	/**
	 * A constructor. Creates tile of specified type in a specified position.
	 * @param type - type of the tile
	 * @param position - position of the center of the tile
	 */
	MapTile(TileType type, Vector position);

	TileType getType() const; ///< Getter for the tile type
	Vector getPosition() const; ///< Getter for the position of the tile
	float getGrassiness() const; ///< Getter for the grassiness value

	/**
	 * Returns pointer to the Herbivore that is eating this tile (or null pointer if it's not being eaten)
	 * @return pointer to the eating Herbivore
	 */
	const Herbivore* getEater() const;

	/**
	 * Sets the eater of this tile
	 * @param eater - pointer to the Herbivore that eats this tile
	 */
	void setEater(const Herbivore* eater);

    static double getSize(); ///< Returns the size of tiles

	/**
	 * Registers the view for this tile, so that it will be informed about
	 * changing state.
	 * @param view - pointer to the map tile view that will observe this tile
	 */
	void registerView(MapTileView* view);

	void reset(); ///< Resets the states of the tile to default one

	/**
	 * Increases grassiness if this tile is of grassy type, keeping the value in range [0.0; 10.0]
	 * @param value - value by which to increase the grassiness
	 */
	void increaseGrassiness(float value);

	/**
	 * Decreases grassiness if this tile is of grassy type, keeping the value in range [0.0; 10.0]
	 * @param value - value by which to decrease the grassiness
	 */
	void decreaseGrassiness(float value);

private:
	TileType type_;					///< Tile type
	Vector position_;				///< Position of the center of the tile
	float grassiness_;				///< Value representing how grassy this tile is
	const Herbivore* eater_;		///< Pointer to herbivore that is eating this tile (if it is a grass tile)
    static double size_;			///< Size of the tiles
	MapTileView* view_;				///< Pointer to the view that observes the tile
};

#endif //ARTIFICIAL_LIFE_MAPTILE_H