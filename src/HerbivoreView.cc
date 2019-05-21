/**
 * Concrete view for herbivores, responsible for their visual representation
 */

#include <include/ALife/HerbivoreView.h>
#include <include/ALife/Herbivore.h>

HerbivoreView::HerbivoreView(Herbivore* const model, SimulationView* const owner): 
    OrganismView(model, owner)
{
    setBrush(QBrush(Qt::green));
}