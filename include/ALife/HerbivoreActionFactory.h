
#ifndef ARTIFICIAL_LIFE_HERBIVOREACTIONFACTORY_H
#define ARTIFICIAL_LIFE_HERBIVOREACTIONFACTORY_H


class Herbivore;
class Simulation;
class HerbivoreEating;
class HerbivoreSleeping;
class HerbivoreReproduction;

#include <memory>

/**
 * Factory Design Pattern for Herbivore's Actions. It's a singleton
 */

class HerbivoreActionFactory
{
public:

	HerbivoreActionFactory(const HerbivoreActionFactory&) = delete;				///< Deleted one-parameter constructor.
	HerbivoreActionFactory& operator=(const HerbivoreActionFactory&) = delete;	///< Deleted assignment operator.
	HerbivoreActionFactory(HerbivoreActionFactory&&) = delete;					///< Deleted moving constructor.
	HerbivoreActionFactory& operator=(HerbivoreActionFactory&&) = delete;		///< Deleted moving assignment operator.

	/**
	 * Gets an instance of HerbivoreActionFactory, according to Singleton design pattern.
	 * @return instance of HerbivoreActionFactory.
	 */
	static HerbivoreActionFactory& getInstance();

	std::unique_ptr<HerbivoreEating> produceEatingAction(Herbivore* const owner, Simulation* const simulation);

	/**
	 * Produces Action of sleeping.
	 * @param owner - Herbivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 * @return HerbivoreSleeping - individual action.
	 */
	std::unique_ptr<HerbivoreSleeping> produceSleepingAction(Herbivore* const owner, Simulation* const simulation);

	/**
	 * Produces Action of reproduction.
	 * @param owner - Herbivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 * @return HerbivoreReproduction- individual action.
	 */
	std::unique_ptr<HerbivoreReproduction> produceReproductionAction(Herbivore* const owner, Simulation* const simulation);


private:

	HerbivoreActionFactory() = default;		///< Private default constructor - according to Singleton design pattern.

};


#endif //ARTIFICIAL_LIFE_HERBIVOREACTIONFACTORY_H
