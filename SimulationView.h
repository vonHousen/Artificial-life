/*
 * SimulationView TODO
 */

#ifndef ARTIFICIAL_LIFE_SIMULATIONVIEW_H
#define ARTIFICIAL_LIFE_SIMULATIONVIEW_H

class Simulation;
class Organism;
class OrganismView;

#include <QtWidgets>
#include <vector>

class SimulationView
{
public:
    SimulationView(QGraphicsScene*, Simulation* const);
    ~SimulationView();

    void update();
    void notifyWhenOrganismAdded(Organism* const);
    void notifyWhenOrganismRemoved(Organism* const);

private:
    Simulation* const model_;
    QGraphicsScene* qGraphicsScene_;
    std::vector<OrganismView*> organismViews_;
};

#endif //ARTIFICIAL_LIFE_SIMULATIONVIEW_H