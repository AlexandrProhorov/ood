#include "painter/Painter.h"

namespace painter
{

void Painter::DrawShapeContainer(const ShapesContainer& cont, canvas::ICanvasSharedPtr& canvas) const
{
	canvas->DrawShapes(cont);
}

} // namespace painter
