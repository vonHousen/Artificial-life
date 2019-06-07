
#include <include/ALife/SpeciesStatisticsWidget.h>
#include <include/ALife/Window.h>

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

void SpeciesStatisticsWidget::updateInfo()
{
    qCarnivoresName_->setText(QString("Carnivores:"));
    qCarnivoresHealth_->setText(QString("Health: "));
    qCarnivoresTimeAlive_->setText(QString("Time alive: "));
    qCarnivoresAlertness_->setText(QString("Alertness: "));
    qCarnivoresSightRange_->setText(QString("Sight range: "));
    qCarnivoresStamina_->setText(QString("Stamina: "));
    qCarnivoresSpeed_->setText(QString("Speed: "));
    qCarnivoresLifespan_->setText(QString("Lifespan: "));
    
    qHerbivoresName_->setText(QString("Herbivores:"));
    qHerbivoresHealth_->setText(QString("Health: "));
    qHerbivoresTimeAlive_->setText(QString("Time alive: "));
    qHerbivoresAlertness_->setText(QString("Alertness: "));
    qHerbivoresSightRange_->setText(QString("Sight range: "));
    qHerbivoresStamina_->setText(QString("Stamina: "));
    qHerbivoresSpeed_->setText(QString("Speed: "));
    qHerbivoresLifespan_->setText(QString("Lifespan: "));
}