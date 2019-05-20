/**
 * Concrete view for herbivores, responsible for their visual representation
 */

#include <include/ALife/HerbivoreView.h>
#include <include/ALife/Herbivore.h>

HerbivoreView::HerbivoreView(Herbivore* const model): OrganismView(model)
{
    setBrush(QBrush(Qt::green));
}