
#include <include/ALife/SpeciesStatisticsWidget.h>
#include <include/ALife/Window.h>
#include <include/ALife/StatisticsVisitor.h>

SpeciesStatisticsWidget::SpeciesStatisticsWidget(Window* window)
{
    setParent(window);

    qSimulationTime_ = new QLabel(this);

    qCarnivoresName_ = new QLabel(this);
    qCarnivoresHealth_ = new QLabel(this);
    qCarnivoresTimeAlive_ = new QLabel(this);
    qCarnivoresAlertness_ = new QLabel(this);
    qCarnivoresSightRange_ = new QLabel(this);
    qCarnivoresStamina_ = new QLabel(this);
    qCarnivoresSpeed_ = new QLabel(this);
    qCarnivoresLifespan_ = new QLabel(this);

    qHerbivoresName_ = new QLabel(this);
    qHerbivoresHealth_ = new QLabel(this);
    qHerbivoresTimeAlive_ = new QLabel(this);
    qHerbivoresAlertness_ = new QLabel(this);
    qHerbivoresSightRange_ = new QLabel(this);
    qHerbivoresStamina_ = new QLabel(this);
    qHerbivoresSpeed_ = new QLabel(this);
    qHerbivoresLifespan_ = new QLabel(this);

    QVBoxLayout* vlayout = new QVBoxLayout();
    vlayout->setSpacing(5);
    vlayout->setAlignment(Qt::AlignTop);

    vlayout->addWidget(qSimulationTime_);

    vlayout->addWidget(qCarnivoresName_);
    vlayout->addWidget(qCarnivoresHealth_);
    vlayout->addWidget(qCarnivoresTimeAlive_);
    vlayout->addWidget(qCarnivoresAlertness_);
    vlayout->addWidget(qCarnivoresSightRange_);
    vlayout->addWidget(qCarnivoresStamina_);
    vlayout->addWidget(qCarnivoresSpeed_);
    vlayout->addWidget(qCarnivoresLifespan_);

    vlayout->addSpacing(10);

    vlayout->addWidget(qSimulationTime_);
    vlayout->addWidget(qHerbivoresName_);
    vlayout->addWidget(qHerbivoresHealth_ );
    vlayout->addWidget(qHerbivoresTimeAlive_);
    vlayout->addWidget(qHerbivoresAlertness_);
    vlayout->addWidget(qHerbivoresSightRange_);
    vlayout->addWidget(qHerbivoresStamina_);
    vlayout->addWidget(qHerbivoresSpeed_);
    vlayout->addWidget(qHerbivoresLifespan_);

    setLayout(vlayout);
    hide();
}

void SpeciesStatisticsWidget::updateInfo(const StatisticsVisitor& stats, float simulationTime)
{
    qSimulationTime_->setText(QString("Simulation time: ") + QString::number(simulationTime));

    qCarnivoresName_->setText(QString("Carnivores: ") + QString::number(stats.getCarnivoreCount()));
    qCarnivoresHealth_->setText(QString("Avg. Health: ") + QString::number(stats.getAvgCarnivoreHealth()));
    qCarnivoresTimeAlive_->setText(QString("Avg. Time alive: ") + QString::number(stats.getAvgCarnivoreTimeAlive()));
    qCarnivoresAlertness_->setText(QString("Avg. Alertness: ") + QString::number(stats.getAvgCarnivoreAlertness()));
    qCarnivoresSightRange_->setText(QString("Avg. Sight range: ") + QString::number(stats.getAvgCarnivoreSightRange()));
    qCarnivoresStamina_->setText(QString("Avg. Stamina: ") + QString::number(stats.getAvgCarnivoreStamina()));
    qCarnivoresSpeed_->setText(QString("Avg. Speed: ") + QString::number(stats.getAvgCarnivoreSpeed()));
    qCarnivoresLifespan_->setText(QString("Avg. Lifespan: ") + QString::number(stats.getAvgCarnivoreLifespan()));
    
    qHerbivoresName_->setText(QString("Herbivores: ") + QString::number(stats.getHerbivoreCount()));
    qHerbivoresHealth_->setText(QString("Avg. Health: ") + QString::number(stats.getAvgHerbivoreHealth()));
    qHerbivoresTimeAlive_->setText(QString("Avg. Time alive: ") + QString::number(stats.getAvgHerbivoreTimeAlive()));
    qHerbivoresAlertness_->setText(QString("Avg. Alertness: ") + QString::number(stats.getAvgHerbivoreAlertness()));
    qHerbivoresSightRange_->setText(QString("Avg. Sight range: ") + QString::number(stats.getAvgHerbivoreSightRange()));
    qHerbivoresStamina_->setText(QString("Avg. Stamina: ") + QString::number(stats.getAvgHerbivoreStamina()));
    qHerbivoresSpeed_->setText(QString("Avg. Speed: ") + QString::number(stats.getAvgHerbivoreSpeed()));
    qHerbivoresLifespan_->setText(QString("Avg. Lifespan: ") + QString::number(stats.getAvgHerbivoreLifespan()));
}