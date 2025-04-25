#include <Windows.h>
#include <iostream>

const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);

void glitch() {
    HDC hdc, memdc;
    HBITMAP hbit;

    while (1) {
        hdc = GetDC(0); memdc = CreateCompatibleDC(hdc);
        hbit = CreateCompatibleBitmap(hdc, HDCX, HDCY);
        (HBITMAP)SelectObject(memdc, hbit);

        BitBlt(memdc, 0, 0, HDCX, HDCY, hdc, 0, 0, SRCCOPY);

        for (int y = 0; y <= HDCY; y++) {
            BitBlt(memdc, (rand()%11)-5, y, HDCX, 1, memdc, 0, y, SRCCOPY);
        }

        BitBlt(hdc, 0, 0, HDCX, HDCY, memdc, 0, 0, SRCCOPY);

        ReleaseDC(0, hdc); DeleteDC(memdc); DeleteObject(hbit);
    }
}

int main() {
    srand(time(0));
    glitch();
}