#include <widgets/common.h>

namespace Ui
{
	Rectangle::Rectangle(Color c)
		: color(c)
	{
	}

	void Rectangle::build(Painter &p, int x, int y, Size size)
	{
		p.drawRect(x, y, size.w, size.h, color);
	}

} // namespace Ui
