
#ifndef ARTIFICIAL_LIFE_WINDOW_H
#define ARTIFICIAL_LIFE_WINDOW_H

#include <memory>
#include <QtWidgets>

#include "SimulationView.h"

class OrganismView;

/**
 * Main window to display Simulation
 */

class Window : public QWidget
{
Q_OBJECT
public:

    /**
	 * A constructor.
	 * @param simulation - Pointer to simulation that this window will display
     * @param size - Size of the simulation view
     * @param parent - Pointer to QWidget that contains this window
	 */
    explicit Window(std::shared_ptr<Simulation> simulation, int size, QWidget* parent = 0);
    ~Window();                                          ///< A destructor.

    void updateOrganismCount();                         ///< Updates labels what show population of organisms. Called by Simulation.
    void showOrganismInfo(Organism* const organism, OrganismView* const organismView);    // TODO document
    void unselectDeletedView(OrganismView* const organismView);
protected:
    void mousePressEvent(QMouseEvent* event);           // TODO document
private slots:
    void update();                                      ///< Slot that reacts to QTimer's tick signal. Calls Simulation's update.
    void updateCarnivorePopulationLabel(int value);     ///< Slot that reacts when slider value is changed. Updates text in label to reflect slider's value. 
    void updateHerbivorePopulationLabel(int value);     ///< Slot that reacts when slider value is changed. Updates text in label to reflect slider's value.
    void handleButtonEvent();                           ///< Slot that reacts when user clicks the Reset button. Caused reinitialization of simulation, with user-specified populations.
private:
    int size_;                                          ///< Size of the simulation view.
    Organism* selectedOrganism_;                        ///< Organism whose info about is being displayed on the window.
    OrganismView* selectedOrganismView_;                ///< View to organism whose info about is being displayed on the window.

    QTimer* qTimer_;                                    ///< Timer that ticks with regular intervals
    QGraphicsScene* qGraphicsScene_;                    ///< Scene containing all views. 
    QGraphicsView* qGraphicsView_;                      ///< Scene's view responsible for displaying scene. 
    std::shared_ptr<Simulation> simulation_;            ///< Simulation that is being displayed
    std::unique_ptr<SimulationView> simulationView_;    ///< View for simulation 
    QLabel* qLabelCarnivores_;                          ///< Label that shows current population of Carnivores
    QLabel* qLabelHerbivores_;                          ///< Label that shows current population of Herbivores
    QLabel* qLabelSetCarnivoresPopulation_;             ///< Label that shows position of slider that controls population of Carnivores that will be created on reset
    QLabel* qLabelSetHerbivoresPopulation_;             ///< Label that shows position of slider that controls population of Herbivores that will be created on reset
    QSlider* qSliderCarnivores_;                        ///< Slider that controls population of Carnivores that will be created on reset
    QSlider* qSliderHerbivores_;                        ///< Slider that controls population of Hernivores that will be created on reset
    QLabel* qOrganismPosition_;                         // PROBABLY TEMPORARY
};


#endif //ARTIFICIAL_LIFE_WINDOW_H
