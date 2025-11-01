#include "header.h"
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
    switch(message){
        case WM_CREATE:{
        SetWindowLongPtr(hWnd, 0, (LONG_PTR)Ptr);
        return 0;
    }
        case WM_CTLCOLORSTATIC:{
        HDC hdcStatic = (HDC)wParam;
        HWND hwndStatic = (HWND)lParam;
        SetTextColor(hdcStatic,RGB(0,0,0));
        SetBkMode(hdcStatic,TRANSPARENT);
        return(INT_PTR)GetStockObject(NULL_BRUSH);
    }
        case WM_DESTROY:{
        void* Ptr = (void*)GetWindowLongPtr(hWnd,0);
        PostQuitMessage(0);
        return 0;}
        default:
        return DefWindowProc(hWnd,message,wParam,lParam);
    }
    return 0;
}
void registerWindow(HINSTANCE hInstance){
    window.lpfnWndProc = WndProc;
    window.cbClsExtra = 0;
    window.cbWndExtra = sizeof(void*);//saving space for a potential pointer to be stored in the window(?)
    window.hInstance = GetModuleHandle(NULL);//this means that this window is owned by itself
    window.hIcon = NULL; //setting the executable icon
    window.hCursor =LoadCursor(NULL,IDC_IBEAM);//setting cursour inside window
    window.hbrBackground = NULL;
    window.lpszMenuName = NULL;//assigns what menu is linked to this window (might change later using LOADMenu after creating one)
    window.lpszClassName = TEXT("MainWindow");
    window.hbrBackground = CreateSolidBrush(RGB(222,222,222));
    if(!RegisterClass(&window)){
        MessageBox(NULL,TEXT("window class registration failed"),TEXT("Error"),MB_ICONERROR);
    }
}
HWND createMainWindow(HINSTANCE hInstance){
    return CreateWindowEx(WS_EX_APPWINDOW,TEXT("MainWindow"),TEXT("LibMan"),WS_OVERLAPPEDWINDOW,windowXpos,windowYpos,windowWidth,windowHeight,NULL,NULL,window.hInstance,NULL);
}
HWND createTitleWindow(HINSTANCE hInstance,HWND MainWindow){
    return CreateWindowEx(WS_EX_APPWINDOW,TEXT("STATIC"),TEXT("Library Manager"),WS_CHILD|WS_BORDER,TitleWindowXpos,TitleWindowYpos,TitleWindowWidth,TitleWindowHeight,MainWindow,NULL,window.hInstance,NULL);
}