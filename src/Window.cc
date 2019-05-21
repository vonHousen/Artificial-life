/**
 * Main window to display simulation
 */

#include <iostream>

#include <include/ALife/Window.h>
#include <include/ALife/Simulation.h>

Window::Window(std::shared_ptr<Simulation> simulation, int size, QWidget* parent): 
    QWidget(parent), 
    size_(size), 
    simulation_(std::move(simulation))
{
    setWindowTitle(tr("Artificial Life"));
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    qGraphicsScene_ = new QGraphicsScene(this);
    qGraphicsScene_->setSceneRect(-1, -1, 2, 2);

    simulationView_ = std::make_unique<SimulationView>(this, qGraphicsScene_, simulation_.get());

    QGraphicsView* view = new QGraphicsView(qGraphicsScene_, this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setStyleSheet("border-style: none");
    view->setFixedSize(size, size);
    
    view->translate(1, 1);
    view->scale(size*0.5, -size*0.5);

    qLabelCarnivores_ = new QLabel(this);
    qLabelCarnivores_->setText("Carnivores: ");

    qLabelHerbivores_ = new QLabel(this);
    qLabelHerbivores_->setText("Herbivores: ");

    qLabelSetCarnivoresPopulation_ = new QLabel(this);
    qLabelSetCarnivoresPopulation_->setText("Carnivore population: 10");

    qLabelSetHerbivoresPopulation_ = new QLabel(this);
    qLabelSetHerbivoresPopulation_->setText("Herbivore population: 10");

    qSliderCarnivores_ = new QSlider(this);
    qSliderCarnivores_->setOrientation(Qt::Horizontal);
    qSliderCarnivores_->setRange(0, 100);
    qSliderCarnivores_->setValue(10);
    connect(qSliderCarnivores_, SIGNAL(valueChanged(int)), this, SLOT(updateCarnivorePopulationLabel(int)));

    qSliderHerbivores_ = new QSlider(this);
    qSliderHerbivores_->setOrientation(Qt::Horizontal);
    qSliderHerbivores_->setRange(0, 100);
    qSliderHerbivores_->setValue(10);
    connect(qSliderHerbivores_, SIGNAL(valueChanged(int)), this, SLOT(updateHerbivorePopulationLabel(int)));

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
    vlayout->addWidget(qLabelSetCarnivoresPopulation_);
    vlayout->addWidget(qSliderCarnivores_);
    vlayout->addWidget(qLabelSetHerbivoresPopulation_);
    vlayout->addWidget(qSliderHerbivores_);
    vlayout->addWidget(button);

    QHBoxLayout* hlayout = new QHBoxLayout(this);
    hlayout->setMargin(0);
    hlayout->setSpacing(0);
    hlayout->addWidget(view);
    hlayout->addLayout(vlayout);

    view->setBackgroundBrush(QBrush(Qt::black));

    setLayout(hlayout);

    qTimer_ = new QTimer(this);
    connect(qTimer_, SIGNAL(timeout()), this, SLOT(update()));
    qTimer_->start(5);
}

void Window::updateOrganismCount()
{
    int carnivores = simulation_->getCarnivoreCount();
    int herbivores = simulation_->getHerbivoreCount();

    qLabelCarnivores_->setText(QString("Carnivores: ") + QString::number(carnivores));
    qLabelHerbivores_->setText(QString("Herbivores: ") + QString::number(herbivores));
}

void Window::update()
{
    simulation_->update();
}

void Window::updateCarnivorePopulationLabel(int value)
{
    qLabelSetCarnivoresPopulation_->setText(QString("Carnivores population: ") + QString::number(value));
}

void Window::updateHerbivorePopulationLabel(int value)
{
    qLabelSetHerbivoresPopulation_->setText(QString("Herbivores population: ") + QString::number(value));
}

void Window::handleButtonEvent()
{
    simulation_->reset(qSliderCarnivores_->value(), qSliderHerbivores_->value());
}

Window::~Window()
{}