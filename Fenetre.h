#pragma once

#include <Windows.h>
namespace app {

	class Fenetre {
		HWND window;
		static bool running;

	public:
		bool create_window(int, int, const char*);
		void update_window();
		static LRESULT CALLBACK windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam);
		bool* getRunning();
	};
}
