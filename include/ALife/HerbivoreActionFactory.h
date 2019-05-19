
#ifndef ARTIFICIAL_LIFE_HERBIVOREACTIONFACTORY_H
#define ARTIFICIAL_LIFE_HERBIVOREACTIONFACTORY_H


class Herbivore;
class Simulation;


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

private:

	HerbivoreActionFactory() = default;		///< Private default constructor - according to Singleton design pattern.

};


#endif //ARTIFICIAL_LIFE_HERBIVOREACTIONFACTORY_H
