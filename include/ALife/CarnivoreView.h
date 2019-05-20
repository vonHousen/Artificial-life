
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

    CarnivoreView(Carnivore* const model);	// TODO make documentation

private:

};

#endif //ARTIFICIAL_LIFE_CARNIVOREVIEW_H