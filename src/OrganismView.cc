/*
 * OrganismView TODO
 */

#include "OrganismView.h"
#include "Organism.h"
#include "Vector.h"

OrganismView::OrganismView(Organism* const model):
    model_(model)
{
    Vector position = model_->getPosition();
    float radius = model_->getRadius();

    setRect(position.getX(), position.getY(), radius, radius);
    setBrush(QBrush(Qt::white));
}

void OrganismView::update()
{
    Vector newPosition = model_->getPosition();
    setPos(newPosition.getX(), newPosition.getY());
}