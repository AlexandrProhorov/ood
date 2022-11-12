#include "canvas/SFMLCanvas.h"

namespace canvas
{

SFMLCanvas::SFMLCanvas(sf::RenderWindow& sfmlRW)
	: m_renderer(sfmlRW)
{
}

void SFMLCanvas::DrawShapes(const ShapesContainer& shapes)
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

		//m_renderer.clear(backgroundColor);

		for (const auto& shape : shapes)
		{
			shape->Draw(m_renderer);
		}

		m_renderer.display();
	}
}

} // namespace canvas
