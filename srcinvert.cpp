#include <Windows.h>
#include <iostream>

const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);

void srcinvert() {
    HDC hdc;

    while (1) {
        hdc = GetDC(0);

        BitBlt(hdc, (rand()%11)-5, (rand()%11)-5, HDCX, HDCY, hdc, 0, 0, SRCINVERT);

        ReleaseDC(0, hdc);
    }
}

int main() {
    srand(time(0));
    srcinvert();
}