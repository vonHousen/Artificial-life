#ifndef ARTIFICIAL_LIFE_STATISTICSWIDGET_H
#define ARTIFICIAL_LIFE_STATISTICSWIDGET_H

class Window;
class Organism;

#include <QtWidgets>

class StatisticsWidget : public QWidget
{
public:
    explicit StatisticsWidget(Window* window);

    void updateIndividualInfo(const Organism* organism);
private:
    Window* window_;

    QLabel* qOrganismHealth_;                           ///< Label indicating selected organism's health
    QLabel* qOrganismTimeAlive_;                        ///< Label indicating how long selected organism is alive
    QLabel* qOrganismAlertness_;                        ///< Label indicating selected organism's alertness
    QLabel* qOrganismSightRange_;                       ///< Label indicating selected organism's sight range 
    QLabel* qOrganismStamina_;                          ///< Label indicating selected organism's stamina
    QLabel* qOrganismSpeed_;                            ///< Label indicating selected organism's speed
    QLabel* qOrganismLifespan_;                         ///< Label indicating selected organism's lifespan
    QLabel* qOrganismHunger_;                           ///< Label indicating selected organism's hunger
    QLabel* qOrganismTiredness_;                        ///< Label indicating selected organism's tiredness
    QLabel* qOrganismLoneliness_;                       ///< Label indicating selected organism's loneliness
};

#endif //ARTIFICIAL_LIFE_STATISTICSWIDGET_H