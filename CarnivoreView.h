/*
 * Concrete view for carnivores, responsible for their visual representation
 */

#ifndef ARTIFICIAL_LIFE_CARNIVOREVIEW_H
#define ARTIFICIAL_LIFE_CARNIVOREVIEW_H

#include "OrganismView.h"

class Carnivore;

class CarnivoreView : public OrganismView
{
public:
    CarnivoreView(Carnivore* const model);
private:
};

#endif //ARTIFICIAL_LIFE_CARNIVOREVIEW_H