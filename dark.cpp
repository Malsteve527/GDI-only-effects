#include <Windows.h>
#include <iostream>

const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);

void dark() {
    HDC hdc;

    while (1) {
        hdc = GetDC(0);

        BitBlt(hdc, (rand()%3)-1, (rand()%3)-1, HDCX, HDCY, hdc, 0, 0, SRCAND);

        ReleaseDC(0, hdc);
    }
}

int main() {
    srand(time(0));
    dark();
}