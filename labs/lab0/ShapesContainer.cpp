#include "include.h"
#include "ShapesContainer.h"
#include <optional>


using ShapeType = ShapesContainer::ShapeType;
inline static const std::map<std::string, ShapeType> String_To_Shape =
{
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
				if (shapeTypeStr == _shapeTypeStr)
				{
					shapeType = _shapeType;
					break;
				}
			}
		}
		ReadCircle(iss);
	}
}



bool ShapesContainer::ReadCircle(std::istream& input)
{
	double posX, posY, radius;
	if (input >> posX >> posY >> radius)
	{
		std::make_shared<Circle>(posX, posY, radius);
		std::cout << "Perimeter: " << 6.28 * radius << std::endl;
		return true;
	}
	return false;
}