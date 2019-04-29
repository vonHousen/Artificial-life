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
    std::cout << "~simV\n";
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
    //TODO
    //OrganismView* organismView = ___________;
    //qGraphicsScene_->removeItem(organismView);
    //delete organismView;
}