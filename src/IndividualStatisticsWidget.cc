
#include <include/ALife/IndividualStatisticsWidget.h>
#include <include/ALife/Window.h>
#include <include/ALife/Organism.h>

IndividualStatisticsWidget::IndividualStatisticsWidget(Window* window)
{
    setParent(window);

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

    QVBoxLayout* vlayout = new QVBoxLayout(this);
    vlayout->setSpacing(10);
    vlayout->setAlignment(Qt::AlignTop);

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

    setLayout(vlayout);
    hide();
}

void IndividualStatisticsWidget::updateIndividualInfo(const Organism* organism)
{
    qOrganismHealth_->setText(QString("Health: ") + QString::number(organism->getHealth()));
    qOrganismTimeAlive_->setText(QString("Time alive: ") + QString::number(organism->getTimeAlive()));
    qOrganismAlertness_->setText(QString("Alertness: ") + QString::number(organism->getAlertness()));
    qOrganismSightRange_->setText(QString("Sight range: ") + QString::number(organism->getSightRange()));
    qOrganismStamina_->setText(QString("Stamina: ") + QString::number(organism->getStamina()));
    qOrganismSpeed_->setText(QString("Speed: ") + QString::number(organism->getSpeed()));
    qOrganismLifespan_->setText(QString("Lifespan: " + QString::number(organism->getLifespan())));
    qOrganismHunger_->setText(QString("Hunger: " + QString::number(organism->getHunger())));
    qOrganismTiredness_->setText(QString("Tiredness: " + QString::number(organism->getTiredness())));
    qOrganismLoneliness_->setText(QString("Loneliness: " + QString::number(organism->getLoneliness())));
}