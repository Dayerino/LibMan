#include "header.h"
#include "WindowSource.cpp"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    registerWindow(hInstance);
    HWND hWnd = createMainWindow(hInstance);
    MSG msg;
    ShowWindow(hWnd,SW_SHOW);
    UpdateWindow(hWnd);
    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}