#pragma once

#include <memory>

namespace painter
{

class IPainter;

using IPainterRawPtr = IPainter*;
using IPainterPtr = std::unique_ptr<IPainter>;
using IPainterSharedPtr = std::shared_ptr<IPainter>;

} // namespace painter
