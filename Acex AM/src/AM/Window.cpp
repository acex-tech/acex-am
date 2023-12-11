# include <AM/Window.hpp>
# include <AM/System.hpp>
# include <iostream>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{

	AM::Application& system = getSystem();

	switch (message) {
	
	case WM_CLOSE:
		
		return DefWindowProc(hwnd, message, wParam, lParam);

	case WM_DESTROY:
	
		system.removeWindow(hwnd);

		PostQuitMessage(0);
		break;
	
	default:
		
		return DefWindowProc(hwnd, message, wParam, lParam);
	
	}

	return 0;

}

HWND AM::Window::getHWND()
{

	return hwnd;

}

AM::Window::Window(Application* system, LPCTSTR title, std::array<int, 2> top, std::array<int, 2> size)
{

	WNDCLASSEX wcex;

	ZeroMemory((LPVOID)&wcex, sizeof(WNDCLASSEX));

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = 0;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = system->hInstance;
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = title;
	wcex.hIconSm = NULL;
	RegisterClassEx(&wcex);

	hwnd = CreateWindowEx(0, wcex.lpszClassName, title, WS_OVERLAPPEDWINDOW,
		top[0], top[1],
		size[0], size[1],
		NULL, NULL, system->hInstance, NULL);

	ShowWindow(hwnd, SW_SHOW);

}

AM::Window::~Window()
{

	CloseWindow(hwnd);

}
