#include "header.h"
#include "WindowSource.cpp"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    registerWindow(hInstance);
    HWND hWnd = createMainWindow(hInstance);
    HWND TitleWindow = createTitleWindow(hInstance,hWnd);
    HFONT hFont = CreateFont(
    24,                // Height
    0,                 // Width
    0,                 // Escapement
    0,                 // Orientation
    FW_BOLD,           // Weight (FW_NORMAL, FW_BOLD, etc.)
    FALSE,             // Italic
    FALSE,             // Underline
    FALSE,             // StrikeOut
    ANSI_CHARSET,      // Charset
    OUT_DEFAULT_PRECIS,// OutputPrecision
    CLIP_DEFAULT_PRECIS,// ClipPrecision
    DEFAULT_QUALITY,   // Quality
    DEFAULT_PITCH | FF_SWISS, // PitchAndFamily
    "Arial"            // Typeface name
    );
    SendMessage(TitleWindow,WM_SETFONT,(WPARAM)hFont,TRUE);
    MSG msg;
    ShowWindow(hWnd,SW_SHOW);
    UpdateWindow(hWnd);
    ShowWindow(TitleWindow,SW_SHOW);//child windows must be shown aswell, they dont appear automatically after their parents
    UpdateWindow(TitleWindow);
    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}