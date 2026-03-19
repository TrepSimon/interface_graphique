#pragma once

#include <Windows.h>
#include "tchar.h"
#include <vector>

namespace app {

	class Fenetre {
		HWND window;
		static bool running;
		static LRESULT(*windowProc)(HWND, UINT, WPARAM, LPARAM);
	public:
		Fenetre();
		bool create_window(int, int, const char*);
		void update_window();
		static LRESULT CALLBACK windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam);
		bool* getRunning();
		void addWindowProc(LRESULT(*func)(HWND, UINT, WPARAM, LPARAM));
	};
}
