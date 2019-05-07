/*
 * Main window to display simulation
 */

#ifndef ARTIFICIAL_LIFE_WINDOW_H
#define ARTIFICIAL_LIFE_WINDOW_H

#include <QtWidgets>

#include "SimulationView.h"

class Window : public QWidget
{
Q_OBJECT
public:
    explicit Window(std::shared_ptr<Simulation> simulation, int size, QWidget *parent = 0);
    ~Window();
private slots:
    void update();
    void handleButtonEvent();
private:
    int size_;

    QTimer* qTimer_;
    QGraphicsScene* qGraphicsScene_;
    std::shared_ptr<Simulation> simulation_;
    std::unique_ptr<SimulationView> simulationView_;
    QLabel* qLabelCarnivores_;
    QLabel* qLabelHerbivores_;
};


#endif //ARTIFICIAL_LIFE_WINDOW_H
