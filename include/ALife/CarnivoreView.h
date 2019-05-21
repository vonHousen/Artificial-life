
#ifndef ARTIFICIAL_LIFE_CARNIVOREVIEW_H
#define ARTIFICIAL_LIFE_CARNIVOREVIEW_H

#include "OrganismView.h"

class Carnivore;

/**
 * Concrete view for carnivores, responsible for their visual representation
 */

class CarnivoreView : public OrganismView
{
public:

    /**
	 * A constructor.
	 *
	 * @param model - Carnivore related to this view, that will be displayed.
	 */
    CarnivoreView(Carnivore* const model);
private:

};

#endif //ARTIFICIAL_LIFE_CARNIVOREVIEW_H