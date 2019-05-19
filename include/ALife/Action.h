/**
 * Abstract class for all types of actions organism can perform driven by needs
 */

#ifndef ARTIFICIAL_LIFE_ACTION_H
#define ARTIFICIAL_LIFE_ACTION_H

class Organism;
class Simulation;
class Carnivore;
class Herbivore;


class Action
{
public:
	Action(Organism* const owner, Simulation* const simulation);
	Action(Carnivore* const owner, Simulation* const simulation);
	Action(Herbivore* const owner, Simulation* const simulation);

	virtual void act() = 0;

protected:
	Organism* const owner_;
	Simulation* const simulation_;
};


#endif //ARTIFICIAL_LIFE_ACTION_H
