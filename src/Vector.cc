/**
 * Vector - version in 2D: a geometric object that has magnitude and direction.
 *
 * Vector is applicable in spherical coordinate system. Primal dimensions: [-1, 1] x [1, 1]
 * For example, y = 1.5 in fact is equal to y = -0.5
 */

#include <include/ALife/Vector.h>
#include <string>
#include <cmath>
#include <iomanip>

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

Vector Vector::operator+(const Vector& other) const
{
	return {other.getX() + x_, other.getY() + y_};
}

Vector Vector::operator-(const Vector& other) const
{
	return {x_ - other.getX(), y_ - other.getY()};
}

Vector Vector::operator-() const
{
	return {-x_, -y_};
}

Vector Vector::operator*(double scalar) const
{
	return {scalar * x_, scalar * y_};
}

Vector& Vector::operator+=(const Vector& other)
{
	x_ = wrapCoordinateAround(x_ + other.getX());
	y_ = wrapCoordinateAround(y_ + other.getY());

	return *this;
}

Vector& Vector::operator-=(const Vector& other)
{
	x_ = wrapCoordinateAround(x_ - other.getX());
	y_ = wrapCoordinateAround(y_ - other.getY());

	return *this;
}

Vector& Vector::operator*=(double scalar)
{
	x_ = wrapCoordinateAround(scalar * x_);
	y_ = wrapCoordinateAround(scalar * y_);

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& vector)
{

	return os << std::showpoint << "( "  	<< std::setw(8) << std::setprecision(3) << vector.getX() << ", "
											<< std::setw(8) << std::setprecision(3) << vector.getY() << " )";
}

bool Vector::operator==(const Vector& other) const
{
	return (x_ == other.getX() and y_ == other.getY());
}

bool Vector::operator!=(const Vector& other) const
{
	return (x_ != other.getX() or y_ != other.getY());
}

double Vector::getLength() const
{
	return sqrt(x_*x_ + y_*y_);
}

Vector Vector::getShortestVectorBetweenPositions(const Vector& first, const Vector& second)
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

Vector Vector::getUnitVector() const
{
	return *this * (1.0/(this->getLength()));
}
