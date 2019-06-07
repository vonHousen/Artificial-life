/**
 * Provides a pseudo-random numbers generator with samples distributed in selected fashion
 */

#include "include/ALife/RandomGenerator.h"

#include <chrono>

RandomGenerator* RandomGenerator::pInstance_ = nullptr;

RandomGenerator::RandomGenerator()
{
    //Seed random engine with time
    rng_ = std::default_random_engine(
        std::chrono::high_resolution_clock::now().time_since_epoch().count());

    uniformDistribution_ = std::uniform_real_distribution<double>(0.0, 1.0);
    normalDistribution_ = std::normal_distribution<double>(0.0, 1.0);
}

RandomGenerator* RandomGenerator::getInstance()
{
    if(!pInstance_)
    {
        pInstance_ = new RandomGenerator();
    }
    return pInstance_;
}

double RandomGenerator::getSampleNormal()
{
    return normalDistribution_(rng_);
}

double RandomGenerator::getSampleUniform()
{
    return uniformDistribution_(rng_);
}

std::default_random_engine& RandomGenerator::getGenerator()
{
    return rng_;
}
