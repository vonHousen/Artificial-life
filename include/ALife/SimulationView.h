
#ifndef ARTIFICIAL_LIFE_SIMULATIONVIEW_H
#define ARTIFICIAL_LIFE_SIMULATIONVIEW_H

class Window;
class Simulation;
class Organism;
class Carnivore;
class Herbivore;
class OrganismView;
class CarnivoreView;
class HerbivoreView;

#include <QtWidgets>
#include <unordered_map>

/**
 * Class responsible for visual representation of the simulation
 */

class SimulationView
{
public:

    /**
	 * A constructor.
	 * @param window - Pointer to window on which the simulation will be displayed.
     * @param qGraphicsScene - Pointer to Qt's scene, where objects to be displayed are being added.
     * @param model - Pointer to simulation that will be displayed.
	 */
    SimulationView(Window* const window, QGraphicsScene* const qGraphicsScene, Simulation* const model);
    ~SimulationView();                                      ///< A destructor.

    void update();                                          ///< Updated views contained in simulation to match the models' states. Called by Simulation.
    
    /**
	 * Called to notify that Carnivore object was added to simulation. 
     * Creates view related to new organism and adds it to this view.
	 * @param organismToAdd - Pointer to Carnivore that was added to simulation
	 */
    void notifyWhenOrganismAdded(Carnivore* const organismToAdd);
    
    /**
	 * Called to notify that Herbivore object was added to simulation. 
     * Creates view related to new organism and adds it to this view.
	 * @param organismToAdd - Pointer to Herbivore that was added to simulation
	 */
    void notifyWhenOrganismAdded(Herbivore* const organismToAdd);
    
    /**
	 * Called to notify that Carnivore object was removed from simulation. 
     * Removes view related to removed organism.
	 * @param organismToAdd - Pointer to Carnivore that was removed from simulation
	 */
    void notifyWhenOrganismRemoved(Carnivore* const organismToRemove);
    
    /**
	 * Called to notify that Herbivore object was removed from simulation. 
     * Removes view related to removed organism.
	 * @param organismToAdd - Pointer to Herbivore that was removed from simulation
	 */
    void notifyWhenOrganismRemoved(Herbivore* const organismToRemove);

    void notifyWhenOrganismClicked(Organism* const organism, OrganismView* const view) const; //TODO document

    void notifyWhenSelectedViewDeleted(OrganismView* const view) const; //TODO document
private:
    Window* const window_;                                              ///< Pointer to Window on which the simulation will be displayed.
    Simulation* const model_;                                           ///< Pointer to Simulation which will be displayed.
    QGraphicsScene* const qGraphicsScene_;                              ///< Pointer to QGraphicsScene, where objects to be displayed are being added.
    std::unordered_map<Carnivore*, CarnivoreView*> carnivoreViews_;     ///< Map that stores related pairs of Carnivores and their Views, that will all be added to QGraphicsScene and displayed.
    std::unordered_map<Herbivore*, HerbivoreView*> herbivoreViews_;     ///< Map that stores related pairs of Herbiivores and their Views, that will all be added to QGraphicsScene and displayed.
};

#endif //ARTIFICIAL_LIFE_SIMULATIONVIEW_H