#ifndef ARTIFICIAL_LIFE_SPECIESSTATISTICSWIDGET_H
#define ARTIFICIAL_LIFE_SPECIESSTATISTICSWIDGET_H

class Window;
class Organism;
class StatisticsVisitor;

#include <QtWidgets>

class SpeciesStatisticsWidget : public QWidget
{
public:
    explicit SpeciesStatisticsWidget(Window* window);

    void updateInfo(const StatisticsVisitor& stats, float simulationTime);
private:

    QLabel* qSimulationTime_;

    QLabel* qCarnivoresName_;
    QLabel* qCarnivoresHealth_;
    QLabel* qCarnivoresTimeAlive_;
    QLabel* qCarnivoresAlertness_;
    QLabel* qCarnivoresSightRange_;
    QLabel* qCarnivoresStamina_;
    QLabel* qCarnivoresSpeed_;
    QLabel* qCarnivoresLifespan_;

    QLabel* qHerbivoresName_;
    QLabel* qHerbivoresHealth_;
    QLabel* qHerbivoresTimeAlive_;
    QLabel* qHerbivoresAlertness_;
    QLabel* qHerbivoresSightRange_;
    QLabel* qHerbivoresStamina_;
    QLabel* qHerbivoresSpeed_;
    QLabel* qHerbivoresLifespan_;
};

#endif //ARTIFICIAL_LIFE_SPECIESSTATISTICSWIDGET_H