# pragma once
# include <Windows.h>
# include <memory>
# include <vector>
# include <array>
# include <map>

int APIENTRY WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmpLine,
	INT       nCmdShow
);

namespace AM
{

	class Window;

	class Application
	{
	public:

		Application();

		Application(HINSTANCE hInstance);

		/// <summary>
		/// 新しくウィンドウを作成します。
		/// </summary>
		/// 
		/// <returns>新しいウィンドウ</returns>
		[[nodiscard]]
		AM::Window& createWindow();

		/// <summary>
		/// ウィンドウを削除します。
		/// </summary>
		/// <param name="hwnd">削除するウィンドウのハンドル</param>
		/// <returns>ウィンドウが存在したか</returns>
		bool removeWindow(HWND hwnd);

		/// <summary>
		/// ウィンドウを取得します。
		/// </summary>
		/// <param name="hwnd">ウィンドウのハンドル</param>
		std::shared_ptr<AM::Window> getWindow(HWND hwnd);

		/// <summary>
		/// 存在するウィンドウをすべて取得します。
		/// </summary>
		std::vector<std::shared_ptr<AM::Window>> getWindows();

	private:

		HINSTANCE hInstance;

		std::vector<std::shared_ptr<AM::Window>> allWindows;

		std::map<HWND, std::shared_ptr<AM::Window>> hwndWindows;

		friend class AM::Window;

	};

}

void Main(AM::Application& system);

AM::Application& getSystem();
