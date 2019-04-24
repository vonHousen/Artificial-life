/*
 * Vector - version in 2D: a geometric object that has magnitude and direction
 */

#include "Vector.h"
#include <string>

Vector::Vector(double x, double y)
{
	while(x > 1.0)
		x -= 2.0;

	while(x < -1.0)
		x += 2.0;

	while(y > 1.0)
		y -= 2.0;

	while(y < -1.0)
		y += 2.0;

	x_ = x;
	y_ = y;
}

Vector::Vector() : Vector(0.0, 0.0) {}

double Vector::getX() const
{
	return x_;
}

double Vector::getY() const
{
	return y_;
}

void Vector::setX(double x)
{
	if(x > 1.0)
		this->setX(x - 2.0);
	else if(x < -1.0)
		this->setX(x + 2.0);
	else
		x_ = x;
}

void Vector::setY(double y)
{
	if(y > 1.0)
		this->setY(y - 2.0);
	else if(y < -1.0)
		this->setY(y + 2.0);
	else
		y_ = y;
}

Vector Vector::operator+(const Vector &other) const
{
	return {other.getX() + x_, other.getY() + y_};
}

Vector Vector::operator-(const Vector &other) const
{
	return {other.getX() - x_, other.getY() - y_};
}

Vector Vector::operator-() const
{
	return {-x_, -y_};
}

Vector Vector::operator*(double scalar) const
{
	return {scalar * x_, scalar * y_};
}

Vector& Vector::operator+=(const Vector &other)
{
	x_ = other.getX() + x_;
	y_ = other.getY() + y_;

	while(x_ > 1.0)
		x_ -= 2.0;

	while(x_ < -1.0)
		x_ += 2.0;

	while(y_ > 1.0)
		y_ -= 2.0;

	while(y_ < -1.0)
		y_ += 2.0;

	return *this;
}

Vector& Vector::operator-=(const Vector &other)
{
	x_ = other.getX() - x_;
	y_ = other.getY() - y_;

	while(x_ > 1.0)
		x_ -= 2.0;

	while(x_ < -1.0)
		x_ += 2.0;

	while(y_ > 1.0)
		y_ -= 2.0;

	while(y_ < -1.0)
		y_ += 2.0;

	return *this;
}

Vector &Vector::operator*=(double scalar)
{
	x_ = scalar * x_;
	y_ = scalar * y_;

	while(x_ > 1.0)
		x_ -= 2.0;

	while(x_ < -1.0)
		x_ += 2.0;

	while(y_ > 1.0)
		y_ -= 2.0;

	while(y_ < -1.0)
		y_ += 2.0;

	return *this;
}

std::ostream &operator<<(std::ostream &os, const Vector &vector)
{
	if (vector.getX() < 0.0 and vector.getY() < 0.0)
		return os << "(" << vector.getX() << ", " << vector.getY() << ")";
	else if (vector.getX() > 0.0 and vector.getY() < 0.0)
		return os << "( " << vector.getX() << ", " << vector.getY() << ")";
	else if (vector.getX() < 0.0 and vector.getY() > 0.0)
		return os << "(" << vector.getX() << ",  " << vector.getY() << ")";
	else
		return os << "( " << vector.getX() << ",  " << vector.getY() << ")";
}

bool Vector::operator==(const Vector &other) const
{
	return (x_ == other.getX() and y_ == other.getY());
}

bool Vector::operator!=(const Vector &other) const
{
	return (x_ != other.getX() or y_ != other.getY());
}
