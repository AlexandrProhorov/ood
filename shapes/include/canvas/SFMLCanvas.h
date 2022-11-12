#pragma once

#include "ICanvas.h"

#include <SFML/Graphics.hpp>

namespace canvas
{

class SFMLCanvas final : public ICanvas
{
public:
	SFMLCanvas(sf::RenderWindow& sfmlRW);

	void DrawShapes(const draft::ShapesContainer& shapes) final;

private:
	sf::RenderWindow& m_renderer;
};

} // namespace canvas
