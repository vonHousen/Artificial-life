/**
 * Concrete view for carnivores, responsible for their visual representation
 */

#include "CarnivoreView.h"
#include "Carnivore.h"

CarnivoreView::CarnivoreView(Carnivore* const model): OrganismView(model)
{
    setBrush(QBrush(Qt::red));
}