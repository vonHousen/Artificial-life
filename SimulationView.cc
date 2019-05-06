/*
 * OrganismView TODO
 */

#include "SimulationView.h"

SimulationView::SimulationView(QGraphicsScene* qGraphicsScene, Simulation* const model):
    qGraphicsScene_(qGraphicsScene),
    model_(model)
{
    model->registerView(this);
}

SimulationView::~SimulationView()
{
    for(auto organismView : organismViews_)
    {
        delete organismView;
    }
}

void SimulationView::update()
{
    for(auto organismView : organismViews_)
    {
        organismView->update();
    }
}

void SimulationView::notifyWhenOrganismAdded(Organism* const organismToAdd)
{
    auto newOrganismView = new OrganismView(organismToAdd);
    qGraphicsScene_->addItem(newOrganismView);
    organismViews_.push_back(newOrganismView);
}

void SimulationView::notifyWhenOrganismRemoved(Organism* organismToRemove)
{
    OrganismView* organismView = organismToRemove->getView();
    qGraphicsScene_->removeItem(organismView);
    organismViews_.erase(std::remove(organismViews_.begin(), organismViews_.end(), organismView), organismViews_.end());
    delete organismView;
}