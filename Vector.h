/*
 * Vector - version in 2D: a geometric object that has magnitude and direction
 */

#ifndef ARTIFICIAL_LIFE_VECTOR_H
#define ARTIFICIAL_LIFE_VECTOR_H

#include <iostream>


class Vector
{
public:
	Vector();
	Vector(float x, float y);

	double getX() const;
	double getY() const;
	void setX(float x);
	void setY(float y);

	Vector operator+(const Vector& other) const;
	Vector operator-(const Vector& other) const;
	Vector operator-() const;
	Vector operator*(float f) const;
	Vector& operator+=(const Vector& other);
	Vector& operator-=(const Vector& other);
	Vector& operator*=(float f);

	friend std::ostream& operator<<(std::ostream& os, const Vector& vector);

private:
	double x_;
	double y_;
};


#endif //ARTIFICIAL_LIFE_VECTOR_H
