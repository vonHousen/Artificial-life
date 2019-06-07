
#include <include/ALife/SpeciesStatisticsWidget.h>
#include <include/ALife/Window.h>
#include <include/ALife/StatisticsVisitor.h>

SpeciesStatisticsWidget::SpeciesStatisticsWidget(Window* window):
    window_(window)
{
    qCarnivoresName_ = new QLabel(window);
    qCarnivoresHealth_ = new QLabel(window);
    qCarnivoresTimeAlive_ = new QLabel(window);
    qCarnivoresAlertness_ = new QLabel(window);
    qCarnivoresSightRange_ = new QLabel(window);
    qCarnivoresStamina_ = new QLabel(window);
    qCarnivoresSpeed_ = new QLabel(window);
    qCarnivoresLifespan_ = new QLabel(window);

    qHerbivoresName_ = new QLabel(window);
    qHerbivoresHealth_ = new QLabel(window);
    qHerbivoresTimeAlive_ = new QLabel(window);
    qHerbivoresAlertness_ = new QLabel(window);
    qHerbivoresSightRange_ = new QLabel(window);
    qHerbivoresStamina_ = new QLabel(window);
    qHerbivoresSpeed_ = new QLabel(window);
    qHerbivoresLifespan_ = new QLabel(window);

    QVBoxLayout* vlayout = new QVBoxLayout();
    vlayout->setSpacing(5);
    vlayout->setAlignment(Qt::AlignTop);

    vlayout->addWidget(qCarnivoresName_);
    vlayout->addWidget(qCarnivoresHealth_);
    vlayout->addWidget(qCarnivoresTimeAlive_);
    vlayout->addWidget(qCarnivoresAlertness_);
    vlayout->addWidget(qCarnivoresSightRange_);
    vlayout->addWidget(qCarnivoresStamina_);
    vlayout->addWidget(qCarnivoresSpeed_);
    vlayout->addWidget(qCarnivoresLifespan_);

    vlayout->addSpacing(10);

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

void SpeciesStatisticsWidget::updateInfo(const StatisticsVisitor& stats)
{
    qCarnivoresName_->setText(QString("Carnivores: ") + QString::number(stats.getCarnivoreCount()));
    qCarnivoresHealth_->setText(QString("Health: ") + QString::number(stats.getAvgCarnivoreHealth()));
    qCarnivoresTimeAlive_->setText(QString("Time alive: ") + QString::number(stats.getAvgCarnivoreTimeAlive()));
    qCarnivoresAlertness_->setText(QString("Alertness: ") + QString::number(stats.getAvgCarnivoreAlertness()));
    qCarnivoresSightRange_->setText(QString("Sight range: ") + QString::number(stats.getAvgCarnivoreSightRange()));
    qCarnivoresStamina_->setText(QString("Stamina: ") + QString::number(stats.getAvgCarnivoreStamina()));
    qCarnivoresSpeed_->setText(QString("Speed: ") + QString::number(stats.getAvgCarnivoreSpeed()));
    qCarnivoresLifespan_->setText(QString("Lifespan: ") + QString::number(stats.getAvgCarnivoreLifespan()));
    
    qHerbivoresName_->setText(QString("Herbivores: ") + QString::number(stats.getHerbivoreCount()));
    qHerbivoresHealth_->setText(QString("Health: ") + QString::number(stats.getAvgHerbivoreHealth()));
    qHerbivoresTimeAlive_->setText(QString("Time alive: ") + QString::number(stats.getAvgHerbivoreTimeAlive()));
    qHerbivoresAlertness_->setText(QString("Alertness: ") + QString::number(stats.getAvgHerbivoreAlertness()));
    qHerbivoresSightRange_->setText(QString("Sight range: ") + QString::number(stats.getAvgHerbivoreSightRange()));
    qHerbivoresStamina_->setText(QString("Stamina: ") + QString::number(stats.getAvgHerbivoreStamina()));
    qHerbivoresSpeed_->setText(QString("Speed: ") + QString::number(stats.getAvgHerbivoreSpeed()));
    qHerbivoresLifespan_->setText(QString("Lifespan: ") + QString::number(stats.getAvgHerbivoreLifespan()));
}