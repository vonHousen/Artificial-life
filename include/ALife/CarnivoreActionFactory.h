/**
 * Factory Design Pattern for Carnivore's actions. It's a singleton
 */

#ifndef ARTIFICIAL_LIFE_CARNIVOREACTIONFACTORY_H
#define ARTIFICIAL_LIFE_CARNIVOREACTIONFACTORY_H

class CarnivoreHunting;
class Carnivore;
class Simulation;

class CarnivoreActionFactory
{
public:
	CarnivoreActionFactory(const CarnivoreActionFactory&) = delete;
	CarnivoreActionFactory& operator=(const CarnivoreActionFactory&) = delete;
	CarnivoreActionFactory(CarnivoreActionFactory&&) = delete;
	CarnivoreActionFactory& operator=(CarnivoreActionFactory&&) = delete;

	static CarnivoreActionFactory& getInstance();

	CarnivoreHunting produceEatingAction(Carnivore* const owner, Simulation* const simulation);

private:
	CarnivoreActionFactory() = default;

};


#endif //ARTIFICIAL_LIFE_CARNIVOREACTIONFACTORY_H
