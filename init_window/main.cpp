#include <windows.h>

/*
	study window programming.

	I typed this code from visual c++ mfc programming.
*/

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	static LPTSTR szAppName = "OurFileName"; //window class name
	static LPTSTR szTitleName = "OurTitleName"; // title bar name


	HWND hwnd; //handler 
	MSG msg; //Message
	WNDCLASSEX WndClass; // window class structure

	WndClass.cbSize = sizeof(WNDCLASSEX);// WndClass size
	WndClass.style = CS_HREDRAW | CS_VREDRAW; // class style
	WndClass.lpfnWndProc = WndProc;	 // window Procedure. call back function?
	WndClass.cbClsExtra = 0; // window class data region
	WndClass.cbWndExtra = 0; // window data region
	WndClass.hInstance = hInstance; //instance handle 
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //icon handle
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);// cursor handle
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // back ground brush handle
	WndClass.lpszMenuName = NULL; // menu name??
	WndClass.lpszClassName = szAppName;
	WndClass.hIconSm = 0;

	RegisterClassEx(&WndClass);

	hwnd = CreateWindow(szAppName, szTitleName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg); 
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {

	HDC hdc;
	RECT rect;
	PAINTSTRUCT ps;
	LPTSTR szMsg1 = "Start Window Programming";
	LPTSTR szMsg2 = "Keyboard Down";
	LPTSTR szMsg3 = "Keyboard Up";
	LPTSTR szMsg4 = "Left Mouse Down";
	LPTSTR szMsg5 = "Right Mouse Down";

	LPTSTR eraseTest = "                               ";

	switch (message)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 10, 10, szMsg1, strlen(szMsg1));
		EndPaint(hwnd, &ps);
		break;

	case WM_LBUTTONDOWN:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, eraseTest, strlen(eraseTest), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		DrawText(hdc, szMsg5, strlen(szMsg5), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_RBUTTONDOWN:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, eraseTest, strlen(eraseTest), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		DrawText(hdc, szMsg4, strlen(szMsg4), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_KEYDOWN:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, eraseTest, strlen(eraseTest), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		DrawText(hdc, szMsg2, strlen(szMsg2), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_KEYUP:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, eraseTest, strlen(eraseTest), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		DrawText(hdc, szMsg3, strlen(szMsg3), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default :
		return DefWindowProc(hwnd, message, wParam, lParam);

	}
	return  0;
}