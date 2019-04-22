/*
 * Vector - version in 2D: a geometric object that has magnitude and direction
 */

#include "Vector.h"

Vector::Vector(float x, float y) : x_(x), y_(y) {}

Vector::Vector() : Vector(0.0, 0.0) {}