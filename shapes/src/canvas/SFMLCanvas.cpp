#include "canvas/SFMLCanvas.h"

namespace canvas
{

SFMLCanvas::SFMLCanvas(sf::RenderWindow& sfmlRW)
	: m_renderer(sfmlRW)
{
}

void SFMLCanvas::DrawShapes(const draft::ShapesContainer& shapes)
{
	while (m_renderer.isOpen())
	{
		sf::Event event;
		while (m_renderer.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_renderer.close();
			}
		}

		//TODO: 0xFFFFFF -> 0xFFFFFFFF так как иначе альфа канал неправильно работает
		m_renderer.clear(sf::Color{255, 255, 0});

		for (const auto& shape : shapes)
		{
			shape->Draw(m_renderer);
		}

		m_renderer.display();
	}
}

} // namespace canvas
