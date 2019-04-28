/*
 * Main window to display simulation
 */

#include <iostream>

#include "Window.h"

Window::Window(int width, int height, QWidget *parent)
    : QWidget(parent), width_(width), height_(height)
{
    setWindowTitle(tr("Artificial Life"));
    setFixedSize(width, height);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    qGraphicsScene_ = new QGraphicsScene(this);
    qGraphicsScene_->setSceneRect(0, 0, width, height);

    QGraphicsView* view = new QGraphicsView(qGraphicsScene_, this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setStyleSheet("border-style: none");

    qLabelCarnivores_ = new QLabel(this);
    qLabelCarnivores_->setText("Carnivores: ");

    qLabelHerbivores_ = new QLabel(this);
    qLabelHerbivores_->setText("Herbivores: ");

    QPushButton* button = new QPushButton(this);
    button->setText("Reset simulation");
    connect(button, SIGNAL(released()), this, SLOT(handleButtonEvent()));

    QVBoxLayout* vlayout = new QVBoxLayout();
    vlayout->setSpacing(10);
    vlayout->setMargin(10);
    vlayout->setAlignment(Qt::AlignTop);
    vlayout->addWidget(qLabelCarnivores_);
    vlayout->addWidget(qLabelHerbivores_);
    vlayout->addSpacing(200);
    vlayout->addWidget(button);

    QHBoxLayout* hlayout = new QHBoxLayout(this);
    hlayout->setMargin(0);
    hlayout->setSpacing(0);
    hlayout->addWidget(view);
    hlayout->addLayout(vlayout);

    view->setBackgroundBrush(QBrush(Qt::black));

    QGraphicsEllipseItem* testEllipse = new QGraphicsEllipseItem();
    testEllipse->setRect(250, 200, 15, 15);
    testEllipse->setBrush(QBrush(Qt::white));

    qGraphicsScene_->addItem(testEllipse);

    setLayout(hlayout);
}

void Window::handleButtonEvent()
{
    std::cout << "Reset simulation!\n";
}

Window::~Window()
{}