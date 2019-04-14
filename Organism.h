/*
 * Organism TODO
 */

#ifndef ARTIFICIAL_LIFE_ORGANISM_H
#define ARTIFICIAL_LIFE_ORGANISM_H


class Organism
{
public:
	void update(float dt); //INFO (KP): will call bhv.act(this, simulation)
	void changeBehavior(const Behavior&); //INFO (KP): called by needs

	bool isAlive() const;
private:
	float health_;
	float timeAlive_;
	Genotype genes_;
	Vector position_;
	Vector velocity_;
	Vector acceleration_;
	Needs needs_;
	Behavior behavior_;
	std::shared_ptr<Simulation> simulation_;
};


#endif //ARTIFICIAL_LIFE_ORGANISM_H
