#pragma once

#include <Windows.h>
#include "tchar.h"
#include <vector>

namespace app {

	class Fenetre {
		HWND window;
		static HWND editWindow;
		static bool running;
		static void(*PaintMethode)(HDC);
		static HWND(*onCreateMethode)(HWND, int);
		static void (*onResize)(HWND, int, int);
	public:
		Fenetre();
		static int* bitmapWidth;
		bool create_window(int, int, const char*);
		void update_window();
		static LRESULT CALLBACK windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam);
		bool* getRunning();
		void addPaintFunction(void (*func)(HDC));
		void addCreateFunction(HWND(*func)(HWND, int));
		void addResizeMethod(void(*func)(HWND, int, int));
	};
}
