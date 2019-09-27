#include <windows.h>

int CALLBACK WinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	
	const auto pClassName = "hw3dbutts";
	//register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIcon = nullptr;
	RegisterClassEx( &wc );
	//create window instance
	HWND hWnd = CreateWindowEx(
		0,
		pClassName,
		"Happy Hard Window",
		WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		200, 200, 640, 480,
		nullptr, nullptr,
		hInstance,
		nullptr
	);
	//show the window
	ShowWindow(hWnd, SW_SHOW);
	return 0;
}
