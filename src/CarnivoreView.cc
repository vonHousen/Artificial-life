/**
 * Concrete view for carnivores, responsible for their visual representation
 */

#include <include/ALife/CarnivoreView.h>
#include <include/ALife/Carnivore.h>

CarnivoreView::CarnivoreView(Carnivore* const model, SimulationView* const owner): 
    OrganismView(model, owner)
{
    setBrush(QBrush(Qt::red));
}