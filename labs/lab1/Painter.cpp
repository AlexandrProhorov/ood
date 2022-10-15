#include "include/ShapesContainer.h"
#include "include/shapes/Shape.h"
#include <SFML/Graphics.hpp>

#include <memory>

class IPainter 
{
public:
	virtual void DrawShapeContainer(const ShapesContainer& cont, sf::RenderWindow& window) const = 0;
	virtual ~IPainter() = default;
};

class Painter : public IPainter
{
public:
	void DrawShapeContainer(const ShapesContainer& cont, sf::RenderWindow& window) const final
	{
		for (auto& shape : cont)
		{
			shape->Draw(window);
		}
	}
};
