#ifndef SHAPE_H
#define SHAPE_H

#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>

using Color = uint32_t;

struct Point
{
	float Distance(const Point& other) const
	{
		return std::sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
	}

	bool operator==(const Point& other) const
	{
		return (x == other.x) && (y == other.y);
	}

	float x, y;
};

class IDrawable
{
public:
	virtual void Draw(sf::RenderWindow& window) const = 0;
	virtual ~IDrawable() = default;
};

class IShape : public IDrawable
{
public:
	virtual float GetPerimeter() const = 0;
	virtual float GetArea() const = 0;
	virtual Color GetOutlineColor() const = 0;
	virtual Point GetBasePoint() const = 0;
};

template <typename Base = IShape>
class ShapeImpl : public Base
{
public:
	float GetPerimeter() const override
	{
		return 0;
	}

	float GetArea() const override
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
	virtual float GetRadius() const = 0;
};

class Circle : public SolidShapeImpl<ICircle>
{
public:
	using MyBase = SolidShapeImpl<ICircle>;

	Circle(const Point& basePoint, const Color& outlineColor, const Color& fillColor, const float radius)
		: MyBase(basePoint, outlineColor, fillColor)
		, m_radius(radius)
	{
	}

	float GetPerimeter() const final
	{
		return 2 * M_PI * m_radius;
	}

	float GetArea() const final
	{
		return M_PI * m_radius * m_radius;
	}
	/*
	* todo class painter с методом drawshapecontainer(const T&, sf::window&)
	*/
	Point GetCenter() const final
	{
		return GetBasePoint();
	}

	float GetRadius() const final
	{
		return m_radius;
	}

	void Draw(sf::RenderWindow& window) const final
	{
		sf::CircleShape drawCircle{ GetRadius() };
		drawCircle.setFillColor(sf::Color{ GetFillColor() });
		drawCircle.setPosition(sf::Vector2f{ GetCenter().x, GetCenter().y });
		window.draw(drawCircle);
	}

protected:
	float m_radius;
};

class player
{
public:
	sf::CircleShape draw(int r)
	{
		sf::CircleShape circle;
		circle.setRadius(r);
		return circle;
	}
};

class IRectangle : public ISolidShape
{
public:
	virtual Point GetLeftTop() const = 0;
	virtual Point GetRightBottom() const = 0;
	virtual float GetWidth() const = 0;
	virtual float GetHeight() const = 0;
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

	virtual float GetWidth() const final
	{
		return m_secondPoint.x - GetBasePoint().x;
	}

	virtual float GetHeight() const final
	{
		return m_secondPoint.y - GetBasePoint().y;
	}

	float GetPerimeter() const final
	{
		return (GetWidth() + GetHeight()) * 2;
	}

	float GetArea() const final
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

class ITriangle : public ISolidShape
{
public:
	virtual Point GetVertex2() const = 0;
	virtual Point GetVertex3() const = 0;
	virtual float GetSide1() const = 0;
	virtual float GetSide2() const = 0;
	virtual float GetSide3() const = 0;
	virtual float GetHalfPerimeter() const = 0;
};

class Triangle : public SolidShapeImpl<ITriangle>
{
public:
	using MyBase = SolidShapeImpl<ITriangle>;

	Triangle(const Point& firstPoint, const Color& outlineColor, const Color& fillColor, const Point& secondPoint, const Point& thirdPoint)
		: MyBase(firstPoint, outlineColor, fillColor)
		, m_secondPoint(secondPoint)
		, m_thirdPoint(thirdPoint)
	{
	}

	Point GetVertex2() const final
	{
		return m_secondPoint;
	}

	Point GetVertex3() const final
	{
		return m_thirdPoint;
	}

	float GetSide1() const final
	{
		float footingPointpowf1 = std::powf(GetBasePoint().x - GetVertex2().x, 2);
		float footingPointpowf2 = std::powf(GetBasePoint().y - GetVertex2().y, 2);
		return std::sqrt(footingPointpowf1 + footingPointpowf2);
	}

	float GetSide2() const final
	{
		float footingPointpowf1 = std::powf(GetVertex2().x - GetVertex3().x, 2);
		float footingPointpowf2 = std::powf(GetVertex2().y - GetVertex3().y, 2);
		return std::sqrt(footingPointpowf1 + footingPointpowf2);
	}

	float GetSide3() const final
	{
		float footingPointpowf1 = std::powf(GetVertex3().x - GetBasePoint().x, 2);
		float footingPointpowf2 = std::powf(GetVertex3().y - GetBasePoint().y, 2);
		return std::sqrt(footingPointpowf1 + footingPointpowf2);
	}

	float GetPerimeter() const final
	{
		return GetSide1() + GetSide2() + GetSide3();
	}

	float GetHalfPerimeter() const final
	{
		return GetPerimeter() * 0.5;
	}

	float GetArea() const final
	{
		return std::sqrt(GetHalfPerimeter() * (GetHalfPerimeter() - GetSide1()) * (GetHalfPerimeter() - GetSide2()) * (GetHalfPerimeter() - GetSide3()));
	}

protected:
	Point m_secondPoint;
	Point m_thirdPoint;
};

#endif