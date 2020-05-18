#pragma once

#include <color.h>

struct SDL_Surface;

namespace Ui
{
	class Painter
	{
	public:
		Painter(SDL_Surface *s) : sfc(s)
		{
		}

		void setSurface(SDL_Surface *s);

		void drawRect(int x, int y, int w, int h, Color c);

	private:
		SDL_Surface *sfc;
	};
} // namespace Ui
