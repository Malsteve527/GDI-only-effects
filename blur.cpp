#include <Windows.h>
#include <iostream>

const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);

void blur() {
    HDC hdc, memdc;
    HBITMAP hbit;

    BLENDFUNCTION blendFunc = {0, 0, 65, 0};

    while (1) {
        hdc = GetDC(0); memdc = CreateCompatibleDC(hdc);
        hbit = CreateCompatibleBitmap(hdc, HDCX, HDCY);
        (HBITMAP)SelectObject(memdc, hbit);

        BitBlt(memdc, 0, 0, HDCX, HDCY, hdc, 0, 0, SRCCOPY);
        AlphaBlend(hdc, (rand()%11)-5, (rand()%11)-5, HDCX, HDCY, memdc, 0, 0, HDCX, HDCY, blendFunc);

        ReleaseDC(0, hdc); DeleteDC(memdc); DeleteObject(hbit);
    }
}

int main() {
    srand(time(0));
    blur();
}