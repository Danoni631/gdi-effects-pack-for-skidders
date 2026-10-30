/*
  Work on C and C++

  on C, remove C++ things
*/

#include <windows.h>

int w = GetSystemMetrics(0);
int h = GetSystemMetrics(1);

int main()
{
	int r = 255;
	int g = 0;
	int b = 0;

	int state = 0;

	int x = rand() % w;
	int y = rand() % h;

	while (true)
	{
		if (state == 0)
		{
			g += 5; if (g >= 255) state = 1;
		}

		else if (state == 1)
		{
			r -= 5; if (r <= 0) state = 2;
		}

		else if (state == 2)
		{
			b += 5; if (b >= 255) state = 3;
		}

		else if (state == 3)
		{
			g -= 5; if (g <= 0) state = 4;
		}

		else if (state == 4)
		{
			r += 5; if (r >= 255) state = 5;
		}

		else if (state == 5)
		{
			b -= 5; if (b <= 0) state = 0;
		}

		HDC hdc = GetDC(NULL);

		HBRUSH circle = CreateSolidBrush(RGB(r, g, b));
		HPEN border = CreatePen(0, 1, RGB(255, 255, 255));

		SelectObject(hdc, circle);
		SelectObject(hdc, border);

		if (x >= w)
		{
			x = rand() % w;
			y = rand() % h;
		}

		else if (y >= h)
		{
			x = rand() % w;
			y = rand() % h;
		}

		else if (x <= 0)
		{
			x = rand() % w;
			y = rand() % h;
		}

		else if (y <= 0)
		{
			x = rand() % w;
			y = rand() % h;
		}

		int sel = rand() % 4 + 1;

		for (int runtime = 0; runtime < 10; runtime++)
		{
			switch (sel)
			{
				case 1:
					Ellipse(hdc, x, y, x, y);
					x += 20;
					y += 20;
					Sleep(1);

				case 2:
					Ellipse(hdc, x, y, x, y);
					x += 20;
					y -= 20;
					Sleep(1);

				case 3:
					Ellipse(hdc, x, y, x, y);
					x -= 20;
					y += 20;
					Sleep(1);

				case 4:
					Ellipse(hdc, x - 60, y - 60, x + 60, y + 60);
					x -= 20;
					y -= 20;
					Sleep(1);
			}
		}
	}
}
