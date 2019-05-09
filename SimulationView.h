/*
 * SimulationView TODO
 */

#ifndef ARTIFICIAL_LIFE_SIMULATIONVIEW_H
#define ARTIFICIAL_LIFE_SIMULATIONVIEW_H

class Window;
class Simulation;
class Organism;
class OrganismView;

#include <QtWidgets>
#include <unordered_map>

class SimulationView
{
public:
    SimulationView(Window* const, QGraphicsScene* const, Simulation* const);
    ~SimulationView();

    void update();
    void notifyWhenOrganismAdded(Organism* const);
    void notifyWhenOrganismRemoved(Organism* const);

private:
    Window* const window_;
    Simulation* const model_;
    QGraphicsScene* const qGraphicsScene_;
    std::unordered_map<Organism*, OrganismView*> organismViews_;
};

#endif //ARTIFICIAL_LIFE_SIMULATIONVIEW_H