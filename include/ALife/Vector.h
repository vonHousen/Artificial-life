#ifndef ARTIFICIAL_LIFE_VECTOR_H
#define ARTIFICIAL_LIFE_VECTOR_H

#include <iostream>

/**
 * Vector - version in 2D: a geometric object that has magnitude and direction.
 *
 * Vector is applicable in spherical coordinate system. Primal dimensions: [-1, 1] x [1, 1].
 * For example, y = 1.5 in fact is equal to y = -0.5.
 */


class Vector
{
public:

	/**
	 * Default constructor creating Vector: [0.0 0.0].
	 */
	Vector();

	/**
	 * A constructor.
	 * @param x coordinate,
	 * @param y coordinate,
	 */
	Vector(double x, double y);

	double getX() const;														///< Getter for x coordinate.
	double getY() const;														///< Getter for y coordinate.
	void setX(double x);														///< Setter for x coordinate.
	void setY(double y);														///< Setter for y coordinate.

	/**
	 * Getter for shortest length of family of Vectors.
	 * @return length of a Vector.
	 */
	double getLength() const;

	/**
	 * Getter for unit Vector of the same direction as this one.
	 * @return Unit vector.
	 */
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

	friend std::ostream& operator<<(std::ostream& os, const Vector& vector);	///< Befriended for elegant printing.

private:

	/**
	 * Wraps coordinate so it can properly represent spherical coordinate system.
	 * For example x=3.5 in fact is equal to x=0.5.
	 * @param value - coordinate value.
	 * @return wrapped value.
	 */
	double wrapCoordinateAround(double value) const;

	double x_;																	///< x coordinate
	double y_;																	///< y coordinate
};


/**
 * Getter for the shortest Vector directing from one position to the other one.
 * @param first - Vector of a position from which is calculated resulting Vector.
 * @param second - Vector of a position to which is calculated resulting Vector.
 * @return shortest Vector between two positions.
 */
Vector getShortestVectorBetweenPositions(const Vector& first, const Vector& second);	// TODO make it local method



#endif //ARTIFICIAL_LIFE_VECTOR_H
