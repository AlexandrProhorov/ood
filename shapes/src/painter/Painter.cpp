#include "painter/Painter.h"

namespace painter
{

void Painter::DrawShapeContainer(const draft::ShapesContainer& cont, canvas::ICanvasSharedPtr& canvas) const
{
	canvas->DrawShapes(cont);
}

} // namespace painter
