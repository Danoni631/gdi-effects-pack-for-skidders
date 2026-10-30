/*
  Work on C and C++
*/

#include <windows.h>

void Effect(HDC hdc, HDC dcCopy, int w, int h, DWORD rop)
{
	HBITMAP bitmap = CreateCompatibleBitmap(hdc, w, h);
	SelectObject(dcCopy, bitmap);
	HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
	SelectObject(hdc, brush);
	PatBlt(hdc, 0, 0, w, h, rop);
	DeleteObject(brush);
	DeleteObject(dcCopy);
	DeleteObject(bitmap);
	ReleaseDC(0, hdc);
	Sleep(1);
}

int main()
{
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);

	while (1)
	{
		HDC hdc = GetDC(0);
		HDC dcCopy = CreateCompatibleDC(hdc);

		Effect(hdc, dcCopy, w, h, PATCOPY);
	}
}
