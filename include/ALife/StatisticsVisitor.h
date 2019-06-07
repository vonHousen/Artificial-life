#ifndef ARTIFICIAL_LIFE_STATISTICSVISITOR_H
#define ARTIFICIAL_LIFE_STATISTICSVISITOR_H

class Carnivore;
class Herbivore;

class StatisticsVisitor
{
public:
    StatisticsVisitor();

    void visit(const Carnivore& carnivore);
    void visit(const Herbivore& herbivore);

    void reset();

    unsigned int getCarnivoreCount() const;
    float getAvgCarnivoreHealth() const;
    float getAvgCarnivoreTimeAlive() const;
    float getAvgCarnivoreAlertness() const;
    float getAvgCarnivoreSightRange() const;
    float getAvgCarnivoreStamina() const;
    float getAvgCarnivoreSpeed() const;
    float getAvgCarnivoreLifespan() const;

    unsigned int getHerbivoreCount() const;
    float getAvgHerbivoreHealth() const;
    float getAvgHerbivoreTimeAlive() const;
    float getAvgHerbivoreAlertness() const;
    float getAvgHerbivoreSightRange() const;
    float getAvgHerbivoreStamina() const;
    float getAvgHerbivoreSpeed() const;
    float getAvgHerbivoreLifespan() const;

private:
    unsigned int numCarnivores_;
    float sumCarnivoresHealth_;
    float sumCarnivoresTimeAlive_;
    float sumCarnivoresAlertness_;
    float sumCarnivoresSightRange_;
    float sumCarnivoresStamina_;
    float sumCarnivoresSpeed_;
    float sumCarnivoresLifespan_;

    unsigned int numHerbivores_;
    float sumHerbivoresHealth_;
    float sumHerbivoresTimeAlive_;
    float sumHerbivoresAlertness_;
    float sumHerbivoresSightRange_;
    float sumHerbivoresStamina_;
    float sumHerbivoresSpeed_;
    float sumHerbivoresLifespan_;
};

#endif //ARTIFICIAL_LIFE_STATISTICSVISITOR_H