
#ifndef ARTIFICIAL_LIFE_ORGANISMVIEW_H
#define ARTIFICIAL_LIFE_ORGANISMVIEW_H

class Organism;

#include <QtWidgets>

/**
 * Base class for Organisms' views, whose objects are added to Simulation view.
 */

class OrganismView : public QGraphicsEllipseItem	// TODO make documentation
{
public:

    OrganismView(Organism* const model);

    virtual void update();

private:
    Organism* const model_;
};

#endif //ARTIFICIAL_LIFE_ORGANISMVIEW_H