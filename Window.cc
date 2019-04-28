/*
 * Main window to display simulation
 */

#include "Window.h"

Window::Window(int width, int height, QWidget *parent)
    : QWidget(parent), width_(width), height_(height)
{
    setWindowTitle(tr("Artificial Life"));
    setFixedSize(width, height);

    const int SIDE_PANEL_WIDTH = 150;

    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width - SIDE_PANEL_WIDTH, height);

    QGraphicsView* view = new QGraphicsView(scene, this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setStyleSheet("border-style: none");

    QPushButton* button = new QPushButton(this);
    button->setText("Side panel");
    button->setFixedSize(SIDE_PANEL_WIDTH, height);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(view);
    layout->addWidget(button);

    view->setBackgroundBrush(QBrush(Qt::black));

    QGraphicsEllipseItem* testEllipse = new QGraphicsEllipseItem();
    testEllipse->setRect(250, 200, 15, 15);
    testEllipse->setBrush(QBrush(Qt::white));
    scene->addItem(testEllipse);

    setLayout(layout);
}

Window::~Window()
{}