
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

    HerbivoreView(Herbivore* const model);	// TODO make documentation

private:

};

#endif //ARTIFICIAL_LIFE_HERBIVOREVIEW_H