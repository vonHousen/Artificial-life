/**
 * Base class for organisms' views, whose objects are added to simulation view.
 */

#include <include/ALife/OrganismView.h>
#include <include/ALife/SimulationView.h>
#include <include/ALife/Organism.h>
#include <include/ALife/Vector.h>

OrganismView::OrganismView(Organism* const model, SimulationView* const owner):
    model_(model),
    owner_(owner),
    isSelected_(false)
{
    Vector position = model_->getPosition();
    float radius = Organism::getRadius();

    setRect(-radius, -radius, 2.0*radius, 2.0*radius);
    setPos(position.getX(), position.getY());
    setPen(Qt::NoPen);
}

OrganismView::~OrganismView()
{
    if(isSelected_)
    {
        unselect();
        owner_->notifyWhenSelectedViewDeleted(this);
    }
}

void OrganismView::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    owner_->notifyWhenOrganismClicked(model_, this);
    setOpacity(0.5);
    isSelected_ = true;
}

void OrganismView::unselect()
{
    setOpacity(1);
    isSelected_ = false;
}

void OrganismView::update()
{
    Vector newPosition = model_->getPosition();
    setPos(newPosition.getX(), newPosition.getY());
}