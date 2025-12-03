#include "header.h"
#include "currentBooksWnd.cpp"
#include "BookInfoWnd.cpp"
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
    switch(message){
        case WM_CREATE:{
        SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)Ptr);
        return 0;
    }
    break;
        case WM_COMMAND:{
            if(LOWORD(wParam)== 1001){//show all books in the db
                //retrieveALLFromDB(database,booksVec);
                createBookButtons(crntbookshWnd,database,booksVec,usedBooks,BooksMap,bookbuttons);
                InvalidateRect(crntbookshWnd,NULL,TRUE);
                UpdateWindow(crntbookshWnd);
                //EnableWindow(ModifyBookBtn,TRUE);
            }
            if(LOWORD(wParam)== 1002){
                drawInputTexts = true;
                InvalidateRect(hWnd,NULL,TRUE);
                //InvalidateRect(bookinfohWnd,NULL,TRUE);
                ShowWindow(BookNameInput,SW_SHOW);
                ShowWindow(AuthorNameInput,SW_SHOW);
                ShowWindow(BookId,SW_SHOW);
                ShowWindow(BookDescriptionInput,SW_SHOW);
                }
            
            if(LOWORD(wParam)== 1003){
                drawInputTexts = true;
                InvalidateRect(hWnd,NULL,TRUE);
                SetWindowText(BookNameInput,foundBook.getBookTitle().c_str());
                SetWindowText(AuthorNameInput,foundBook.getBookAuthor().c_str());
                std::string bookidSTR = std::to_string(foundBook.getBookID());
                SetWindowText(BookId,bookidSTR.c_str());
                SetWindowText(BookDescriptionInput,foundBook.getBookDescription().c_str());
                ShowWindow(BookNameInput,SW_SHOW);
                ShowWindow(AuthorNameInput,SW_SHOW);
                ShowWindow(BookId,SW_SHOW);
                ShowWindow(BookDescriptionInput,SW_SHOW);
            }
            if(LOWORD(wParam)== 1004){
                    std::string booktitle = foundBook.getBookTitle();
                    deleteFromDB(database,booktitle);
                    deleteBookBTN(bookbuttons,selectedBookWparam);
                    BooksMap.erase(wParam);
                    booksVec.erase(std::remove(booksVec.begin(),booksVec.end(),foundBook),booksVec.end());
                    usedBooks.erase(std::remove(usedBooks.begin(),usedBooks.end(),foundBook),usedBooks.end());
                    bookBtnYpos = CrntBooksWndYpos *0.1;
                    SetWindowText(descriptionWindow,"");
                    InvalidateRect(bookinfohWnd,NULL,TRUE);
                    InvalidateRect(crntbookshWnd,NULL,TRUE);
                    UpdateWindow(bookinfohWnd);
                    UpdateWindow(crntbookshWnd);
            }
            if(LOWORD(wParam) == 1005){
                drawInputTexts = false;
                ShowWindow(BookNameInput,SW_HIDE);
                ShowWindow(AuthorNameInput,SW_HIDE);
                ShowWindow(BookId,SW_HIDE);
                ShowWindow(BookDescriptionInput,SW_HIDE);
                std::string BN= GetTextFromInput(BookNameInput);
                std::string AN=GetTextFromInput(AuthorNameInput);
                std:: string bID=GetTextFromInput(BookId);
                std:: string BD = GetTextFromInput(BookDescriptionInput);
                int bookId = std::stoi(bID);
                newObj.setBookTitle(BN);
                newObj.setBookAuthor(AN);
                newObj.setBookID(bookId);
                newObj.setDescription(BD);
                //inserting into the database
                addBookToDB(database,newObj);
                //clearing text
                SetWindowText(BookNameInput, "");
                SetWindowText(AuthorNameInput, "");
                SetWindowText(BookId, "");
                SetWindowText(BookDescriptionInput,"");
                InvalidateRect(hWnd,NULL,TRUE);
                add1newBooktoUI(newObj,booksVec,usedBooks,BooksMap,bookbuttons,crntbookshWnd);
                createBookButtons(crntbookshWnd,database,booksVec,usedBooks,BooksMap,bookbuttons);
                InvalidateRect(crntbookshWnd,NULL,TRUE);
                UpdateWindow(hWnd);
            }
            if(HIWORD(wParam) == EN_CHANGE){
                int changedInput = LOWORD(wParam);
                if(changedInput == 1 || changedInput == 2 || changedInput == 3 || changedInput == 4){//1 2 3 4 are the wParams of the text fields
                    int BookNameTxtLen = GetWindowTextLength(BookNameInput);
                    int AuthorNameTxtLen=GetWindowTextLength(AuthorNameInput);
                    int bookIDTxtLen = GetWindowTextLength(BookId);
                    int bookDescriptionTxtLen = GetWindowTextLength(BookDescriptionInput);
                    if(BookNameTxtLen >0 && AuthorNameTxtLen>0 && bookIDTxtLen >0 && bookDescriptionTxtLen>0){
                        EnableWindow(SubmitNewBookBtn,TRUE);
                    }else{
                        EnableWindow(SubmitNewBookBtn,FALSE);
                    }
                }
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
        case WM_PAINT:{
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd,&ps);
            /*if(!booksVec.empty()){
                int ypos = 20;
                for(BOOK el: booksVec){
                    automateBookShowing(el,hdc,10,ypos);
                    ypos += 10;
                }
            }*/
            if(drawInputTexts){
            TextOut(hdc,enterBookNameXpos,enterBookNameYpos,enterBookName.c_str(),enterBookName.length());
            TextOut(hdc,enterAuthorNameXpos,enterAuthorNameYpos,enterAuthorName.c_str(),enterAuthorName.length());
            TextOut(hdc,enterBookIdXpos,enterBookIdYpos,enterBookId.c_str(),enterBookId.length());
            TextOut(hdc,enterBookDescriptionXpos,enterBookDescriptionYpos,enterDescription.c_str(),enterDescription.length());
        }   else{
            TextOut(hdc,enterBookNameXpos,enterBookNameYpos,"",0);
            TextOut(hdc,enterAuthorNameXpos,enterAuthorNameYpos,"",0);
            TextOut(hdc,enterBookIdXpos,enterBookIdYpos,"",0);
            TextOut(hdc,enterBookDescriptionXpos,enterBookDescriptionYpos,"",0);
        }
            EndPaint(hWnd,&ps);
            break;
        }
        case WM_DESTROY:{
        void* Ptr = (void*)GetWindowLongPtr(hWnd,0);
        if(rc == SQLITE_OK){
        sqlite3_close(database);
        }
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
    return CreateWindowEx(WS_EX_APPWINDOW,TEXT("CurrentBooksWindow"),TEXT(""),WS_CHILD|WS_BORDER|ES_AUTOVSCROLL,CrntBooksWndXpos,CrntBooksWndYpos,CrntBooksWndWidth,crntBooksWndHeight,MainWindow,NULL,window.hInstance,NULL);
}
HWND CreateBookInfoWindow(HINSTANCE hInstance,HWND MainWindow){
    return CreateWindowEx(WS_EX_APPWINDOW,TEXT("bookinfohWnd"),TEXT("BookInfo"),WS_CHILD|WS_BORDER|WS_DISABLED|ES_MULTILINE,bookInfoWndXpos,bookInfoWndYpos,bookInfoWndWidth,bookInfoWndHeight,MainWindow,NULL,window.hInstance,NULL);
}

//create buttons
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
HWND CreateSubmitBtn(HINSTANCE hInstance, HWND MainWindow){
    return CreateWindowEx(WS_EX_APPWINDOW,TEXT("BUTTON"),TEXT("Submit Book"),WS_CHILD|WS_DISABLED|WS_VISIBLE,submitBookBtnXpos,submitBookBtnYpos,BtnWidth,BtnHeight,MainWindow,(HMENU)1005,window.hInstance,NULL);
}
/*
BookNameInput   = CreateWindowEx(0,"EDIT","",WS_CHILD|WS_VISIBLE|WS_BORDER,BookNameInputBoxXpos,BookNameInputBoxYpos,150,25,hWnd,(HMENU)1,window.hInstance,NULL);
AuthorNameInput = CreateWindowEx(0,"EDIT","",WS_CHILD|WS_VISIBLE|WS_BORDER,AuthorNameBoxXpos,AuthorNameBoxYpos,150,25,hWnd,(HMENU)2,window.hInstance,NULL);
 BookId = CreateWindowEx(0,"EDIT","",WS_CHILD|WS_VISIBLE|WS_BORDER,BookIdBoxXpos,BookIdBoxYpos,150,25,hWnd,(HMENU)3,window.hInstance,NULL);
*/
HWND createBookNameInput(HINSTANCE hInstance,HWND MainWindow){
    return CreateWindowEx(0,"EDIT","",WS_CHILD|WS_BORDER|ES_AUTOVSCROLL|ES_WANTRETURN,BookNameInputBoxXpos,BookNameInputBoxYpos,150,25,MainWindow,(HMENU)1,window.hInstance,NULL);
}
HWND createAuthorNameInput(HINSTANCE hInstance, HWND MainWindow){
    return  CreateWindowEx(0,"EDIT","",WS_CHILD|WS_BORDER|ES_AUTOVSCROLL|ES_WANTRETURN,AuthorNameBoxXpos,AuthorNameBoxYpos,150,25,MainWindow,(HMENU)2,window.hInstance,NULL);
}
HWND createBookIdInput(HINSTANCE hInstance, HWND MainWindow){
    return  CreateWindowEx(0,"EDIT","",WS_CHILD|WS_BORDER|ES_AUTOVSCROLL|ES_WANTRETURN,BookIdBoxXpos,BookIdBoxYpos,150,25,MainWindow,(HMENU)3,window.hInstance,NULL);
}
HWND createBookDescriptionInput(HINSTANCE hInstance,HWND MainWindow){
    return CreateWindowEx(0,"EDIT","",WS_CHILD|WS_BORDER|ES_MULTILINE|ES_AUTOVSCROLL|ES_WANTRETURN,bookDescriptionBoxXpos,bookDescriptionBoxYpos,150,50,MainWindow,(HMENU)4,window.hInstance,NULL);
}
HWND createBookDescriptionWindow(HINSTANCE hInstance, HWND BookInfoWnd){
    return CreateWindowEx(0,TEXT("EDIT"),"",WS_CHILD|WS_BORDER|ES_MULTILINE|WS_VISIBLE|WS_VSCROLL,bookInfoWndXpos,bookdescWNDYpos,bookInfoWndWidth,bookInfoWndHeight,BookInfoWnd,NULL,window.hInstance,NULL);
}
/*test adding a button that has the book's name and shit, assign the button to a book object (in memory after being shown), so basically everytime i retrieve data from the db
i assign each column of the table to a button and show it on the current books window screen, clicking the button displays the book's information/synopsis on the bookinfo window*/

//extra shit that will be reused later
/*while(!BookNameInput && !AuthorNameInput && !BookId){
                    /*create a new window that has these edit classes inside it but they are initially disabled until add a new book is clicked, then the info inside gets
                    stored in some temp variables to be used to create book objects which get added to the current books window
                    if(!BookNameInput){
                    BookNameInput   = CreateWindowEx(0,"EDIT","",WS_CHILD|WS_VISIBLE|WS_BORDER,BookNameInputBoxXpos,BookNameInputBoxYpos,150,25,hWnd,(HMENU)1,window.hInstance,NULL);
                }else{
                    char buffer[256];
                    GetWindowText(BookNameInput,buffer,256);
                    storedBookName = buffer;
                    MessageBox(hWnd,storedBookName.c_str(),"stored Book Name: ",MB_OK);
                }
                if(!AuthorNameInput){
                    AuthorNameInput = CreateWindowEx(0,"EDIT","",WS_CHILD|WS_VISIBLE|WS_BORDER,AuthorNameBoxXpos,AuthorNameBoxYpos,150,25,hWnd,(HMENU)2,window.hInstance,NULL);
                }else{
                    char buffer[256];
                    GetWindowText(AuthorNameInput,buffer,256);
                    storedAuthorName = buffer;
                    MessageBox(hWnd,storedAuthorName.c_str(),"stored author name:",MB_OK);
                }
                if(!BookId){
                    BookId = CreateWindowEx(0,"EDIT","",WS_CHILD|WS_VISIBLE|WS_BORDER,BookIdBoxXpos,BookIdBoxYpos,150,25,hWnd,(HMENU)3,window.hInstance,NULL);
                }else{
                    char buffer[256];
                    GetWindowText(BookId,buffer,256);
                    std::string temp = buffer;
                    char *end;
                    storedBookId = strtol(buffer,&end,10);
                    if(*end != '\0'){
                        MessageBox(NULL,TEXT("MAKE SURE YOU ENTER A NUMBER FOR THE BOOK ID"),TEXT("invalid input"),MB_ICONERROR);
                    }
                    MessageBox(hWnd,temp.c_str(),"Stored BookID",MB_OK);
                }
            }*/