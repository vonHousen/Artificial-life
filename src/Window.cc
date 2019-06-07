/**
 * Main window to display simulation
 */

#include <iostream>

#include <include/ALife/Window.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/OrganismView.h>
#include <include/ALife/Organism.h>
#include <include/ALife/IndividualStatisticsWidget.h>
#include <include/ALife/SpeciesStatisticsWidget.h>
#include <include/ALife/StatisticsVisitor.h>

Window::Window(std::shared_ptr<Simulation> simulation, int size, QWidget* parent): 
    QWidget(parent), 
    size_(size),
    selectedOrganism_(nullptr),
    selectedOrganismView_(nullptr),
    simulation_(std::move(simulation))
{
    setWindowTitle(tr("Artificial Life"));

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

    qLabelSetCarnivoresPopulation_ = new QLabel(this);
    qLabelSetHerbivoresPopulation_ = new QLabel(this);

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

    updateCarnivorePopulationLabel(qSliderCarnivores_->value());
    updateHerbivorePopulationLabel(qSliderHerbivores_->value());

    QPushButton* button = new QPushButton(this);
    button->setText("Reset simulation");
    connect(button, SIGNAL(released()), this, SLOT(handleButtonEvent()));

    QVBoxLayout* vlayout = new QVBoxLayout();
    vlayout->setSpacing(10);
    vlayout->setMargin(10);
    vlayout->setAlignment(Qt::AlignTop);

    //Controls related to simulation reset feature
    vlayout->addWidget(qLabelSetCarnivoresPopulation_);
    vlayout->addWidget(qSliderCarnivores_);
    vlayout->addWidget(qLabelSetHerbivoresPopulation_);
    vlayout->addWidget(qSliderHerbivores_);
    vlayout->addWidget(button);
    vlayout->addSpacing(10);

    //Add statistics view
    statisitcsView_ = new IndividualStatisticsWidget(this);
    vlayout->addWidget(statisitcsView_);

    //Add statistics view
    speciesStatisitcsView_ = new SpeciesStatisticsWidget(this);
    vlayout->addWidget(speciesStatisitcsView_);
    speciesStatisitcsView_->show();

    QHBoxLayout* hlayout = new QHBoxLayout(this);
    hlayout->setMargin(0);
    hlayout->setSpacing(0);
    hlayout->addWidget(qGraphicsView_);
    hlayout->addLayout(vlayout);

    setLayout(hlayout);
    adjustSize();
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    qTimer_ = new QTimer(this);
    connect(qTimer_, SIGNAL(timeout()), this, SLOT(update()));
    qTimer_->start(5);
}

void Window::showOrganismInfo(Organism* const organism, OrganismView* const organismView)
{
    if(selectedOrganismView_ and selectedOrganismView_ != organismView) 
        selectedOrganismView_->unselect();
    
    selectedOrganism_ = organism;
    selectedOrganismView_ = organismView;
    
    statisitcsView_->updateIndividualInfo(organism);
    speciesStatisitcsView_->hide();
    statisitcsView_->show();
}

void Window::unselectDeletedView(OrganismView* const organismView)
{
    selectedOrganism_ = nullptr;
    selectedOrganismView_ = nullptr;

    statisitcsView_->hide();
    speciesStatisitcsView_->show();
}

void Window::mousePressEvent(QMouseEvent* event)
{
    if(!selectedOrganismView_) return;

    QPoint positionInViewSpace = qGraphicsView_->mapFromParent(event->pos());
    if(qGraphicsView_->rect().contains(positionInViewSpace))
    {
        selectedOrganismView_->unselect();
        selectedOrganism_ = nullptr;
        selectedOrganismView_ = nullptr;

        statisitcsView_->hide();
        speciesStatisitcsView_->show();
    }
}

void Window::update()
{
    simulation_->update();
    if(selectedOrganism_) statisitcsView_->updateIndividualInfo(selectedOrganism_);
    else
    {
        StatisticsVisitor stats;
        simulation_->getStatistics(stats);
        speciesStatisitcsView_->updateInfo(stats, simulation_->getSimulationTime());
    }
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