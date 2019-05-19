
#ifndef ARTIFICIAL_LIFE_CARNIVOREACTIONFACTORY_H
#define ARTIFICIAL_LIFE_CARNIVOREACTIONFACTORY_H

class CarnivoreHunting;
class Carnivore;
class Simulation;


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
	CarnivoreHunting produceEatingAction(Carnivore* const owner, Simulation* const simulation);

private:

	CarnivoreActionFactory() = default;		///< Private default constructor - according to Singleton design pattern.

};


#endif //ARTIFICIAL_LIFE_CARNIVOREACTIONFACTORY_H
