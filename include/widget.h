#pragma once

#include <property.h>
#include <painter.h>
#include <size.h>

namespace Ui
{
	class Widget
	{
	public:
		Widget();
		virtual void build(Painter &p, int x, int y, Size size) = 0;

		Property<Size> minSize;
		Property<Size> maxSize;
	};
} // namespace Ui
