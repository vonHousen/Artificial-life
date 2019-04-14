/*
 * Location of the Organism
 */

#ifndef ARTIFICIAL_LIFE_LOCATION_H
#define ARTIFICIAL_LIFE_LOCATION_H

#include <iostream>


class Location
{

public:
	explicit Location();
	Location(float v);								//KZ: what is that for?
	Location(float x, float y);

	float getX() const;
	float getY() const;
	void setX(float x);
	void setY(float y);

	Location operator+(const Location& other) const;
	Location operator-(const Location& other) const;
	Location operator-() const;
	Location operator*(float f) const;				//KP: or const float as an argument?
	Location& operator+=(const Location& other);
	Location& operator-=(const Location& other);
	Location& operator*=(float f); 					//KP: or const float as an argument?

	friend std::ostream& operator<<(std::ostream& os, const Location& Location);
private:
	float x_;										//not sure if float is the best type
	float y_;
};


#endif //ARTIFICIAL_LIFE_LOCATION_H
