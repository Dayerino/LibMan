#include "header.h"
#include "WindowSource.cpp"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    registerMainWindow(hInstance);
    registercurrentBooksWindow(hInstance);
    registerBookInfoWindow(hInstance);
    hWnd = createMainWindow(hInstance);
    TitleWindow = createTitleWindow(hInstance,hWnd);
    crntbookshWnd = CreateCurrentBooksWindow(hInstance,hWnd);
    bookinfohWnd = CreateBookInfoWindow(hInstance,hWnd);
    ShowBooksBtn = CreateShowAllBooksButton(hInstance,hWnd);
    AddBookBtn = CreateAddBookButton(hInstance,hWnd);
    ModifyBookBtn=CreateModifyBookButton(hInstance,hWnd);
    RemoveBookBtn=CreateRemoveBookButton(hInstance,hWnd);
    SubmitNewBookBtn = CreateSubmitBtn(hInstance,hWnd);
    BookNameInput = createBookNameInput(hInstance,hWnd);
    AuthorNameInput= createAuthorNameInput(hInstance,hWnd);
    BookId = createBookIdInput(hInstance,hWnd);
    BookDescriptionInput = createBookDescriptionInput(hInstance,hWnd);
    descriptionWindow = createBookDescriptionWindow(hInstance,bookinfohWnd);
    SendMessage(TitleWindow,WM_SETFONT,(WPARAM)hFont,TRUE);
    MSG msg;
    ShowWindow(hWnd,SW_SHOW);
    ShowWindow(TitleWindow,SW_SHOW);//child windows must be shown aswell, they dont appear automatically after their parents
    UpdateWindow(TitleWindow);
    ShowWindow(crntbookshWnd,SW_SHOW);
    UpdateWindow(crntbookshWnd);
    ShowWindow(bookinfohWnd,SW_SHOW);
    UpdateWindow(bookinfohWnd);
    ShowWindow(bookinfohWnd,SW_SHOW);
    UpdateWindow(hWnd);
    //sqlite things:
    rc = sqlite3_open("database.sqlite",&database);
    if(rc != SQLITE_OK){
        MessageBox(hWnd,"database isnt opening","error",MB_ICONERROR);
    }
    rc = sqlite3_exec(database,schema,nullptr,nullptr,nullptr);
    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}