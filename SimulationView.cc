/*
 * OrganismView TODO
 */

#include "SimulationView.h"
#include "Simulation.h"
#include "OrganismView.h"

SimulationView::SimulationView(QGraphicsScene* qGraphicsScene, Simulation* const model):
    qGraphicsScene_(qGraphicsScene),
    model_(model)
{
    model->registerView(this);
}

SimulationView::~SimulationView()
{
    for(auto organismViewPair : organismViews_)
    {
        delete organismViewPair.second;
    }
}

void SimulationView::update()
{
    for(auto organismViewPair : organismViews_)
    {
        organismViewPair.second->update();
    }
}

void SimulationView::notifyWhenOrganismAdded(Organism* const organismToAdd)
{
    auto newOrganismView = new OrganismView(organismToAdd);
    qGraphicsScene_->addItem(newOrganismView);
    organismViews_.emplace(std::make_pair(organismToAdd, newOrganismView));
}

void SimulationView::notifyWhenOrganismRemoved(Organism* organismToRemove)
{
    OrganismView* organismView = organismViews_[organismToRemove];
    qGraphicsScene_->removeItem(organismView);
    organismViews_.erase(organismToRemove);
    delete organismView;
}