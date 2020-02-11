/* Vector2D.h

An attempt to re-create Microsoft.Xna.Framework.Vector2 from C# in C++

Copyright (C) 2018 Lord Wolfenstein

*/
#pragma once
#ifndef LORD_WOLFENSTEIN_MICROSOFT_XNA_VECTOR_2D
#define LORD_WOLFENSTEIN_MICROSOFT_XNA_VECTOR_2D

//#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <SDL.h>
//#include <cmath>

//#define INT64_MAX 9223372036854775807
//#define INT64_MAX LLONG_MAX

class Vector2D
{
private:
protected:
    //const double PI = 3.14159265358979323846;
public:
    static const double PI;
    double x;
    double y;

    // For lazy printing
    friend std::ostream& operator<<(std::ostream& os, Vector2D vector2D);

    // Returns the angle between two vectors
    static double Angle( Vector2D V1, Vector2D V2);

    // Initiates both X and Y components to 0
    Vector2D(void);
    Vector2D(int x, int y);
    Vector2D(int x, double y);
    Vector2D(double x, int y);
    Vector2D(double x, double y);
    Vector2D(const Vector2D &vector2D);
    Vector2D(const SDL_Point &point);

    // Sets the vector to the values
    void Set(double x, double y);

    // Returns the length of the vector
    double Length(void);

    // Sets the length and preserves angle
    void SetLength(double length);

    // Returns the length difference between the vectors
    double Length(Vector2D vector2D);

    // Returns the distance between the vectors
    double Distance(Vector2D vector2D);

    // Returns the vector from this to vector2D
    Vector2D To(Vector2D vector2D);

    // Returns unit vector of direction from this to vector2D
    Vector2D Direction(Vector2D vector2D);

    // Return the unit vector of the vector
    Vector2D Unit(void);

    // Normalizes the vector to its unit vector
    void Normalize(void);

    // Returns angle in radians (-PI to PI)
    double Angle(void);

    // As Angle() but in degrees
    double Degrees(void);

    // Returns the angle between the vectors
    double Angle(Vector2D vector2D);

    // Rotates with the angle preserving the magnitude
    // angle: radians I assume...
    void Rotate(double angle);

    // Sets the given angle preserving the magnitude
    void Angle(double angle);

    // A.K.A. Scalar product
    double Dot(Vector2D vector2D);

    // Determinant
    double Det(Vector2D vector2D);

    // Operator overloading.

    Vector2D& operator=(Vector2D vector2D);
    // Adds two vectors
    Vector2D operator+(Vector2D vector2D);
    // Adds one vector to the other
    Vector2D& operator+=(Vector2D vector2D);
    // Adds a value to the the length of the vector
    Vector2D operator+(double scalar);
    // Adds a value to the the length of the vector
    Vector2D& operator+=(double scalar);
    // Subtracts two vectors
    Vector2D operator-(Vector2D vector2D);
    // Subtracts one vector from the other
    Vector2D& operator-=(Vector2D vector2D);
    // Substrates a scalar value from a vector
    Vector2D operator-(double scalar);
    // Substrates a scalar value from a vector
    Vector2D& operator-=(double scalar);
    // returns the negative vector
    Vector2D operator-(void);
    // Multiplies the length of the vector by a scalar
    Vector2D operator*(double scalar);
    // Multiplies the length of the vector by a scalar
    Vector2D& operator*=(double scalar);
    // This one makes no sense mathematically but is usefull in game programming.
    Vector2D operator*(Vector2D vector2D);
    // Divide the length of the vector by a scalar (Divide by 0 on your own risk)
    Vector2D operator/(double scalar);
    // Divide the length of the vector by a scalar (Divide by 0 on your own risk)
    Vector2D& operator/=(double scalar);
    // Are the vectors equal
    bool operator==(Vector2D vector2D);
    // Are the vectors not equal
    bool operator!=(Vector2D vector2D);
    // Compares the length of the vectors
    bool operator<(Vector2D vector2D);
    // Compares the length of the vectors
    bool operator>(Vector2D vector2D);
    // Is this the same vexctor? Beeing of exact equal length do not count.
    bool Equals(const Vector2D &vector2D);
    // Return the sum of a vector of Vector2D:S with float error corrections.
    // See: https://en.wikipedia.org/wiki/Kahan_summation_algorithm#Further_enhancements
    static Vector2D Sum(std::vector<Vector2D> vectors);

    // This does nothing
    virtual ~Vector2D(void);
};

#endif
