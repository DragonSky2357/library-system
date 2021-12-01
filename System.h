#pragma once

#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")

using namespace Gdiplus;
ULONG_PTR gdiplusToken;
GdiplusStartupInput gdiplusStartupInput;

void printQRcode(int x, int y, int width, int height) {
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// image.png ������ �̿��Ͽ� Image ��ü�� �����մϴ�.
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);
	Image* image = Image::FromFile(L"C:\\Users\\qkrdy\\source\\repos\\LibrarySystem\\LibrarySystem\\20211120\\Image\\NFT �������.png");
	::Graphics g(hdc);

	// (x, y)�� width X height ũ���� �̹����� �׸��ϴ�.
	g.DrawImage(image, 0, 0, 100, 100);

	// ������ �޸� ����
	delete image;
	ReleaseDC(hWnd, hdc);
}

