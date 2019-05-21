
#ifndef ARTIFICIAL_LIFE_ORGANISMVIEW_H
#define ARTIFICIAL_LIFE_ORGANISMVIEW_H

class Organism;
class SimulationView;

#include <QtWidgets>

/**
 * Base class for Organisms' views, whose objects are added to Simulation view to be displayed. 
 * It is derived from QGraphicsEllipseItem so as to be added to QGraphicsScene.
 */

class OrganismView : public QGraphicsEllipseItem
{
public:

    /**
	 * A constructor.
	 * @param model - Organism related to this view, that will be displayed.
	 */
    OrganismView(Organism* const model, SimulationView* const owner);
    ~OrganismView();

    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event); //TODO document
    virtual void unselect();
    virtual void update();      ///< Updates position to match owner's location. Called by Organism.

private:
    Organism* const model_;         ///< pointer to organism, that this view represents
    SimulationView* const owner_;   //TODO document
    bool isSelected_;
};

#endif //ARTIFICIAL_LIFE_ORGANISMVIEW_H