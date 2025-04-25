#include <Windows.h>

const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);

void inverting() {
    HDC hdc;

    while (1) {
        Sleep(1000);
        hdc = GetDC(0);
        PatBlt(hdc, 0, 0, HDCX, HDCY, PATINVERT);
        ReleaseDC(0, hdc);
    }
}

int main() {
    inverting();
}