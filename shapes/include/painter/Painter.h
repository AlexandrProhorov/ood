#pragma once

#include "IPainter.h"

namespace painter
{

class Painter : public IPainter
{
public:
	void DrawShapeContainer(const ShapesContainer& cont, canvas::ICanvasSharedPtr& canvas) const override;
};

} // namespace painter
