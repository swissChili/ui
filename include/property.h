#pragma once

#include <functional>
#include <list>

namespace Ui
{
	template <class T>
	class Property
	{
	public:
		Property(T val) : v(val)
		{
		}
		void operator=(T other)
		{
			if (v == other)
				return;
			v = other;
			updated();
		}

		T get()
		{
			return v;
		}

		void onUpdate(std::function<void(T)> fn)
		{
			handlers.push_back(fn);
		}

	private:
		void updated()
		{
			for (auto fn : handlers)
			{
				fn(v);
			}
		}
		T v;
		std::list<std::function<void(T)>> handlers;
	};
} // namespace Ui
