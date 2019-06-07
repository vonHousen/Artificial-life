
#include <include/ALife/StatisticsVisitor.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/Herbivore.h>

StatisticsVisitor::StatisticsVisitor()
{
    reset();
}

void StatisticsVisitor::visit(const Carnivore& carnivore)
{
    numCarnivores_++;
    sumCarnivoresHealth_ += carnivore.getHealth();
    sumCarnivoresTimeAlive_ += carnivore.getTimeAlive();
    sumCarnivoresAlertness_ += carnivore.getAlertness();
    sumCarnivoresSightRange_ += carnivore.getSightRange();
    sumCarnivoresStamina_ += carnivore.getStamina();
    sumCarnivoresSpeed_ += carnivore.getSpeed();
    sumCarnivoresLifespan_ += carnivore.getLifespan();
}

void StatisticsVisitor::visit(const Herbivore& herbivore)
{
    numHerbivores_++;
    sumHerbivoresHealth_ += herbivore.getHealth();
    sumHerbivoresTimeAlive_ += herbivore.getTimeAlive();
    sumHerbivoresAlertness_ += herbivore.getAlertness();
    sumHerbivoresSightRange_ += herbivore.getSightRange();
    sumHerbivoresStamina_ += herbivore.getStamina();
    sumHerbivoresSpeed_ += herbivore.getSpeed();
    sumHerbivoresLifespan_ += herbivore.getLifespan();
}

void StatisticsVisitor::reset()
{
    numCarnivores_ = 0;
    sumCarnivoresHealth_ = 0;
    sumCarnivoresTimeAlive_ = 0;
    sumCarnivoresAlertness_ = 0;
    sumCarnivoresSightRange_ = 0;
    sumCarnivoresStamina_ = 0;
    sumCarnivoresSpeed_ = 0;
    sumCarnivoresLifespan_ = 0;

    numHerbivores_ = 0;
    sumHerbivoresHealth_ = 0;
    sumHerbivoresTimeAlive_ = 0;
    sumHerbivoresAlertness_ = 0;
    sumHerbivoresSightRange_ = 0;
    sumHerbivoresStamina_ = 0;
    sumHerbivoresSpeed_ = 0;
    sumHerbivoresLifespan_ = 0;
}

unsigned int StatisticsVisitor::getCarnivoreCount() const
{
    return numCarnivores_;
}

float StatisticsVisitor::getAvgCarnivoreHealth() const
{
    if(numCarnivores_ == 0) return 0;
    else return sumCarnivoresHealth_ / numCarnivores_;
}

float StatisticsVisitor::getAvgCarnivoreTimeAlive() const
{
    if(numCarnivores_ == 0) return 0;
    else return sumCarnivoresTimeAlive_ / numCarnivores_;
}

float StatisticsVisitor::getAvgCarnivoreAlertness() const
{
    if(numCarnivores_ == 0) return 0;
    else return sumCarnivoresAlertness_ / numCarnivores_;
}

float StatisticsVisitor::getAvgCarnivoreSightRange() const
{
    if(numCarnivores_ == 0) return 0;
    else return sumCarnivoresSightRange_ / numCarnivores_;
}

float StatisticsVisitor::getAvgCarnivoreStamina() const
{
    if(numCarnivores_ == 0) return 0;
    else return sumCarnivoresStamina_ / numCarnivores_;
}

float StatisticsVisitor::getAvgCarnivoreSpeed() const
{
    if(numCarnivores_ == 0) return 0;
    else return sumCarnivoresSpeed_ / numCarnivores_;
}

float StatisticsVisitor::getAvgCarnivoreLifespan() const
{
    if(numCarnivores_ == 0) return 0;
    else return sumCarnivoresLifespan_ / numCarnivores_;
}

unsigned int StatisticsVisitor::getHerbivoreCount() const
{
    return numHerbivores_;
}

float StatisticsVisitor::getAvgHerbivoreHealth() const
{
    if(numHerbivores_ == 0) return 0;
    else return sumHerbivoresHealth_ / numCarnivores_;
}

float StatisticsVisitor::getAvgHerbivoreTimeAlive() const
{
    if(numHerbivores_ == 0) return 0;
    else return sumHerbivoresTimeAlive_ / numHerbivores_;
}

float StatisticsVisitor::getAvgHerbivoreAlertness() const
{
    if(numHerbivores_ == 0) return 0;
    else return sumHerbivoresAlertness_ / numHerbivores_;
}

float StatisticsVisitor::getAvgHerbivoreSightRange() const
{
    if(numHerbivores_ == 0) return 0;
    else return sumHerbivoresSightRange_ / numHerbivores_;
}

float StatisticsVisitor::getAvgHerbivoreStamina() const
{
    if(numHerbivores_ == 0) return 0;
    else return sumHerbivoresStamina_ / numHerbivores_;
}

float StatisticsVisitor::getAvgHerbivoreSpeed() const
{
    if(numHerbivores_ == 0) return 0;
    else return sumHerbivoresSpeed_ / numHerbivores_;
}

float StatisticsVisitor::getAvgHerbivoreLifespan() const
{
    if(numHerbivores_ == 0) return 0;
    else return sumHerbivoresLifespan_ / numHerbivores_;
}
