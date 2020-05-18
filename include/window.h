#pragma once

#include <SDL2/SDL.h>
#include <property.h>
#include <size.h>
#include <widget.h>

#include <atomic>
#include <string>

namespace Ui {
	class Window
	{
	public:
		Window(char* name, int w, int h);
		~Window();
		void show();

		Property<std::string> title;
		Property<Size> size;
		bool open;
		int event(SDL_Event *e);
		void setChild(Widget *w);

	private:
		SDL_Window* win = nullptr;
		SDL_Surface* sfc = nullptr;
		Widget *child = nullptr;
	};
} // namespace Ui
