/*
 * CarnivoreActionFactory - Factory Design Pattern for Carnivore's actions. It's a singleton
 */

#ifndef ARTIFICIAL_LIFE_CARNIVOREACTIONFACTORY_H
#define ARTIFICIAL_LIFE_CARNIVOREACTIONFACTORY_H


class CarnivoreActionFactory
{
public:
	CarnivoreActionFactory(const CarnivoreActionFactory&) = delete;
	CarnivoreActionFactory& operator=(const CarnivoreActionFactory&) = delete;
	CarnivoreActionFactory(CarnivoreActionFactory&&) = delete;
	CarnivoreActionFactory& operator=(CarnivoreActionFactory&&) = delete;

	static CarnivoreActionFactory& getInstance();

private:
	CarnivoreActionFactory();

};


#endif //ARTIFICIAL_LIFE_CARNIVOREACTIONFACTORY_H
