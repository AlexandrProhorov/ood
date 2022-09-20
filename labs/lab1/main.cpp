#include "include/pch.h"
#include "include/ShapesContainer.h"

int main()
{
	ShapesContainer shapeContainer;
	try
	{
		shapeContainer.ReadShapes(std::cin);
	}
	catch (const std::exception& e)
	{
		std::cout << "a";
		return 1;
	}
}
