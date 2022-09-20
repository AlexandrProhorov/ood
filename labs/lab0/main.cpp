#include <iostream>
#include "ShapesContainer.h"
#include "include.h"

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

