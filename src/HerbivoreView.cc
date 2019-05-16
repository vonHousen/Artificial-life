/*
 * Concrete view for herbivores, responsible for their visual representation
 */

#include "HerbivoreView.h"
#include "Herbivore.h"

HerbivoreView::HerbivoreView(Herbivore* const model): OrganismView(model)
{
    setBrush(QBrush(Qt::green));
}