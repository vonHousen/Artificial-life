/*
 * Needs represents all organism's physical and psychological needs. It implicitly impacts organism's actions.
 */

#ifndef ARTIFICIAL_LIFE_NEEDS_H
#define ARTIFICIAL_LIFE_NEEDS_H

class Organism;

class Needs final
{
public:
	explicit Needs(Organism* owner);

	void update();									//flow of the information upside down

private:
	enum class LeadingDesire { EATING, REPRODUCTION, SLEEPING };
	LeadingDesire leadingDesire_;

	Organism* owner_;

	float hunger_;
	float tiredness_;
	float loneliness_;

	void notify() const; 							//notify owner when leading desire changes

};


#endif //ARTIFICIAL_LIFE_NEEDS_H