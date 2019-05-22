
#ifndef ARTIFICIAL_LIFE_HERBIVOREVIEW_H
#define ARTIFICIAL_LIFE_HERBIVOREVIEW_H

#include "OrganismView.h"

class Herbivore;

/**
 * Concrete view for herbivores, responsible for their visual representation
 */

class HerbivoreView : public OrganismView
{
public:

    /**
	 * A constructor.
	 *
	 * @param model - Herbivore related to this view, that will be displayed.
	 */
    HerbivoreView(Herbivore* const model, SimulationView* const owner);

private:

};

#endif //ARTIFICIAL_LIFE_HERBIVOREVIEW_H