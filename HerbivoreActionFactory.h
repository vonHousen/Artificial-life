/*
 * HerbivoreActionFactory - Factory Design Pattern for Herbivore's actions. It's a singleton
 */

#ifndef ARTIFICIAL_LIFE_HERBIVOREACTIONFACTORY_H
#define ARTIFICIAL_LIFE_HERBIVOREACTIONFACTORY_H


class HerbivoreActionFactory
{
public:
	HerbivoreActionFactory(const HerbivoreActionFactory&) = delete;
	HerbivoreActionFactory& operator=(const HerbivoreActionFactory&) = delete;
	HerbivoreActionFactory(HerbivoreActionFactory&&) = delete;
	HerbivoreActionFactory& operator=(HerbivoreActionFactory&&) = delete;


private:
	HerbivoreActionFactory() = default;
	static HerbivoreActionFactory& getInstance();


	friend class Herbivore;
};


#endif //ARTIFICIAL_LIFE_HERBIVOREACTIONFACTORY_H
