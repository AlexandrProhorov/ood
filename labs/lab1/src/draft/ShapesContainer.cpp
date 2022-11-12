#include "../include/pch.h"

#include <memory>
#include <optional>

#include "../include/ShapesContainer.h"
#include "../include/include.h"
#include "../include/shapes/Shape.h"

namespace draft
{

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
		if (inputStr == "stop")
		{
			break;
		}

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
		if (shapeType.has_value() && *shapeType == ShapeType::Triangle)
		{
			ReadTriangle(iss);
		}
	}
}

bool ShapesContainer::ReadCircle(std::istream& input)
{
	float posX, posY, radius;
	if (input >> posX >> posY >> radius)
	{
		/*ShapePtrType circle = std::make_shared<Circle>(Point(posX, posY), 100, 100, radius);*/
		m_shapes.emplace_back(std::make_shared<Circle>(Point(posX, posY), 100, 100, radius));
		return true;
	}
	return false;
}

bool ShapesContainer::ReadRectangle(std::istream& input)
{
	float posX, posY, posX1, posY1;
	if (input >> posX >> posY >> posX1 >> posY1)
	{
		/*auto shape = std::make_shared<Rectangle>(Point(posX, posY), 100, 100, Point(posX1, posY1));
		m_shapes.emplace_back(shape);
		shape->GetHeight();
		shape->GetWidth();
		std::cout << '\n'
				  << comRectangle << '\n'
				  << comArea << shape->GetArea() << '\n'
				  << comPerimeter << shape->GetPerimeter() << '\n';*/
		return true;
	}
	return false;
}

bool ShapesContainer::ReadTriangle(std::istream& input)
{
	float posX, posY, posX1, posY1, posX2, posY2;
	if (input >> posX >> posY >> posX1 >> posY1 >> posX2 >> posY2)
	{
		/*auto shape = std::make_shared<Triangle>(Point(posX, posY), 100, 100, Point(posX1, posY1), Point(posX2, posY2));
		m_shapes.emplace_back(shape);
		shape->GetSide1();
		shape->GetSide2();
		shape->GetSide3();
		shape->GetHalfPerimeter();
		std::cout << '\n'
				  << comTriangle << '\n'
				  << comArea << shape->GetArea() << '\n'
				  << comPerimeter << shape->GetPerimeter() << '\n';*/
		return true;
	}
	return false;
}

} // namespace draft