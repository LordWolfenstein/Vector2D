/* Vector2D.h 

An attempt to re-create Microsoft.Xna.Framework.Vector2 from C# in C++

Copyright (C) 2018 Lord Wolfenstein

*/

#ifndef LORD_WOLFENSTEIN_MICROSOFT_XNA_VECTOR_2D
#define LORD_WOLFENSTEIN_MICROSOFT_XNA_VECTOR_2D

//#define _USE_MATH_DEFINES
//#include <iostream>
//#include <cmath>

class Vector2D
{
private:
    const double PI = 3.14159265358979323846;
protected:
public:

    //friend std::ostream& operator<<(std::ostream& os, Vector2D vector2D);
    static double Angle( Vector2D V1, Vector2D V2);
    
    double X;
    double Y;
    Vector2D(void);
    Vector2D(double value);
    Vector2D(double x, double y);
    Vector2D(const Vector2D &vector2D);

    void Set(double x, double y);

    double Length(void);
    void Length(double length);
    double Length(Vector2D vector2D);
    double Distance(Vector2D vector2D);
    Vector2D Unit(void);
    void Normalize(void);
    double Angle(void);
    double Degrees(void);
    double Angle(Vector2D vector2D);
    void Rotate(double angle);
    void Angle(double angle);

    double Dot(Vector2D vector2D);
    double Det(Vector2D vector2D);

    Vector2D& operator=(Vector2D vector2D);

    Vector2D operator+(Vector2D vector2D);
    Vector2D& operator+=(Vector2D vector2D);
    Vector2D operator+(double scalar);
    Vector2D& operator+=(double scalar);

    Vector2D operator-(Vector2D vector2D);
    Vector2D& operator-=(Vector2D vector2D);
    Vector2D operator-(double scalar);
    Vector2D& operator-=(double scalar);
    Vector2D operator-(void);

    //Vector2D operator*(Vector2D vector2D);
    //Vector2D& operator*=(Vector2D vector2D);
    Vector2D operator*(double scalar);
    Vector2D& operator*=(double scalar);

    Vector2D operator/(double scalar);
    Vector2D& operator/=(double scalar);

    bool operator==(Vector2D &vector2D);
    bool operator!=(Vector2D &vector2D);
    bool operator<(Vector2D &vector2D);
    bool operator>(Vector2D &vector2D);

    bool Equals(const Vector2D &vector2D);
    //std::string ToString(void);

    ~Vector2D(void);
};

#endif