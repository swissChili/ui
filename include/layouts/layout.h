#pragma once

#include <widget.h>
#include <list>

namespace Ui
{
	class VLayout : public Widget
	{
	public:
		void add(Widget *w);
		void build(Painter &p, int x, int y, Size size) override;

	private:
		std::list<Widget *> children;
	};
}