#ifndef ARTIFICIAL_LIFE_MAPTILEVIEW_H
#define ARTIFICIAL_LIFE_MAPTILEVIEW_H

#include <QtWidgets>

class MapTile;

/**
 * Class responsible for the visual representation of a single map tile
 */

class MapTileView : public QGraphicsRectItem
{
public:
    /**
     * A constructor. Creates view for supplied MapTile.
     * @param model - pointer to the MapTile that this view represents
     */
    explicit MapTileView(MapTile* const model);

    void update(); ///< Updates tile's color, based on changed grassines
protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget); ///< Overloaded function called by QGraphicsView to paint the tile
private:
    MapTile* const model_; ///< Pointer to the MapTile that this view represents
};

#endif //ARTIFICIAL_LIFE_MAPTILEVIEW_H