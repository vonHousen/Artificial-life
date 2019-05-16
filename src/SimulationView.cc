/*
 * SimulationView - Class responsible for visual represenation of simulation
 */

#include "SimulationView.h"
#include "Simulation.h"
#include "CarnivoreView.h"
#include "HerbivoreView.h"
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
    for(auto carnivoreViewPair : carnivoreViews_)
    {
        delete carnivoreViewPair.second;
    }

    for(auto herbivoreViewPair : herbivoreViews_)
    {
        delete herbivoreViewPair.second;
    }
}

void SimulationView::update()
{
    for(auto carnivoreViewPair : carnivoreViews_)
    {
        carnivoreViewPair.second->update();
    }

    for(auto herbivoreViewPair : herbivoreViews_)
    {
        herbivoreViewPair.second->update();
    }
}

void SimulationView::notifyWhenOrganismAdded(Carnivore* const organismToAdd)
{
    auto newOrganismView = new CarnivoreView(organismToAdd);
    qGraphicsScene_->addItem(newOrganismView);
    carnivoreViews_.emplace(std::make_pair(organismToAdd, newOrganismView));
    window_->updateOrganismCount();
}

void SimulationView::notifyWhenOrganismAdded(Herbivore* const organismToAdd)
{
    auto newOrganismView = new HerbivoreView(organismToAdd);
    qGraphicsScene_->addItem(newOrganismView);
    herbivoreViews_.emplace(std::make_pair(organismToAdd, newOrganismView));
    window_->updateOrganismCount();
}

void SimulationView::notifyWhenOrganismRemoved(Carnivore* const organismToRemove)
{
    OrganismView* organismView = carnivoreViews_[organismToRemove];
    qGraphicsScene_->removeItem(organismView);
    carnivoreViews_.erase(organismToRemove);
    window_->updateOrganismCount();
    delete organismView;
}

void SimulationView::notifyWhenOrganismRemoved(Herbivore* const organismToRemove)
{
    OrganismView* organismView = herbivoreViews_[organismToRemove];
    qGraphicsScene_->removeItem(organismView);
    herbivoreViews_.erase(organismToRemove);
    window_->updateOrganismCount();
    delete organismView;
}