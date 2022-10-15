#include "include/pch.h"
#include "include/ShapesContainer.h"
#include "Painter.cpp"
#include <SFML/Graphics.hpp>

//using namespace sf;

int main()
{
	 //todo class painter с методом drawshapecontainer(const shapescontainer&, sf::window&)
	 
	ShapesContainer shapeContainer;
	try
	{
		sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
		ShapesContainer container = ShapesContainer();
		Painter paint = Painter();
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			container.ReadShapes(std::cin);
			window.clear();
			paint.DrawShapeContainer(container, window);
			window.display();
		}
		container.PrintShapesInfo(std::cout);
	}
	catch (const std::exception& _)
	{
		std::cout << "a";
		return 1;
	}

	return 0;
}
