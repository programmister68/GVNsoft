#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static TCHAR szAppName[] = _T("Demo");
HPEN hRedPen, hLilacPen, hGreenPen, hBluePen, hOrangePen;
HBRUSH hRedBrush, hLilacBrush, hGreenBrush, hBlueBrush, hOrangeBrush;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;

	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(120, 120, 255));
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&wndclass);
	hwnd = CreateWindow(szAppName, _T("Графика"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (msg)
	{
	case WM_CREATE:
		hRedPen = CreatePen(PS_SOLID, 2, RGB(150, 0, 0));
		hBluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 150));

		hRedBrush = CreateSolidBrush(RGB(255, 120, 120));
		hBlueBrush = CreateSolidBrush(RGB(120, 120, 255));

		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkMode(hdc, TRANSPARENT);
		
		//Rectangle(hdc, 10, 40, 150, 140); // Прямоугольник

		SelectPen(hdc, hBluePen);
		SelectBrush(hdc, hBlueBrush);
		Chord(hdc, 10, 40, 150, 140, 10, 100, 148, 100); // Дуга

		
		SelectPen(hdc, hRedPen);
		SelectBrush(hdc, hRedBrush);
		Chord(hdc, 10, 140, 150, 240, 910, 62, 12, 180); // Дуга

		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default: return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}