# pragma once
# include <Windows.h>
# include <AM/System.hpp>
# include <array>

namespace AM
{

	class Application;

	class Window
	{
		
	public:

		Window(AM::Application* system, LPCTSTR title, std::array<int, 2> top, std::array<int, 2> size);
		~Window();

		HWND getHWND();


	private:

		
		HWND hwnd;

		friend class AM::Application;

	};

}