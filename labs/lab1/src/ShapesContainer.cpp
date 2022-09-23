#include "../include/pch.h"

#include <memory>
#include <optional>

#include "../include/ShapesContainer.h"

#include "../include/shapes/Shape.h"

using ShapeType = ShapesContainer::ShapeType;
const std::map<std::string, ShapeType> String_To_Shape = {
	{ "triangle", ShapeType::Triangle },
	{ "circle", ShapeType::Circle },
	{ "rectangle", ShapeType::Rectangle },
};

void ShapesContainer::ReadShapes(std::istream& input)
{
	std::string inputStr, shapeTypeStr;
	std::stringstream iss;
	std::optional<ShapeType> shapeType;
	while (std::getline(input, inputStr))
	{
		iss.str("");
		iss.clear();
		iss << inputStr;
		iss >> shapeTypeStr;
		shapeType.reset();
		for (const auto& [_shapeTypeStr, _shapeType] : String_To_Shape)
		{
			if (shapeTypeStr == _shapeTypeStr)
			{
				shapeType = _shapeType;
				break;
			}
		}
		if (shapeType.has_value() && *shapeType == ShapeType::Circle)
		{
			ReadCircle(iss);
		}
		if (shapeType.has_value() && *shapeType == ShapeType::Rectangle)
		{
			ReadRectangle(iss);
		}
	}
}

bool ShapesContainer::ReadCircle(std::istream& input)
{
	double posX, posY, radius;
	if (input >> posX >> posY >> radius)
	{
		auto shape = std::make_shared<Circle>(Point(posX, posY), 100, 100, radius);
		m_shapes.emplace_back(shape);
		std::cout << "Circle: " << '\n'
			      << "Area: " << shape->GetArea() << '\n'
				  << "Perimeter: " << shape->GetPerimeter() << '\n';
		return true;
	}
	return false;
}

bool ShapesContainer::ReadRectangle(std::istream& input)
{
	double posX, posY, posX1, posY1;
	if (input >> posX >> posY >> posX1 >> posY1)
	{
		auto shape = std::make_shared<Rectangle>(Point(posX, posY), 100, 100, Point(posX1, posY1));
		m_shapes.emplace_back(shape);
		shape->GetHeight();
		shape->GetWidth();
		std::cout << "Rectangle: " << '\n'
				  << "area: " << shape->GetArea() << '\n'
				  << "perimeter: " << shape->GetPerimeter() << '\n';
		return true;
	}
	return false;
}
