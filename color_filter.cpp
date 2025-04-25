#include <Windows.h>
#include <iostream>

const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);

void filter() {
    HDC hdc;
    HBRUSH brush;

    COLORREF color = RGB(rand()%256, rand()%256, rand()%256); //Random color each time. If you don't see it the color was too light.
    
    while (1) {
        hdc = GetDC(0);
        brush = CreateSolidBrush(color);
        SelectObject(hdc, brush);

        BitBlt(hdc, 0, 0, HDCX, HDCY, hdc, 0, 0, MERGECOPY);

        ReleaseDC(0, hdc); DeleteObject(brush);
    }
}

int main() {
    srand(time(0));
    filter();
}
