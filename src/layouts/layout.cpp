#include <layouts/layout.h>

namespace Ui
{
	void VLayout::build(Painter &p, int x, int y, Size size)
	{
		int numChildren = children.size();

		if (size.h == 0 || numChildren == 0)
			return;
		int sizeEach = size.h / numChildren;
		int currentY = y;

		for (auto *c : children)
		{
			c->build(p, x, currentY, Size{size.w, sizeEach});
			currentY += sizeEach;
		}
	}

	void VLayout::add(Widget *w)
	{
		children.push_back(w);
	}
} // namespace Ui
