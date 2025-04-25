#include <Windows.h>
#include <cmath>

const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);

void wave() {
    HDC hdc;
    int y = 0;

    while (1) {
        hdc = GetDC(0);

        BitBlt(hdc, 30*sin(y*0.08), y, HDCX, 1, hdc, 0, y, SRCCOPY); y++;

        if (y > HDCY) {
            y = 0;
        }

        ReleaseDC(0, hdc);
    }
}

int main() {
    wave();
}