//Warning! This will move your cursor
#include <Windows.h>
#include <iostream>

void crazy_mouse() {
    HDC hdc;
    POINT curPos;
    HICON icon = LoadIcon(NULL, IDI_ERROR);
    int w = GetSystemMetrics(SM_CXICON), h = GetSystemMetrics(SM_CYICON);
    
    while (1) {
        hdc = GetDC(0);

        GetCursorPos(&curPos);
        SetCursorPos(curPos.x + (rand()%5)-2, curPos.y + (rand()%5)-2);
        DrawIcon(hdc, curPos.x-w, curPos.y-h, icon);

        ReleaseDC(0, hdc);
    }
}

int main() {
    srand(time(0));
    crazy_mouse();
}