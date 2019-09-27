#include <windows.h>

LRESULT CALLBACK WinProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam ) {

	switch ( msg ) {
	case WM_CLOSE:
		PostQuitMessage( 69 );
		break;
	}
	return DefWindowProc( hWnd, msg, wParam, lParam );

}

int CALLBACK WinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	
	const auto pClassName = "hw3dbutts";
	//register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof( wc );
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WinProc;
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

	//message pump
	MSG msg;
	BOOL gResult;
	while ( (gResult = GetMessage( &msg, nullptr, 0, 0 )) > 0 ) {
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}

	if ( gResult == -1 ) {
		return -1;
	}
	else {
		return msg.wParam;
	}

}
