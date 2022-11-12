#include "../include/pch.h"

#include <memory>

#include "draft/ShapeTypes.h"
#include "draft/ShapesContainer.h"
#include "shapes/Shape.h"
#include "util/string_util.h"

namespace draft
{

void ShapesContainer::ReadShapes(std::istream& input)
{
	std::string inputStr;
	std::stringstream iss;

	draft::ShapeType shapeType{};
	using namespace draft;

	while (std::getline(input, inputStr))
	{
		if (string_util::IEqualStrings(inputStr, STOP_READ_SHAPES_WORD))
		{
			break;
		}

		iss.str("");
		iss.clear();

		iss << inputStr;
		iss >> shapeType;

		bool successRead = false;
		switch (shapeType)
		{ // TODO: реализовать считывание цвета в uint32_t в формате FFFFFFFF
		case draft::ShapeType::CIRCLE: {
			successRead = ReadCircle(iss);
		}
		case draft::ShapeType::TRIANGLE: {
			successRead = ReadRectangle(iss);
		}
		case draft::ShapeType::RECTANGLE: {
			successRead = ReadTriangle(iss);
		}
		case draft::ShapeType::UNKNOWN: { // TODO: Придумать, что делать, если пользователь ввёл неизвестный тип фигуры
			successRead = false;
		}
		}
	}
}

bool ShapesContainer::ReadCircle(std::istream& input)
{
	float posX, posY, radius;
	if (input >> posX >> posY >> radius)
	{
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
		return true;
	}
	return false;
}

bool ShapesContainer::ReadTriangle(std::istream& input)
{
	float posX, posY, posX1, posY1, posX2, posY2;
	if (input >> posX >> posY >> posX1 >> posY1 >> posX2 >> posY2)
	{

		return true;
	}
	return false;
}

using ConstIterator = ShapesContainer::ConstIterator;

ConstIterator ShapesContainer::begin() const
{
	return m_shapes.begin();
}

ConstIterator ShapesContainer::end() const
{
	return m_shapes.end();
}

void ShapesContainer::PrintShapesInfo(std::ostream& os)
{
	if (!std::ostream::sentry(os))
	{
		return;
	}

	for (auto& shape : m_shapes)
	{
		auto downcasted = std::dynamic_pointer_cast<IShape>(shape);
		if (downcasted != nullptr)
		{
			os << downcasted->GetArea();
		}
	}
}

} // namespace draft