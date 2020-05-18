#pragma once

#include <widget.h>

namespace Ui
{
	class Rectangle : public Widget
	{
	public:
		Rectangle(Color c);
		void build(Painter &p, int x, int y, Size size) override;

	private:
		Color color;
	};
} // namespace Ui
