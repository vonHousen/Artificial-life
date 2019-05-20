/**
 * Base class for organisms' views, whose objects are added to simulation view.
 */

#include <include/ALife/OrganismView.h>
#include <include/ALife/Organism.h>
#include <include/ALife/Vector.h>

OrganismView::OrganismView(Organism* const model):
    model_(model)
{
    Vector position = model_->getPosition();
    float radius = model_->getRadius();

    setRect(-radius, -radius, 2.0*radius, 2.0*radius);
    setPos(position.getX(), position.getY());
    setPen(Qt::NoPen);
}

void OrganismView::update()
{
    Vector newPosition = model_->getPosition();
    setPos(newPosition.getX(), newPosition.getY());
}