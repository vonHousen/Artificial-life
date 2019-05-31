#include <include/ALife/MapTileView.h>
#include <include/ALife/MapTile.h>

MapTileView::MapTileView(MapTile* const model):
    model_(model)
{
    float size = model->getSize();
    Vector position = model->getPosition();

    setRect(-0.5 * size, -0.5 * size, size, size);
    setPos(position.getX(), position.getY());
    setPen(Qt::NoPen);


    update();   
}

void MapTileView::update()
{
    if(model_->getType() == TileType::GRASS)
    {
        float interpolationFactor = model_->getGrassiness() / 10.0f;
        int r = 45 * interpolationFactor + (1.0 - interpolationFactor) * 40;
        int g = 153 * interpolationFactor + (1.0 - interpolationFactor) * 10;
        int b = 27 * interpolationFactor + (1.0 - interpolationFactor) * 10;

        setBrush(QBrush(QColor(r, g, b)));
    }
    else //cave
    {
        setBrush(QBrush(QColor(100, 100, 100)));
    }
}

void MapTileView::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    //Turn off antialiasing to prevent drawing semi-transparent lines that causes 
    //visual artifacts seen as grid lines
    painter->setRenderHint(QPainter::Antialiasing, false);
    QGraphicsRectItem::paint(painter, option, widget);
}