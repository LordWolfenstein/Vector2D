/* Vector2D.cpp

An attempt to re-create Microsoft.Xna.Framework.Vector2 from C# in C++

Copyright (C) 2018 Lord Wolfenstein

*/

//#include <sstream>
#include <cmath>
#include "Vector2D.h"

// For lazy printing
std::ostream& operator<<(std::ostream& os, Vector2D vector2D)
{
    os << "X = " << vector2D.X << ", Y = " << vector2D.Y << ", length = " << vector2D.Length();
    return os;
}

// Returns the angle between two vectors
double Vector2D::Angle(Vector2D V1, Vector2D V2)
{
    return V1.Angle(V2);
}

// Initiates both X and Y components to 0
Vector2D::Vector2D(void)
{
    X = 0;
    Y = 0;
}

// Initiates the vector to the value
Vector2D::Vector2D(double x, double y)
{
    X = x;
    Y = y;
}

// Copy constructor
Vector2D::Vector2D(const Vector2D &vector2D)
{
    X = vector2D.X;
    Y = vector2D.Y;
}

// This does nothing
Vector2D::~Vector2D(void)
{

}

void Vector2D::Set(double x, double y)
{
    X = x;
    Y = y;
}

// Returns the length of the vector
double Vector2D::Length(void)
{
    return std::sqrt(X*X + Y*Y);
}

// Sets the length and preserves angle
void Vector2D::Length(double length)
{
    double angle = Angle();
    X = length * cos(angle);
    Y = length * sin(angle);
}

// Returns the length difference between the vectors
double Vector2D::Length(Vector2D vector2D)
{
    return abs(Length() - Length());
}

// Returns the distance between the vectors
double Vector2D::Distance(Vector2D vector2D)
{
    double x = X - vector2D.X;
    double y = Y - vector2D.Y;
    return std::sqrt(x*x + y*y);
}

// Return the unit vector of the vector
Vector2D Vector2D::Unit(void)
{
    double length = Length();
    return length != 0 ? Vector2D(X / length, Y / length) : Vector2D(0, 0); // if Length()==0 then return a zero vector
}

// Normalizes the vector to its unit vector
void Vector2D::Normalize(void)
{
    double length = Length();
    if (length != 0)
    {
        X /= length;
        Y /= length;
    }
}

// Returns angle in radians (-PI to PI)
double Vector2D::Angle(void)
{
    return std::atan2(Y, X);
}

// As Angle() but in degrees
double Vector2D::Degrees(void)
{
    return Angle() * 180 / PI;
}

// Returns the angle between the vectors
double Vector2D::Angle(Vector2D vector2D)
{
    return std::atan2(Det(vector2D), Dot(vector2D));
}

// Sets the given angle preserving the magnitude
void Vector2D::Angle(double angle)
{
    double length = Length();
    X = length * cos(angle);
    Y = length * sin(angle);
}

// Rotates with the angle preserving the magnitude
void Vector2D::Rotate(double angle)
{
    double length = Length();
    double oldAngle = Angle();
    X = length * cos(oldAngle + angle);
    Y = length * sin(oldAngle + angle);
}

// A.K.A. Scalar product
double Vector2D::Dot(Vector2D vector2D)
{
    return X*vector2D.X + Y*vector2D.Y;
}

// Determinant
double Vector2D::Det(Vector2D vector2D)
{
    return X*vector2D.Y - Y*vector2D.X;
}

// Operator overloading.

Vector2D& Vector2D::operator=(Vector2D vector2D)
{
    X = vector2D.X;
    Y = vector2D.Y;

    return *this;
}

// Adds two vectors
Vector2D Vector2D::operator+(Vector2D vector2D)
{
    return Vector2D(X + vector2D.X, Y + vector2D.Y);
}

// Adds one vector to the other
Vector2D& Vector2D::operator+=(Vector2D vector2D)
{
    X += vector2D.X;
    Y += vector2D.Y;
    return *this;
}

