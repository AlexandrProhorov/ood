#ifndef SHAPESCONTAINER_H
#define SHAPESCONTAINER_H

#include <iostream>
#include <memory>
#include <vector>

#include "shapes/Shape.h"

namespace draft
{

constexpr auto STOP_READ_SHAPES_WORD = "stop";

class ShapesContainer
{
public:
	using Container = std::vector<IDrawableSharedPtr>;
	using ConstIterator = Container::const_iterator;

	void PrintShapesInfo(std::ostream& os);
	void ReadShapes(std::istream& input);

	ConstIterator begin() const;
	ConstIterator end() const;

private:
	bool ReadCircle(std::istream& input);
	bool ReadTriangle(std::istream& input);
	bool ReadRectangle(std::istream& input);

	Container m_shapes;
};

} // namespace draft

#endif