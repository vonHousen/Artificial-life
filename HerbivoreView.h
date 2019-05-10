/*
 * Concrete view for herbivores, responsible for their visual representation
 */

#ifndef ARTIFICIAL_LIFE_HERBIVOREVIEW_H
#define ARTIFICIAL_LIFE_HERBIVOREVIEW_H

#include "OrganismView.h"

class Herbivore;

class HerbivoreView : public OrganismView
{
public:
    HerbivoreView(Herbivore* const model);
private:
};

#endif //ARTIFICIAL_LIFE_HERBIVOREVIEW_H