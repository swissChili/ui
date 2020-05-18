#pragma once

namespace Ui
{
	struct Size
	{
		int w;
		int h;

		bool operator==(Size &other)
		{
			return w == other.w && h == other.h;
		}
	};
} // namespace Ui
