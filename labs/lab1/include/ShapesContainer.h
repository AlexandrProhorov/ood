#ifndef SHAPESCONTAINER_H
#define SHAPESCONTAINER_H

#include <iostream>
#include <memory>
#include <vector>

#include "shapes/Shape.h"

class ShapesContainer
{
public:
	enum class ShapeType
	{
		Circle,
		Triangle,
		Rectangle,
	};

	void ReadShapes(std::istream& input);

	decltype(auto) begin() const
	{
		return m_shapes.begin();
	}

	decltype(auto) end() const
	{
		return m_shapes.end();
	}

	void PrintShapesInfo(std::ostream& os)
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

private:
	bool ReadCircle(std::istream& input);
	bool ReadTriangle(std::istream& input);
	bool ReadRectangle(std::istream& input);	

	std::vector<IDrawableSharedPtr> m_shapes;
};

#endif