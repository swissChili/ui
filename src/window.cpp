#include <SDL2/SDL.h>
#include <painter.h>
#include <stdexcept>
#include <functional>
#include <window.h>

namespace Ui
{
	Window::Window(char *name, int w, int h) : title(name), size({w, h}), open(true)
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::runtime_error("SDL_Init failed");
		}
	}

	int windowEvent(void *win, SDL_Event *e)
	{
		return ((Window *)win)->event(e);
	}

	void Window::setChild(Widget *w)
	{
		child = w;
	}

	Window::~Window()
	{
		if (win)
			SDL_DestroyWindow(win);
	}

	void Window::show()
	{
		win = SDL_CreateWindow(title.get().c_str(), SDL_WINDOWPOS_UNDEFINED,
							   SDL_WINDOWPOS_UNDEFINED, size.get().w, size.get().h,
							   SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE |
								   SDL_WINDOW_OPENGL);
		sfc = SDL_GetWindowSurface(win);

		SDL_Event e;
		Painter p{sfc};
		unsigned char i = 0;
		SDL_SetEventFilter(windowEvent, nullptr);
		int w, h;

		while (open)
		{
			SDL_GetWindowSize(win, &w, &h);
			size = Size{w, h};

			while (SDL_PollEvent(&e))
			{
				switch (e.type)
				{
				case SDL_QUIT:
					open = false;
					break;
				case SDL_WINDOWEVENT:
					switch (e.window.event)
					{
					case SDL_WINDOWEVENT_RESIZED:
						sfc = SDL_GetWindowSurface(win);
						p.setSurface(sfc);
						break;
					}
				}
			}

			if (child)
			{
				child->build(p, 0, 0, size.get());
			}

			SDL_UpdateWindowSurface(win);
			SDL_Delay(10);
		}
	}

	int Window::event(SDL_Event *e)
	{
		return 1;
	}
} // namespace Ui
