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
		/// �V�����E�B���h�E���쐬���܂��B
		/// </summary>
		/// 
		/// <returns>�V�����E�B���h�E</returns>
		[[nodiscard]]
		AM::Window& createWindow();

		/// <summary>
		/// �E�B���h�E���폜���܂��B
		/// </summary>
		/// <param name="hwnd">�폜����E�B���h�E�̃n���h��</param>
		/// <returns>�E�B���h�E�����݂�����</returns>
		bool removeWindow(HWND hwnd);

		/// <summary>
		/// �E�B���h�E���擾���܂��B
		/// </summary>
		/// <param name="hwnd">�E�B���h�E�̃n���h��</param>
		std::shared_ptr<AM::Window> getWindow(HWND hwnd);

		/// <summary>
		/// ���݂���E�B���h�E�����ׂĎ擾���܂��B
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
