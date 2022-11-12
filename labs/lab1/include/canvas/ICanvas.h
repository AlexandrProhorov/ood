#pragma once

#include "ICanvas_fwd.h"
#include "draft/ShapesContainer.h"

namespace canvas
{

class ICanvas
{
public:
	virtual void DrawShapes(const draft::ShapesContainer& shapes) = 0;

	virtual ~ICanvas() = default;
};

} // namespace canvas
