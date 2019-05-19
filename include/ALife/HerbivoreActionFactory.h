/**
 * Factory Design Pattern for Herbivore's actions. It's a singleton
 */

#ifndef ARTIFICIAL_LIFE_HERBIVOREACTIONFACTORY_H
#define ARTIFICIAL_LIFE_HERBIVOREACTIONFACTORY_H


class HerbivoreActionFactory final
{
public:
	HerbivoreActionFactory(const HerbivoreActionFactory&) = delete;
	HerbivoreActionFactory& operator=(const HerbivoreActionFactory&) = delete;
	HerbivoreActionFactory(HerbivoreActionFactory&&) = delete;
	HerbivoreActionFactory& operator=(HerbivoreActionFactory&&) = delete;

	static HerbivoreActionFactory& getInstance();

private:
	HerbivoreActionFactory() = default;

};


#endif //ARTIFICIAL_LIFE_HERBIVOREACTIONFACTORY_H
