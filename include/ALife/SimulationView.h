
#ifndef ARTIFICIAL_LIFE_SIMULATIONVIEW_H
#define ARTIFICIAL_LIFE_SIMULATIONVIEW_H

class Window;
class Simulation;
class Organism;
class Carnivore;
class Herbivore;
class CarnivoreView;
class HerbivoreView;

#include <QtWidgets>
#include <unordered_map>

/**
 * Class responsible for visual representation of the simulation
 */

class SimulationView	// TODO make documentation
{
public:
    SimulationView(Window* const, QGraphicsScene* const, Simulation* const);
    ~SimulationView();

    void update();
    void notifyWhenOrganismAdded(Carnivore* const);
    void notifyWhenOrganismAdded(Herbivore* const);
    void notifyWhenOrganismRemoved(Carnivore* const);
    void notifyWhenOrganismRemoved(Herbivore* const);

private:
    Window* const window_;
    Simulation* const model_;
    QGraphicsScene* const qGraphicsScene_;
    std::unordered_map<Carnivore*, CarnivoreView*> carnivoreViews_;
    std::unordered_map<Herbivore*, HerbivoreView*> herbivoreViews_;
};

#endif //ARTIFICIAL_LIFE_SIMULATIONVIEW_H