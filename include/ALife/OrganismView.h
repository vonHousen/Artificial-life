
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
    ~OrganismView(); ///< A destructor. Notifies simulation view that it was deleted so that information on corresponding organism won't be shown

    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event); ///< Handler for mouse pressing event. Selects this view and informs simulation view that some organism was clicked
    virtual void unselect();    ///< Unselects this view. Called when user selects other organism or clicks on black space
    virtual void update();      ///< Updates position to match owner's location. Called by Organism.

private:
    Organism* const model_;         ///< Pointer to organism that this view represents.
    SimulationView* const owner_;   ///< Pointer to simulation view that owns this view.
    bool isSelected_;               ///< Boolean value telling if this view was selected by clicking on it
};

#endif //ARTIFICIAL_LIFE_ORGANISMVIEW_H