#include <SDL2/SDL.h>
#include <painter.h>

namespace Ui
{
	void Painter::drawRect(int x, int y, int w, int h, Color c)
	{
		SDL_Rect r;
		r.x = x;
		r.y = y;
		r.w = w;
		r.h = h;

		SDL_FillRect(sfc, &r, SDL_MapRGB(sfc->format, c.r, c.g, c.b));
	}

	void Painter::setSurface(SDL_Surface *s)
	{
		sfc = s;
	}
} // namespace Ui
