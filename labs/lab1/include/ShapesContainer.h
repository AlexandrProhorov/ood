#ifndef SHAPESCONTAINER_H
#define SHAPESCONTAINER_H

#include <iostream>
#include <vector>

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
	bool ReadCircle(std::istream& input);
	bool ReadTriangle(std::istream& input);
	bool ReadRectangle(std::istream& input);

	std::vector<ShapeType> m_shapes;
};

#endif
