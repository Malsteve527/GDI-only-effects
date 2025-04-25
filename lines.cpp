#include <Windows.h>
#include <iostream>

const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);

void lines() {
    HDC hdc;
    HPEN pen;
    COLORREF color;
    POINT bPoints[4];
    bPoints[0] = {HDCX/2, 0};

    while (1) {
        hdc = GetDC(0);

        bPoints[1] = {rand()%HDCX, rand()%HDCY};
        bPoints[2] = {rand()%HDCX, rand()%HDCY};
        bPoints[3] = {rand()%HDCX, rand()%HDCY};

        color = RGB(rand()%256, rand()%256, rand()%256);
        pen = CreatePen(PS_SOLID, 7, color);
        SelectObject(hdc, pen);

        PolyBezier(hdc, bPoints, 4);

        ReleaseDC(0, hdc); DeleteObject(pen);
    }
}

int main() {
    srand(time(0));
    lines();
}