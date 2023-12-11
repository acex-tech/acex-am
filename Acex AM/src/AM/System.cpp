# include <AM/System.hpp>
# include <AM/Window.hpp>
# include <vector>

static AM::Application application;

int APIENTRY WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmpLine,
	INT       nCmdShow
)
{
	
	MSG message{};

	application = AM::Application{ hInstance };

	Main(application);

	while (true)
	{

		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{

			AM::Window& window = *application.getWindow(message.hwnd);

			if (message.message == WM_DESTROY)
			{

				application.removeWindow(message.hwnd);

			}

			TranslateMessage(&message);
			DispatchMessage(&message);

		}

		if (application.getWindows().size() == 0)
		{

			break;

		}

	}

	return 0;

}

AM::Application::Application()
	:hInstance{ NULL }
{
}

AM::Application::Application(HINSTANCE hInstance)
	:hInstance{ hInstance }
{
}

AM::Window& AM::Application::createWindow()
{

	std::shared_ptr<AM::Window> window = std::make_shared<AM::Window>(this, LPCTSTR(L"Title"), std::array<int, 2>{ 0, 0 }, std::array<int, 2>{ 1000, 900 });

	hwndWindows[window->getHWND()] = window;
	allWindows.push_back(window);

	return *window;

}

bool AM::Application::removeWindow(HWND hwnd)
{
	
	for (size_t i = 0; i < allWindows.size(); i++)
	{

		if (allWindows[i]->getHWND() == hwnd)
		{

			hwndWindows.erase(hwnd);
			allWindows.erase(allWindows.begin() + i);

			return true;

		}

	}

	return false;

}

std::shared_ptr<AM::Window> AM::Application::getWindow(HWND hwnd)
{
	
	return hwndWindows[hwnd];

}

std::vector<std::shared_ptr<AM::Window>> AM::Application::getWindows()
{

	return allWindows;

}

AM::Application& getSystem()
{

	return application;

}
