/**
 * Main window to display simulation
 */

#include <iostream>
#include <sstream>

#include <include/ALife/Window.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/OrganismView.h>
#include <include/ALife/Organism.h>

Window::Window(std::shared_ptr<Simulation> simulation, int size, QWidget* parent): 
    QWidget(parent), 
    size_(size),
    selectedOrganism_(nullptr),
    selectedOrganismView_(nullptr),
    simulation_(std::move(simulation))
{
    setWindowTitle(tr("Artificial Life"));
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    qGraphicsScene_ = new QGraphicsScene(this);
    qGraphicsScene_->setSceneRect(-1, -1, 2, 2);

    simulationView_ = std::make_unique<SimulationView>(this, qGraphicsScene_, simulation_.get());

    qGraphicsView_ = new QGraphicsView(qGraphicsScene_, this);
    qGraphicsView_->setRenderHint(QPainter::Antialiasing);
    qGraphicsView_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    qGraphicsView_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    qGraphicsView_->setStyleSheet("border-style: none");
    qGraphicsView_->setFixedSize(size, size);
    qGraphicsView_->setBackgroundBrush(QBrush(Qt::black));
    
    qGraphicsView_->translate(1, 1);
    qGraphicsView_->scale(size*0.5, -size*0.5);

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

    qOrganismPosition_ = new QLabel(this);
    qOrganismPosition_->setVisible(false);

    QVBoxLayout* vlayout = new QVBoxLayout();
    vlayout->setSpacing(10);
    vlayout->setMargin(10);
    vlayout->setAlignment(Qt::AlignTop);
    vlayout->addWidget(qLabelCarnivores_);
    vlayout->addWidget(qLabelHerbivores_);
    vlayout->addSpacing(20);
    vlayout->addWidget(qLabelSetCarnivoresPopulation_);
    vlayout->addWidget(qSliderCarnivores_);
    vlayout->addWidget(qLabelSetHerbivoresPopulation_);
    vlayout->addWidget(qSliderHerbivores_);
    vlayout->addWidget(button);
    vlayout->addSpacing(20);
    vlayout->addWidget(qOrganismPosition_);

    QHBoxLayout* hlayout = new QHBoxLayout(this);
    hlayout->setMargin(0);
    hlayout->setSpacing(0);
    hlayout->addWidget(qGraphicsView_);
    hlayout->addLayout(vlayout);

    setLayout(hlayout);

    qTimer_ = new QTimer(this);
    connect(qTimer_, SIGNAL(timeout()), this, SLOT(update()));
    qTimer_->start(5);
}

void Window::showOrganismInfo(Organism* const organism, OrganismView* const organismView)
{
    if(selectedOrganismView_ and selectedOrganismView_ != organismView) 
        selectedOrganismView_->unselect();

    std::stringstream ss;
    ss << organism->getPosition();
    qOrganismPosition_->setText(QString("Position: ") + QString(ss.str().c_str()));
    qOrganismPosition_->setVisible(true);
    selectedOrganism_ = organism;
    selectedOrganismView_ = organismView;
}

void Window::unselectDeletedView(OrganismView* const organismView)
{
    qOrganismPosition_->setVisible(false);
    selectedOrganism_ = nullptr;
    selectedOrganismView_ = nullptr;
}

void Window::updateOrganismCount()
{
    int carnivores = simulation_->getCarnivoreCount();
    int herbivores = simulation_->getHerbivoreCount();

    qLabelCarnivores_->setText(QString("Carnivores: ") + QString::number(carnivores));
    qLabelHerbivores_->setText(QString("Herbivores: ") + QString::number(herbivores));
}

void Window::mousePressEvent(QMouseEvent* event)
{
    if(!selectedOrganismView_) return;

    QPoint positionInViewSpace = qGraphicsView_->mapFromParent(event->pos());
    if(qGraphicsView_->rect().contains(positionInViewSpace))
    {
        qOrganismPosition_->setVisible(false);
        selectedOrganismView_->unselect();
        selectedOrganism_ = nullptr;
        selectedOrganismView_ = nullptr;
    }
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