#ifndef ARTIFICIAL_LIFE_RANDOMGENERATOR_H
#define ARTIFICIAL_LIFE_RANDOMGENERATOR_H


#include <random>

/**
 * Provides a pseudo-random numbers generator with samples distributed in selected fashion
 */

class RandomGenerator
{
public:
    static RandomGenerator* getInstance();

    double getSampleNormal();
    double getSampleUniform();
    std::default_random_engine& getGenerator();

private:
    RandomGenerator();
    RandomGenerator(const RandomGenerator&) = delete;
    RandomGenerator& operator=(const RandomGenerator&) = delete;

    static RandomGenerator* pInstance_;

    std::default_random_engine rng_;
    std::uniform_real_distribution<double> uniformDistribution_;
    std::normal_distribution<double> normalDistribution_;
};

#endif //ARTIFICIAL_LIFE_RANDOMGENERATOR_H