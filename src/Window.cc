/**
 * Main window to display simulation
 */

#include <iostream>

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

    qOrganismHealth_ = new QLabel(this);
    qOrganismTimeAlive_ = new QLabel(this);
    qOrganismAlertness_ = new QLabel(this);
    qOrganismSightRange_ = new QLabel(this);
    qOrganismStamina_ = new QLabel(this);
    qOrganismSpeed_ = new QLabel(this);
    qOrganismLifespan_ = new QLabel(this);
    qOrganismHunger_ = new QLabel(this);
    qOrganismTiredness_ = new QLabel(this);
    qOrganismLoneliness_ = new QLabel(this);

    setOrganismTraitsLablesVisability(false);

    QVBoxLayout* vlayout = new QVBoxLayout();
    vlayout->setSpacing(10);
    vlayout->setMargin(10);
    vlayout->setAlignment(Qt::AlignTop);

    //Labels indicating population of organisms in simulation
    vlayout->addWidget(qLabelCarnivores_);
    vlayout->addWidget(qLabelHerbivores_);
    vlayout->addSpacing(20);

    //Controls related to simulation reset feature
    vlayout->addWidget(qLabelSetCarnivoresPopulation_);
    vlayout->addWidget(qSliderCarnivores_);
    vlayout->addWidget(qLabelSetHerbivoresPopulation_);
    vlayout->addWidget(qSliderHerbivores_);
    vlayout->addWidget(button);
    vlayout->addSpacing(20);

    //Labels indicating selected organism's traits
    vlayout->addWidget(qOrganismHealth_);
    vlayout->addWidget(qOrganismTimeAlive_);
    vlayout->addWidget(qOrganismAlertness_);
    vlayout->addWidget(qOrganismSightRange_);
    vlayout->addWidget(qOrganismStamina_);
    vlayout->addWidget(qOrganismSpeed_);
    vlayout->addWidget(qOrganismLifespan_);
    vlayout->addWidget(qOrganismHunger_);
    vlayout->addWidget(qOrganismTiredness_);
    vlayout->addWidget(qOrganismLoneliness_);

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
    
    setOrganismTraitsLablesText();
    setOrganismTraitsLablesVisability(true);
}

void Window::unselectDeletedView(OrganismView* const organismView)
{
    selectedOrganism_ = nullptr;
    selectedOrganismView_ = nullptr;

    setOrganismTraitsLablesVisability(false);
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
        selectedOrganismView_->unselect();
        selectedOrganism_ = nullptr;
        selectedOrganismView_ = nullptr;

        setOrganismTraitsLablesVisability(false);
    }
}

void Window::setOrganismTraitsLablesText() const
{
    if(not selectedOrganism_) return;

    qOrganismHealth_->setText(QString("Health: ") + QString::number(selectedOrganism_->getHealth()));
    qOrganismTimeAlive_->setText(QString("Time alive: ") + QString::number(selectedOrganism_->getTimeAlive()));
    qOrganismAlertness_->setText(QString("Alertness: ") + QString::number(selectedOrganism_->getAlertness()));
    qOrganismSightRange_->setText(QString("Sight range: ") + QString::number(selectedOrganism_->getSightRange()));
    qOrganismStamina_->setText(QString("Stamina: ") + QString::number(selectedOrganism_->getStamina()));
    qOrganismSpeed_->setText(QString("Speed: ") + QString::number(selectedOrganism_->getSpeed()));
    qOrganismLifespan_->setText(QString("Lifespan: " + QString::number(selectedOrganism_->getLifespan())));
    qOrganismHunger_->setText(QString("Hunger: " + QString::number(selectedOrganism_->getHunger())));
    qOrganismTiredness_->setText(QString("Tiredness: " + QString::number(selectedOrganism_->getTiredness())));
    qOrganismLoneliness_->setText(QString("Loneliness: " + QString::number(selectedOrganism_->getLoneliness())));
}

void Window::setOrganismTraitsLablesVisability(bool value) const
{
    qOrganismHealth_->setVisible(value);
    qOrganismTimeAlive_->setVisible(value);
    qOrganismAlertness_->setVisible(value);
    qOrganismSightRange_->setVisible(value);
    qOrganismStamina_->setVisible(value);
    qOrganismSpeed_->setVisible(value);
    qOrganismLifespan_->setVisible(value);
    qOrganismHunger_->setVisible(value);
    qOrganismTiredness_->setVisible(value);
    qOrganismLoneliness_->setVisible(value);
}

void Window::update()
{
    simulation_->update();
    setOrganismTraitsLablesText();
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