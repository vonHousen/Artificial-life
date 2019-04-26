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
	Vector(double x, double y);

	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	double getLength() const;
	Vector getVectorTo(const Vector& other) const;

	Vector operator+(const Vector& other) const;
	Vector operator-(const Vector& other) const;
	Vector operator-() const;
	Vector operator*(double scalar) const;
	Vector& operator+=(const Vector& other);
	Vector& operator-=(const Vector& other);
	Vector& operator*=(double scalar);
	bool operator==(const Vector& other) const;
	bool operator!=(const Vector& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Vector& vector);

private:
	double x_;
	double y_;
};


#endif //ARTIFICIAL_LIFE_VECTOR_H
