#ifndef SHAPE_H
#define SHAPE_H

#define _USE_MATH_DEFINES

#include <math.h>
#include <string>


struct Point
{
	double X, Y;
};


class Shape 
{
public:
	Shape(const Point& basePoint)
		: m_basePoint(basePoint)
	{
		
	}
	virtual double GetPerimeter() const = 0;
	virtual double GetArea() const = 0;

protected:
	Point m_basePoint;
};

class Circle : public Shape
{
public:
	Circle(const Point& basePoint, const double radius)
		: Shape(basePoint)
		, m_radius(radius)
	{

	}
	 double GetPerimeter() const final
	{
		return 2 * M_PI * m_radius;
	}
	double GetArea() const final
	{
		return M_PI * std::pow(m_radius, 2);
	}

protected:
	double m_radius;
}; 

class Rectangle : public Shape
{
public:
	Rectangle(const Point firstPoint, const Point secondPoint)
		: Shape(firstPoint)
		, m_secondPoint(secondPoint)
	{

	}
	virtual double GetWidth() const final
	{
		return m_secondPoint.X - m_firstPoint.X;
	}
	virtual double GetHeight() const final
	{
		return m_secondPoint.Y - m_firstPoint.Y;
	}
	double GetPerimeter() const final
	{
		return (GetWidth() + GetHeight()) * 2;
	}
	double GetArea() const final
	{
		return GetWidth() * GetHeight();
	}

protected:
	Point m_firstPoint;
	Point m_secondPoint;
};

class Triangle : public Rectangle
{
public:
    const int X2, Y2;
};

#endif
