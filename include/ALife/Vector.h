/*
 * Vector - version in 2D: a geometric object that has magnitude and direction.
 *
 * Vector is applicable in spherical coordinate system. Primal dimensions: [-1, 1] x [1, 1]
 * For example, y = 1.5 in fact is equal to y = -0.5
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
	Vector getUnitVector() const;

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
	double wrapCoordinateAround(double value) const;

	double x_;
	double y_;
};


//returns the shortest vector pointing from one position to the other one
Vector getShortestVectorBetweenPositions(const Vector& first, const Vector& second);	// TODO make it local method



#endif //ARTIFICIAL_LIFE_VECTOR_H
