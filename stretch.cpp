#include <Windows.h>
#include <cmath>

const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);

void stretch() {
    HDC hdc;
    int t = 0, w;

    while (1) {
        hdc = GetDC(0);
        
        w = 20*sin(t*0.05);
        StretchBlt(hdc, -w/2, 0, HDCX+w, HDCY, hdc, 0, 0, HDCX, HDCY, SRCCOPY); t++;

        ReleaseDC(0, hdc);
    }
}

int main() {
    stretch();
}