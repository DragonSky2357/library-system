#pragma once

#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")

using namespace Gdiplus;
ULONG_PTR gdiplusToken;
GdiplusStartupInput gdiplusStartupInput;

void printQRcode(int x, int y, int width, int height) {
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// image.png 파일을 이용하여 Image 객체를 생성합니다.
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);
	Image* image = Image::FromFile(L"C:\\Users\\qkrdy\\source\\repos\\LibrarySystem\\LibrarySystem\\20211120\\Image\\NFT 레볼루션.png");
	::Graphics g(hdc);

	// (x, y)에 width X height 크기의 이미지를 그립니다.
	g.DrawImage(image, 0, 0, 100, 100);

	// 데이터 메모리 해제
	delete image;
	ReleaseDC(hWnd, hdc);
}

