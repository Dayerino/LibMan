#include "header.h"
LRESULT CALLBACK currentBooksWndProc(HWND crntbookshWnd, UINT message, WPARAM wParam, LPARAM lParam){
    switch(message){
        case WM_COMMAND:{
            if(LOWORD(wParam)>=5000){//book buttons start from 5000 and go on from here
                //iterator here needs to be a global variable that i can reuse
                auto iterator = BooksMap.find(wParam);
                if(iterator !=BooksMap.end()){
                    foundBook = iterator->second;
                    selectedBookWparam = wParam;
                }
                std:: string wp = std::to_string(selectedBookWparam);
                //MessageBox(hWnd,"please enter a number in book id","error",MB_ICONERROR);
                EnableWindow(ModifyBookBtn,TRUE);
                EnableWindow(RemoveBookBtn,TRUE);
                UpdateWindow(bookinfohWnd);
                InvalidateRect(bookinfohWnd,NULL,TRUE);
                UpdateWindow(bookinfohWnd);
            }
        }
        
    case WM_CREATE:{
        SCROLLINFO scrl = { sizeof(scrl)};
        scrl.nMin = 0;
        scrl.nMax = 100;
        SetScrollInfo(crntbookshWnd,SB_VERT,&scrl,TRUE);
        return 0;
    }
    case WM_VSCROLL:{
            SCROLLINFO scrl = {sizeof(scrl)};
            scrl.fMask = SIF_ALL;
            GetScrollInfo(crntbookshWnd,SB_VERT,&scrl);
            int pos = scrl.nPos;
            switch(LOWORD(wParam)){
                case SB_LINEUP:
                scrl.nPos -=1;
                break;
                case SB_LINEDOWN:
                scrl.nPos +=1;
                break;
                case SB_PAGEUP:
                scrl.nPos -=scrl.nPage;
                break;
                case SB_PAGEDOWN:
                scrl.nPos +=scrl.nPage;
                break;
                case SB_THUMBTRACK:
                scrl.nPos = HIWORD(wParam);
                break;
            }
            scrl.fMask = SIF_POS;
            SetScrollInfo(crntbookshWnd,SB_VERT,&scrl,TRUE);
            GetScrollInfo(crntbookshWnd,SB_VERT,&scrl);
            if(scrl.nPos != pos){
                ScrollWindow(crntbookshWnd,0,pos - scrl.nPos,NULL,NULL);
                UpdateWindow(crntbookshWnd);
            }
            break;
        }
        case WM_PAINT:{
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(crntbookshWnd,&ps);
            /*if(!booksVec.empty()){
                for(BOOK el: booksVec){
                    automateBookShowing(el,hdc,10,addedBooksYPos);
                    addedBooksYPos += 50;
                }
            }*/
            EndPaint(crntbookshWnd,&ps);
            break;
        }
        case WM_DESTROY:{
            if(rc == SQLITE_OK){
                sqlite3_close(database);
            }
            PostQuitMessage(0);
            return 0;
        }
        default:
        return DefWindowProc(crntbookshWnd,message,wParam,lParam);
}
return 0;
}
void registercurrentBooksWindow(HINSTANCE hInstance){
    WNDCLASS currentBooksWindow={};
    currentBooksWindow.lpfnWndProc = currentBooksWndProc;
    currentBooksWindow.cbClsExtra = 0;
    currentBooksWindow.cbWndExtra = 0;
    currentBooksWindow.hInstance = hInstance;
    currentBooksWindow.hIcon = NULL; //setting the executable icon
    currentBooksWindow.hCursor =LoadCursor(NULL,IDC_ARROW);//setting cursour inside window
    currentBooksWindow.hbrBackground = NULL;
    currentBooksWindow.lpszMenuName = NULL;//assigns what menu is linked to this window (might change later using LOADMenu after creating one)
    currentBooksWindow.lpszClassName = TEXT("CurrentBooksWindow");
    currentBooksWindow.hbrBackground = CreateSolidBrush(RGB(222,222,222));
    if(!RegisterClass(&currentBooksWindow)){
        MessageBox(NULL,TEXT("current books window class registration failed"),TEXT("Error"),MB_ICONERROR);
    }
}