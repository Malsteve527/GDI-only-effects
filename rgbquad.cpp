#include <Windows.h>

const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);

void rgbquad() {
    HDC hdc, memdc;
    HBITMAP hdib;

    BITMAPINFO bInfo = {0};
    bInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bInfo.bmiHeader.biBitCount = 32;
    bInfo.bmiHeader.biPlanes = 1;
    bInfo.bmiHeader.biWidth = HDCX;
    bInfo.bmiHeader.biHeight = HDCY;
    bInfo.bmiHeader.biCompression = BI_RGB;
    bInfo.bmiHeader.biSizeImage = 0;

    RGBQUAD *pixel = {0};

    while (1) {
        hdc = GetDC(0); memdc = CreateCompatibleDC(hdc);
        hdib = CreateDIBSection(hdc, &bInfo, NULL, (void**)&pixel, 0, 0);
        SelectObject(memdc, hdib);

        BitBlt(memdc, 0, 0, HDCX, HDCY, hdc, 0, 0, SRCCOPY);

        for (int i = 0; i < HDCX * HDCY; i++) {
            pixel[i].rgbGreen += 30;
            pixel[i].rgbBlue += 15;
        }

        BitBlt(hdc, 0, 0, HDCX, HDCY, memdc, 0, 0, SRCCOPY);

        ReleaseDC(0, hdc); DeleteDC(memdc); DeleteObject(hdib);
    }
}

int main() {
    rgbquad();
}
