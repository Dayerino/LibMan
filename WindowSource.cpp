#include "header.h" 
#include "currentBooksWnd.cpp"
#include "BookInfoWnd.cpp"
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
    switch(message){
        
        case WM_CREATE:{
        SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)Ptr);
        return 0;
    }
        case WM_COMMAND:{
            if(LOWORD(wParam)== 1001){
                MessageBox(NULL,TEXT("button pressed! and buttons enabled!"),TEXT("not error"),MB_ICONEXCLAMATION);
                EnableWindow(RemoveBookBtn,TRUE);
                EnableWindow(ModifyBookBtn,TRUE);
            }
            if(LOWORD(wParam)== 1002){
                if(!TextEdit){
                    /*create a new window that has these edit classes inside it but they are initially disabled until add a new book is clicked, then the info inside gets
                    stored in some temp variables to be used to create book objects which get added to the current books window*/
                TextEdit = CreateWindowEx(0,"EDIT","",WS_CHILD|WS_VISIBLE|WS_BORDER,windowWidth/2,windowHeight/2,150,25,hWnd,(HMENU)1,window.hInstance,NULL);
                }else{
                    char buffer[256];
                    GetWindowText(TextEdit,buffer,256);
                    Text = buffer;
                    MessageBox(hWnd,Text.c_str(),"stored text: ",MB_OK);
                }
                //InvalidateRect(BookInfoWindow,NULL,TRUE);
                EnableWindow(RemoveBookBtn,TRUE);
                EnableWindow(ModifyBookBtn,TRUE);
            }
            if(LOWORD(wParam)== 1003){
                MessageBox(NULL,TEXT("button pressed!"),TEXT("not error"),MB_ICONEXCLAMATION);
            }
            if(LOWORD(wParam)== 1004){
                MessageBox(NULL,TEXT("button pressed!"),TEXT("not error"),MB_ICONEXCLAMATION);
            }
            return 0;
        }
        break;
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
void registerMainWindow(HINSTANCE hInstance){
    window.lpfnWndProc = WndProc;
    window.cbClsExtra = 0;
    window.cbWndExtra = sizeof(void*);//saving space for a potential pointer to be stored in the window(?)
    window.hInstance = GetModuleHandle(NULL);//this means that this window is owned by itself
    window.hIcon = NULL; //setting the executable icon
    window.hCursor =LoadCursor(NULL,IDC_ARROW);//setting cursour inside window
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
HWND CreateCurrentBooksWindow(HINSTANCE hInstance,HWND MainWindow){
    return CreateWindowEx(WS_EX_APPWINDOW,TEXT("CurrentBooksWindow"),TEXT(""),WS_CHILD|WS_BORDER|WS_VSCROLL,CrntBooksWndXpos,CrntBooksWndYpos,CrntBooksWndWidth,crntBooksWndHeight,MainWindow,NULL,window.hInstance,NULL);
}
HWND CreateBookInfoWindow(HINSTANCE hInstance,HWND MainWindow){
    return CreateWindowEx(WS_EX_APPWINDOW,TEXT("BookInfoWindow"),TEXT("BookInfo"),WS_CHILD|WS_BORDER|WS_DISABLED,bookInfoWndXpos,bookInfoWndYpos,bookInfoWndWidth,bookInfoWndHeight,MainWindow,NULL,window.hInstance,NULL);
}
HWND CreateShowAllBooksButton(HINSTANCE hInstance,HWND MainWindow){
   return CreateWindowEx(WS_EX_APPWINDOW,TEXT("BUTTON"),TEXT("Show ALL Books"),WS_CHILD|WS_VISIBLE,showBooksBtnXpos,showBooksBtnYpos,BtnWidth,BtnHeight,MainWindow,(HMENU)1001,window.hInstance,NULL);
}
HWND CreateAddBookButton(HINSTANCE hInstance, HWND MainWindow){
    return CreateWindowEx(WS_EX_APPWINDOW,TEXT("BUTTON"),TEXT("Add Book"),WS_CHILD|WS_VISIBLE,addBookBtnXpos,addBookBtnYpos,BtnWidth,BtnHeight,MainWindow,(HMENU)1002,window.hInstance,NULL);
}
HWND CreateModifyBookButton(HINSTANCE hInstance,HWND MainWindow){
    return CreateWindowEx(WS_EX_APPWINDOW,TEXT("BUTTON"),TEXT("Modify Book"),WS_CHILD|WS_VISIBLE|WS_DISABLED,modifyBookBtnXpos,modifyBookBtnYpos,BtnWidth,BtnHeight,MainWindow,(HMENU)1003,window.hInstance,NULL);
}
HWND CreateRemoveBookButton(HINSTANCE hInstance,HWND MainWindow){
    return CreateWindowEx(WS_EX_APPWINDOW,TEXT("BUTTON"),TEXT("Remove Book"),WS_CHILD|WS_VISIBLE|WS_DISABLED,removeBookBtnXpos,removeBookBtnYpos,BtnWidth,BtnHeight,MainWindow,(HMENU)1004,window.hInstance,NULL);
}   