// Adds a value to the the length of the vector
Vector2D Vector2D::operator+(double scalar)
{
    double length = Length() + scalar;
    double angle = Angle();
    return Vector2D(length * cos(angle), length * sin(angle));
}

// Adds a value to the the length of the vector
Vector2D& Vector2D::operator+=(double scalar)
{
    double length = Length() + scalar;
    double angle = Angle();
    X = length * cos(angle);
    Y = length * sin(angle);
    return *this;
}

// Subtracts two vectors
Vector2D Vector2D::operator-(Vector2D vector2D)
{
    return Vector2D(X - vector2D.X, Y - vector2D.Y);
}

// Subtracts one vector from the other
Vector2D& Vector2D::operator-=(Vector2D vector2D)
{
    X -= vector2D.X;
    Y -= vector2D.Y;
    return *this;
}

// Substrates a scalar value from a vector
Vector2D Vector2D::operator-(double scalar)
{
    double length = Length() - scalar;
    double angle = Angle();
    return Vector2D(length * cos(angle), length * sin(angle));
}

// Substrates a scalar value from a vector
Vector2D& Vector2D::operator-=(double scalar)
{
    double length = Length() - scalar;
    double angle = Angle();
    X = length * cos(angle);
    Y = length * sin(angle);
    return *this;
}

// returns the negative vector
Vector2D Vector2D::operator-(void)
{
    return Vector2D(-X, -Y);
}

// Multiplies the length of the vector by a scalar
Vector2D Vector2D::operator*(double scalar)
{
    double length = Length() * scalar;
    double angle = Angle();
    return Vector2D(length * cos(angle), length * sin(angle));
}

// Multiplies the length of the vector by a scalar
Vector2D& Vector2D::operator*=(double scalar)
{
    double length = Length() * scalar;
    double angle = Angle();
    X = length * cos(angle);
    Y = length * sin(angle);
    return *this;
}

// Divide the length of the vector by a scalar (Divide by 0 on your own risk)
Vector2D Vector2D::operator/(double scalar)
{
    double length = Length() / scalar;
    double angle = Angle();
    return Vector2D(length * cos(angle), length * sin(angle));
}

// Divide the length of the vector by a scalar (Divide by 0 on your own risk)
Vector2D& Vector2D::operator/=(double scalar)
{
    double length = Length() / scalar;
    double angle = Angle();
    X = length * cos(angle);
    Y = length * sin(angle);
    return *this;
}

bool Vector2D::operator==(Vector2D &vector2D)
{
    return X == vector2D.X && Y == vector2D.Y;
}

bool Vector2D::operator!=(Vector2D &vector2D)
{
    return X != vector2D.X || Y != vector2D.Y;
}

// Compares the length of the vectors
bool Vector2D::operator<(Vector2D &vector2D)
{
    return Length() < vector2D.Length();
}

// Compares the length of the vectors
bool Vector2D::operator>(Vector2D &vector2D)
{
    return Length() > vector2D.Length();
}

bool Vector2D::Equals(const Vector2D &vector2D)
{
    return this == &vector2D;
}

// Return the sum of a vector of Vector2D:S with float error corrections.
// See: https://en.wikipedia.org/wiki/Kahan_summation_algorithm#Further_enhancements
Vector2D Vector2D::Sum(std::vector<Vector2D> vectors)
{
    Vector2D sum = vectors[0];
    Vector2D c;

    for(int i = 1; i < vectors.size(); i++)
    {
        Vector2D t = sum + vectors[i];

        if(std::abs(sum.X) >= std::abs(vectors[i].X))
            c.X += (sum.X - t.X) + vectors[i].X;
        else
            c.X += (vectors[i].X - t.X) + sum.X;

        if(std::abs(sum.Y) >= std::abs(vectors[i].Y))
            c.Y += (sum.Y - t.Y) + vectors[i].Y;
        else
            c.Y += (vectors[i].Y - t.Y) + sum.Y;
    }

    return sum + c;
}
