/*
 * OrganismView TODO
 */

#include "SimulationView.h"
#include "Simulation.h"
#include "OrganismView.h"
#include "Window.h"

SimulationView::SimulationView(Window* const window, QGraphicsScene* const qGraphicsScene, Simulation* const model):
    window_(window),
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
    window_->updateOrganismCount();
}

void SimulationView::notifyWhenOrganismRemoved(Organism* const organismToRemove)
{
    OrganismView* organismView = organismViews_[organismToRemove];
    qGraphicsScene_->removeItem(organismView);
    organismViews_.erase(organismToRemove);
    window_->updateOrganismCount();
    delete organismView;
}