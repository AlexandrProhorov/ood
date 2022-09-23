#ifndef SHAPESCONTAINER_H
#define SHAPESCONTAINER_H

#include <iostream>
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

private:
	using ShapePtrType = std::shared_ptr<IShape>;

	bool ReadCircle(std::istream& input);
	//bool ReadTriangle(std::istream& input);
	bool ReadRectangle(std::istream& input);

	std::vector<ShapePtrType> m_shapes;
};

#endif
