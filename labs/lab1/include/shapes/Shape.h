#ifndef SHAPE_H
#define SHAPE_H

#define _USE_MATH_DEFINES

#include <math.h>
#include <string>

using Color = uint32_t;

struct Point
{
	double Distance(const Point& other) const
	{
		return std::sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
	}

	bool operator==(const Point& other) const
	{
		return (x == other.x) && (y == other.y);
	}

	double x, y;
};

class IShape
{
public:
	virtual double GetPerimeter() const = 0;
	virtual double GetArea() const = 0;
	virtual Color GetOutlineColor() const = 0;
	virtual Point GetBasePoint() const = 0;

	virtual ~IShape() = default;
};

template <typename Base = IShape>
class ShapeImpl : public Base
{
public:
	double GetPerimeter() const override
	{
		return 0;
	}

	double GetArea() const override
	{
		return 0;
	}

	Point GetBasePoint() const final
	{
		return m_basePoint;
	}

	Color GetOutlineColor() const final
	{
		return m_outlineColor;
	}

protected:
	ShapeImpl(const Point& basePoint, const Color& outlineColor)
		: m_basePoint(basePoint)
		, m_outlineColor(outlineColor)
	{
	}

	Color m_outlineColor;
	Point m_basePoint;
};

class ISolidShape : public IShape
{
public:
	virtual Color GetFillColor() const = 0;
};

template <typename Base = ISolidShape>
class SolidShapeImpl : public ShapeImpl<Base>
{
public:
	using MyBase = ShapeImpl<Base>;

	Color GetFillColor() const final
	{
		return m_fillColor;
	}

protected:
	SolidShapeImpl(const Point& basePoint, const Color& outlineColor, const Color& fillColor)
		: MyBase(basePoint, outlineColor)
		, m_fillColor(fillColor)
	{
	}

	Color m_fillColor;
};

class ICircle : public ISolidShape
{
public:
	virtual Point GetCenter() const = 0;
	virtual double GetRadius() const = 0;
};

class Circle : public SolidShapeImpl<ICircle>
{
public:
	using MyBase = SolidShapeImpl<ICircle>;

	Circle(const Point& basePoint, const Color& outlineColor, const Color& fillColor, const double radius)
		: MyBase(basePoint, outlineColor, fillColor)
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

	Point GetCenter() const final
	{
		return GetBasePoint();
	}

	double GetRadius() const final
	{
		return m_radius;
	}

protected:
	double m_radius;
}; 

class IRectangle : public ISolidShape
{
public:
	virtual Point GetLeftTop() const = 0;
	virtual Point GetRightBottom() const = 0;
	virtual double GetWidth() const = 0;
	virtual double GetHeight() const = 0;
};

class Rectangle : public SolidShapeImpl<IRectangle>
{
public:
	using MyBase = SolidShapeImpl<IRectangle>;

	Rectangle(const Point& firstPoint, const Color& outlineColor, const Color& fillColor, const Point& secondPoint)
		: MyBase(firstPoint, outlineColor, fillColor)
		, m_secondPoint(secondPoint)
	{
		
	}
	
	virtual double GetWidth() const final
	{
		return m_secondPoint.x - GetBasePoint().x;
	}

	virtual double GetHeight() const final
	{
		return m_secondPoint.y - GetBasePoint().y;
	}

	double GetPerimeter() const final
	{
		return (GetWidth() + GetHeight()) * 2;
	}

	double GetArea() const final
	{
		return GetWidth() * GetHeight();
	}

	Point GetLeftTop() const final
	{
		return GetBasePoint();
	}

	Point GetRightBottom() const final
	{
		return m_secondPoint;
	}

protected:
	Point m_secondPoint;
};

//class Triangle : public Rectangle
//{
//public:
//    const int X2, Y2;
//};

#endif
