#pragma once

#include "ICanvas_fwd.h"
#include "ShapesContainer.h"

namespace canvas
{

class ICanvas
{
public:
	virtual void DrawShapes(const ShapesContainer& shapes) = 0;

	virtual ~ICanvas() = default;
};

} // namespace canvas
