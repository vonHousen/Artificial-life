/**
 * Class responsible for visual representation of the simulation
 */

#include <include/ALife/Simulation.h>
#include <include/ALife/SimulationView.h>
#include <include/ALife/CarnivoreView.h>
#include <include/ALife/HerbivoreView.h>
#include <include/ALife/MapTileView.h>
#include <include/ALife/MapTile.h>
#include <include/ALife/Window.h>

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

    for(auto mapTileViewPair : mapTileViews_)
    {
        delete mapTileViewPair.second;
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

    for(auto mapTileViewPair : mapTileViews_)
    {
        mapTileViewPair.second->update();
    }
}

void SimulationView::createViewsForMap(Map* const map)
{
    auto tiles = map->getTiles();
    for(auto tile : tiles)
    {
        auto mapTileView = new MapTileView(tile.get());
        tile->registerView(mapTileView);
        qGraphicsScene_->addItem(mapTileView);
        mapTileViews_.emplace(std::make_pair(tile.get(), mapTileView));
    }
}

void SimulationView::notifyWhenOrganismAdded(Carnivore* const organismToAdd)
{
    auto newOrganismView = new CarnivoreView(organismToAdd, this);
    qGraphicsScene_->addItem(newOrganismView);
    carnivoreViews_.emplace(std::make_pair(organismToAdd, newOrganismView));
    window_->updateOrganismCount();
}

void SimulationView::notifyWhenOrganismAdded(Herbivore* const organismToAdd)
{
    auto newOrganismView = new HerbivoreView(organismToAdd, this);
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

void SimulationView::notifyWhenOrganismClicked(Organism* const organism, OrganismView* view) const
{
    window_->showOrganismInfo(organism, view);
}

void SimulationView::notifyWhenSelectedViewDeleted(OrganismView* const view) const
{
    window_->unselectDeletedView(view);
}