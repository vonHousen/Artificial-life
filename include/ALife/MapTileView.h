#ifndef ARTIFICIAL_LIFE_MAPTILEVIEW_H
#define ARTIFICIAL_LIFE_MAPTILEVIEW_H

#include <QtWidgets>

class MapTile;

class MapTileView : public QGraphicsRectItem
{
public:
    MapTileView(MapTile* const model);

    void update();
private:
    MapTile* const model_;
};

#endif //ARTIFICIAL_LIFE_MAPTILEVIEW_H