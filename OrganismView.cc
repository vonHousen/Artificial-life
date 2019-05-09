/*
 * OrganismView TODO
 */

#include "OrganismView.h"

OrganismView::OrganismView(Organism* const model):
    model_(model)
{
    Vector position = model_->getPosition();
    float radius = model_->getRadius();

    setRect(position.getX() - radius*0.5, position.getY() - radius*0.5, radius, radius);
    setBrush(QBrush(Qt::white));
}

void OrganismView::update()
{
    Vector newPosition = model_->getPosition();
    setPos(newPosition.getX(), newPosition.getY());
}