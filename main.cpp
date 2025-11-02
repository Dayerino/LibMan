#include "header.h"
#include "WindowSource.cpp"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    registerMainWindow(hInstance);
    registercurrentBooksWindow(hInstance);
    registerBookInfoWindow(hInstance);
    hWnd = createMainWindow(hInstance);
    TitleWindow = createTitleWindow(hInstance,hWnd);
    CurrentBooksWindow = CreateCurrentBooksWindow(hInstance,hWnd);
    BookInfoWindow = CreateBookInfoWindow(hInstance,hWnd);
    SendMessage(TitleWindow,WM_SETFONT,(WPARAM)hFont,TRUE);
    MSG msg;
    ShowWindow(hWnd,SW_SHOW);
    ShowWindow(TitleWindow,SW_SHOW);//child windows must be shown aswell, they dont appear automatically after their parents
    UpdateWindow(TitleWindow);
    ShowWindow(CurrentBooksWindow,SW_SHOW);
    UpdateWindow(CurrentBooksWindow);
    ShowWindow(BookInfoWindow,SW_SHOW);
    UpdateWindow(BookInfoWindow);
    UpdateWindow(hWnd);
    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
