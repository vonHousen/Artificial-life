/**
 * Base class for organisms' views, whose objects are added to simulation view.
 */

#include "OrganismView.h"
#include "Organism.h"
#include "Vector.h"

OrganismView::OrganismView(Organism* const model):
    model_(model)
{
    Vector position = model_->getPosition();
    float radius = model_->getRadius();

    setRect(-radius, -radius, radius, radius);
    setPos(position.getX(), position.getY());
}

void OrganismView::update()
{
    Vector newPosition = model_->getPosition();
    setPos(newPosition.getX(), newPosition.getY());
}