/*
 * Vector
 */

#ifndef ARTIFICIAL_LIFE_VECTOR_H
#define ARTIFICIAL_LIFE_VECTOR_H

#include <iostream>


class Vector
{

public:
	explicit Vector();
	Vector(float x, float y);

	float getX() const;
	float getY() const;
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
	float x_;
	float y_;
};


#endif //ARTIFICIAL_LIFE_VECTOR_H
