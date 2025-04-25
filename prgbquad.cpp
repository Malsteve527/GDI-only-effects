#include <Windows.h>

const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);

typedef union {
    COLORREF rgb;
    struct {
        BYTE rgbBlue;
        BYTE rgbGreen;
        BYTE rgbRed;
        BYTE rgbReserved;
    };
} *PRGBQUAD;

void prgbquad() {
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

    PRGBQUAD pixel = {0};

    while (1) {
        hdc = GetDC(0); memdc = CreateCompatibleDC(hdc);
        hdib = CreateDIBSection(hdc, &bInfo, NULL, (void**)&pixel, 0, 0);
        SelectObject(memdc, hdib);

        BitBlt(memdc, 0, 0, HDCX, HDCY, hdc, 0, 0, SRCCOPY);

        for (int i = 0; i < HDCX * HDCY; i++) {
            pixel[i].rgb += i/HDCX ^ HDCX/(i+10);
        }

        BitBlt(hdc, 0, 0, HDCX, HDCY, memdc, 0, 0, SRCCOPY);

        ReleaseDC(0, hdc); DeleteDC(memdc); DeleteObject(hdib);
    }
}

int main() {
    prgbquad();
}