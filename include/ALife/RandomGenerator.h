#ifndef ARTIFICIAL_LIFE_RANDOMGENERATOR_H
#define ARTIFICIAL_LIFE_RANDOMGENERATOR_H


#include <random>

/**
 * Provides a pseudo-random numbers generator with samples distributed in selected fashion
 */

class RandomGenerator
{
public:
    static RandomGenerator* getInstance();  ///< Returns unique instance of this class (Singleton desing pattern)

    double getSampleNormal();  ///< Returns sample from normal distribution with mean equal to 0 and standard deviation equal to 1.
    double getSampleUniform(); ///< Returns uniformaly distributed random sample from range [0.0; 1.0).
    std::default_random_engine& getGenerator(); ///< Getter for random engine that this generator is consisting of.

private:
    RandomGenerator();
    RandomGenerator(const RandomGenerator&) = delete;
    RandomGenerator& operator=(const RandomGenerator&) = delete;

    static RandomGenerator* pInstance_;  ///< Pointer to unique instance of this class.

    std::default_random_engine rng_;  ///< Random engine used for samples generation.
    std::uniform_real_distribution<double> uniformDistribution_;  ///< Uniform distribution of real numbers in range [0.0; 1.0).
    std::normal_distribution<double> normalDistribution_;  ///< Normal distribution of real numbers with mean 0 and standard deviation 1.
};

#endif //ARTIFICIAL_LIFE_RANDOMGENERATOR_H