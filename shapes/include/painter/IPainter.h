#pragma once

#include "IPainter_fwd.h"

#include "draft/ShapesContainer.h"
#include "canvas/ICanvas.h"

namespace painter
{

class IPainter
{
public:
	virtual void DrawShapeContainer(const draft::ShapesContainer& cont, canvas::ICanvasSharedPtr& canvas) const = 0;

	virtual ~IPainter() = default;
};

} // namespace painter
