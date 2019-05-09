/*
 * Vector - version in 2D: a geometric object that has magnitude and direction
 */

#include "Vector.h"
#include <string>
#include <cmath>

Vector::Vector(double x, double y)
{
	x_ = wrapCoordinateAround(x);
	y_ = wrapCoordinateAround(y);
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
	x_ = wrapCoordinateAround(x);
}

void Vector::setY(double y)
{
	y_ = wrapCoordinateAround(y);
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

double Vector::getLength() const
{
	return sqrt(x_*x_ + y_*y_);
}

Vector getShortestVectorBetweenPositions(const Vector &first, const Vector &second)
{
	double dx_natural, dx_symmetric, dy_natural, dy_symmetric, dx_nearest, dy_nearest;

	dx_natural = 	second.getX() - first.getX();
	dx_symmetric = 	second.getX() - first.getX() - 2.0 ;
	dy_natural = 	second.getY() - first.getY();
	dy_symmetric = 	second.getY() - first.getY() - 2.0 ;

	dx_nearest = fabs(dx_natural) < fabs(dx_symmetric) ? dx_natural : dx_symmetric;
	dy_nearest = fabs(dy_natural) < fabs(dy_symmetric) ? dy_natural : dy_symmetric;

	return {dx_nearest, dy_nearest};
}

double Vector::wrapCoordinateAround(double value) const
{
	double result = fmod(value, 2);
    if(result > 1) result = result - 2;
    else if(result < -1) result = result + 2;
    return result;
}