
#ifndef ARTIFICIAL_LIFE_CARNIVOREACTIONFACTORY_H
#define ARTIFICIAL_LIFE_CARNIVOREACTIONFACTORY_H

class CarnivoreHunting;
class CarnivoreSleeping;
class CarnivorePairing;
class Carnivore;
class Simulation;

#include <memory>

/**
 * Factory Design Pattern for Carnivore's Actions. It's a singleton.
 */

class CarnivoreActionFactory
{
public:

	CarnivoreActionFactory(const CarnivoreActionFactory&) = delete;				///< Deleted one-parameter constructor.
	CarnivoreActionFactory& operator=(const CarnivoreActionFactory&) = delete;	///< Deleted assignment operator.
	CarnivoreActionFactory(CarnivoreActionFactory&&) = delete;					///< Deleted moving constructor.
	CarnivoreActionFactory& operator=(CarnivoreActionFactory&&) = delete;		///< Deleted moving assignment operator.

	/**
	 * Gets an instance of CarnivoreActionFactory, according to Singleton design pattern.
	 * @return instance of CarnivoreActionFactory.
	 */
	static CarnivoreActionFactory& getInstance();

	/**
	 * Produces Action of eating (finding food).
	 * @param owner - Carnivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 * @return CarnivoreHunting <=> Eating.
	 */
	std::unique_ptr<CarnivoreHunting> produceEatingAction(Carnivore* const owner, Simulation* const simulation);

	/**
	 * Produces Action of sleeping.
	 * @param owner - Carnivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 * @return CarnivoreSleeping - individual action.
	 */
	std::unique_ptr<CarnivoreSleeping> produceSleepingAction(Carnivore* const owner, Simulation* const simulation);

	/**
	 * Produces Action of pairing.
	 * @param owner - Carnivore "owning" this Action.
	 * @param simulation - Simulation that Action makes an impact on.
	 * @return CarnivorePairing - individual action.
	 */
	std::unique_ptr<CarnivorePairing> producePairingAction(Carnivore* const owner, Simulation* const simulation);

private:

	CarnivoreActionFactory() = default;		///< Private default constructor - according to Singleton design pattern.

};


#endif //ARTIFICIAL_LIFE_CARNIVOREACTIONFACTORY_H
