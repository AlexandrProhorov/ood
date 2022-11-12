#include "pch.h"

#include "draft/ShapesContainer.h"
#include "canvas/SFMLCanvas.h"
#include "painter/Painter.h"


int main()
{
	draft::ShapesContainer shapeContainer;

	painter::Painter painter{};

	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
	canvas::ICanvasSharedPtr canvas = std::make_shared<canvas::SFMLCanvas>(window);

	try
	{
		shapeContainer.ReadShapes(std::cin);

		painter.DrawShapeContainer(shapeContainer, canvas);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	shapeContainer.PrintShapesInfo(std::cout);

	return 0;
}
