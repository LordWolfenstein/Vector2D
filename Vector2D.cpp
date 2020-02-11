/* Vector2D.cpp

An attempt to re-create Microsoft.Xna.Framework.Vector2 from C# in C++

Copyright (C) 2018 Lord Wolfenstein

*/

//#include <sstream>
#include <cmath>
#include "Vector2D.h"

std::ostream& operator<<(std::ostream& os, Vector2D vector2D)
{
    os << "X = " << vector2D.x << ", Y = " << vector2D.y << ", length = " << vector2D.Length();
    return os;
}

const double Vector2D::PI = 3.14159265358979323846;

double Vector2D::Angle(Vector2D V1, Vector2D V2)
{
    return V1.Angle(V2);
}

Vector2D::Vector2D(void)
{
    x = 0;
    y = 0;
}

Vector2D::Vector2D(int x, int y)
{
    this->x = (double)x;
    this->y = (double)y;
}


Vector2D::Vector2D(int x, double y)
{
    this->x = (double)x;
    this->y = y;
}

Vector2D::Vector2D(double x, int y)
{
    this->x = x;
    this->y = (double)y;
}

Vector2D::Vector2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

Vector2D::Vector2D(const Vector2D &vector2D)
{
    x = vector2D.x;
    y = vector2D.y;
}

Vector2D::Vector2D(const SDL_Point &point)
{
    x = point.x;
    y = point.y;
}


Vector2D::~Vector2D(void)
{

}

void Vector2D::Set(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Vector2D::Length(void)
{
    return std::sqrt(x*x + y*y);
}

void Vector2D::SetLength(double length)
{
    double angle = Angle();
    x = length * std::cos(angle);
    y = length * std::sin(angle);
}

double Vector2D::Length(Vector2D vector2D)
{
    return std::abs(Length() - Length());
}


double Vector2D::Distance(Vector2D vector2D)
{
    double X = x - vector2D.x;
    double Y = y - vector2D.y;
    return std::sqrt(X*X + Y*Y);
}

Vector2D Vector2D::To(Vector2D vector2D)
{
    return vector2D - *this;
}

Vector2D Vector2D::Direction(Vector2D vector2D)
{
    return To(vector2D).Unit();
}

Vector2D Vector2D::Unit(void)
{
    double length = Length();
    return length != 0 ? Vector2D(x / length, y / length) : Vector2D(0, 0); // if Length()==0 then return a zero vector
}

void Vector2D::Normalize(void)
{
    double length = Length();
    if (length != 0)
    {
        x /= length;
        y /= length;
    }
}

double Vector2D::Angle(void)
{
    return std::atan2(y, x);
}

double Vector2D::Degrees(void)
{
    return Angle() * 180 / PI;
}

double Vector2D::Angle(Vector2D vector2D)
{
    return std::atan2(Det(vector2D), Dot(vector2D));
}

void Vector2D::Angle(double angle)
{
    double length = Length();
    x = length * std::cos(angle);
    y = length * std::sin(angle);
}

void Vector2D::Rotate(double angle)
{
    double length = Length();
    double oldAngle = Angle();
    x = length * std::cos(oldAngle + angle);
    y = length * std::sin(oldAngle + angle);
}

double Vector2D::Dot(Vector2D vector2D)
{
    return x*vector2D.x + y*vector2D.y;
}


double Vector2D::Det(Vector2D vector2D)
{
    return x*vector2D.y - y*vector2D.x;
}

Vector2D& Vector2D::operator=(Vector2D vector2D)
{
    x = vector2D.x;
    y = vector2D.y;

    return *this;
}

Vector2D Vector2D::operator+(Vector2D vector2D)
{
    return Vector2D(x + vector2D.x, y + vector2D.y);
}

Vector2D& Vector2D::operator+=(Vector2D vector2D)
{
    x += vector2D.x;
    y += vector2D.y;
    return *this;
}

Vector2D Vector2D::operator+(double scalar)
{
    double length = Length() + scalar;
    double angle = Angle();
    return Vector2D(length * std::cos(angle), length * std::sin(angle));
}

Vector2D& Vector2D::operator+=(double scalar)
{
    double length = Length() + scalar;
    double angle = Angle();
    x = length * std::cos(angle);
    y = length * std::sin(angle);
    return *this;
}

Vector2D Vector2D::operator-(Vector2D vector2D)
{
    return Vector2D(x - vector2D.x, y - vector2D.y);
}


Vector2D& Vector2D::operator-=(Vector2D vector2D)
{
    x -= vector2D.x;
    y -= vector2D.y;
    return *this;
}

Vector2D Vector2D::operator-(double scalar)
{
    double length = Length() - scalar;
    double angle = Angle();
    return Vector2D(length * std::cos(angle), length * std::sin(angle));
}

Vector2D& Vector2D::operator-=(double scalar)
{
    double length = Length() - scalar;
    double angle = Angle();
    x = length * std::cos(angle);
    y = length * std::sin(angle);
    return *this;
}

Vector2D Vector2D::operator-(void)
{
    return Vector2D(-x, -y);
}

Vector2D Vector2D::operator*(double scalar)
{
    double length = Length() * scalar;
    double angle = Angle();
    return Vector2D(length * std::cos(angle), length * std::sin(angle));
}

Vector2D& Vector2D::operator*=(double scalar)
{
    double length = Length() * scalar;
    double angle = Angle();
    x = length * std::cos(angle);
    y = length * std::sin(angle);
    return *this;
}

Vector2D Vector2D::operator*(Vector2D vector2D)
{
    return Vector2D(x * vector2D.x, y * vector2D.y);
}

Vector2D Vector2D::operator/(double scalar)
{
    double length = Length() / scalar;
    double angle = Angle();
    return Vector2D(length * std::cos(angle), length * std::sin(angle));
}

Vector2D& Vector2D::operator/=(double scalar)
{
    double length = Length() / scalar;
    double angle = Angle();
    x = length * std::cos(angle);
    y = length * std::sin(angle);
    return *this;
}

bool Vector2D::operator==(Vector2D vector2D)
{
    return x == vector2D.x && y == vector2D.y;
}

bool Vector2D::operator!=(Vector2D vector2D)
{
    return x != vector2D.x || y != vector2D.y;
}

bool Vector2D::operator<(Vector2D vector2D)
{
    return Length() < vector2D.Length();
}

bool Vector2D::operator>(Vector2D vector2D)
{
    return Length() > vector2D.Length();
}

bool Vector2D::Equals(const Vector2D &vector2D)
{
    return this == &vector2D;
}

Vector2D Vector2D::Sum(std::vector<Vector2D> vectors)
{
    Vector2D sum = vectors[0];
    Vector2D c;

    for(int i = 1; i < vectors.size(); i++)
    {
        Vector2D t = sum + vectors[i];

        if(std::abs(sum.x) >= std::abs(vectors[i].x))
            c.x += (sum.x - t.x) + vectors[i].x;
        else
            c.x += (vectors[i].x - t.x) + sum.x;

        if(std::abs(sum.y) >= std::abs(vectors[i].y))
            c.y += (sum.y - t.y) + vectors[i].y;
        else
            c.y += (vectors[i].y - t.y) + sum.y;
    }

    return sum + c;
}
