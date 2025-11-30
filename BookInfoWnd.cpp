#include "header.h"
LRESULT CALLBACK BookInfoWindowProc(HWND bookinfohWnd,UINT message,WPARAM wParam,LPARAM lParam){
    switch(message){
        case WM_PAINT:{
            PAINTSTRUCT Paint;
            HDC hdc = BeginPaint(bookinfohWnd,&Paint);
            if(foundBook.getBookDescription()!= ""){
            SetWindowText(descriptionWindow,foundBook.getBookDescription().c_str());
        }else{
            SetWindowText(descriptionWindow,"");
        }
            EndPaint(bookinfohWnd,&Paint);
            return 0;
        }
        case WM_DESTROY:{
            PostQuitMessage(0);
            return 0;
        }
        default:
        return DefWindowProc(bookinfohWnd,message,wParam,lParam);
    }
    return 0;
}
void registerBookInfoWindow(HINSTANCE hInstance){
    WNDCLASS BookInfo={};
    BookInfo.lpfnWndProc = BookInfoWindowProc;
    BookInfo.cbClsExtra = 0;
    BookInfo.cbWndExtra = 0;
    BookInfo.hInstance = hInstance;
    BookInfo.hIcon = NULL; //setting the executable icon
    BookInfo.hCursor =LoadCursor(NULL,IDC_ARROW);//setting cursour inside window
    BookInfo.hbrBackground = NULL;
    BookInfo.lpszMenuName = NULL;//assigns what menu is linked to this window (might change later using LOADMenu after creating one)
    BookInfo.lpszClassName = TEXT("bookinfohWnd");
    BookInfo.hbrBackground = CreateSolidBrush(RGB(222,222,222));
    if(!RegisterClass(&BookInfo)){
        MessageBox(NULL,TEXT("book info window class registration failed"),TEXT("Error"),MB_ICONERROR);
    }
}