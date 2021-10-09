#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <string.h>
#include <stdio.h>

LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);

char szWinName[] = "МоеОкно";
char str[80] = "Строка вывода";

int WINAPI WinMain(HINSTANCE hThisInst,
	HINSTANCE hPrevInst,
	LPSTR lpszArgs,
	int nWinMode)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS wcl;

	wcl.hInstance = hThisInst;
	wcl.lpszClassName = szWinName;
	wcl.lpfnWndProc = WindowFunc;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.lpszMenuName = NULL;

	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;

	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	if (!RegisterClass(&wcl))
		return 0;

	hwnd = CreateWindow(szWinName,
		"Обработка сообщений мыши",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		HWND_DESKTOP,
		NULL,
		hThisInst,
		NULL
	);

	ShowWindow(hwnd, nWinMode);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WindowFunc(HWND hwnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT paintstruct;
	switch (message)
	{
	case WM_CHAR:
		hdc = GetDC(hwnd);
		TextOut(hdc, 1, 1, " ", 2);
		sprintf(str, "%c", (char)wParam);

		TextOut(hdc, 1, 1, str, strlen(str));
		ReleaseDC(hwnd, hdc);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &paintstruct);
		TextOut(hdc, 1, 1, str, strlen(str));
		EndPaint(hwnd, &paintstruct);
		break;

	case WM_RBUTTONDOWN:
		hdc = GetDC(hwnd);
		strcpy(str, "Нажата правая кнопка");
		TextOut(hdc, LOWORD(lParam), HIWORD(lParam),
			str, strlen(str));
		ReleaseDC(hwnd, hdc);
		break;

	case WM_LBUTTONDOWN:
		hdc = GetDC(hwnd);
		strcpy(str, "Нажата левая кнопка");
		TextOut(hdc, LOWORD(lParam), HIWORD(lParam),
			str, strlen(str));
		ReleaseDC(hwnd, hdc);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);

	}
	return 0;
}
