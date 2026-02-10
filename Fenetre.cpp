#include "Fenetre.h"

namespace app {

	bool Fenetre::running = false;
	void (*callback)(HDC) = NULL;

	LRESULT CALLBACK Fenetre::windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT result = 0;

		switch (msg) {
		case WM_CLOSE:
			running = false;
			CloseWindow(window);
			break;
		case WM_PAINT:{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(window, &ps);

			FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

			drawMethode(hdc);

			EndPaint(window, &ps);
			break;
		}
		default:
			result = DefWindowProcA(window, msg, wParam, lParam);
		}

		return result;
	}

	bool Fenetre::create_window(int largeur, int hauteur, const char* titre) {
		HINSTANCE instance = GetModuleHandleA(0);

		WNDCLASSA ws = {};
		ws.hInstance = instance;
		ws.hIcon = LoadIcon(instance, IDI_APPLICATION);
		ws.hCursor = LoadCursor(NULL, IDC_ARROW);
		ws.lpszClassName = titre;
		ws.lpfnWndProc = windows_window_callback;

		if (!RegisterClassA(&ws)) {
			return false;
		}

		int style = WS_OVERLAPPEDWINDOW;

		window = CreateWindowExA(0, titre, titre,
			style, 100, 100, largeur, hauteur, NULL, NULL, instance, NULL);

		if (window == NULL) {
			return false;
		}

		ShowWindow(window, SW_SHOW);
		
		return true;
	}

	void Fenetre::update_window() {
		MSG msg;

		while (PeekMessageA(&msg, window, 0, 0, PM_REMOVE)) {

			TranslateMessage(&msg);
			DispatchMessageA(&msg);
		}
	}

	bool* Fenetre::getRunning() {
		return &running;
	}

	void Fenetre::addFunction(void (*func)(HDC)) {
		drawMethode = func;
	}
	
}