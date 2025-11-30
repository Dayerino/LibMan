#ifndef HEADER
#define HEADER
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <vector>
#include <string>
#include "bookclass.h"
#include "sqlite3.h"
#include <vector>
#include <algorithm>
#include "unordered_map"
WNDCLASS window = {};
HWND hWnd;
HWND TitleWindow; 
HWND crntbookshWnd;
HWND bookinfohWnd;
int * Ptr;
void registerMainWindow(HINSTANCE hInstance);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void registercurrentBooksWindow(HINSTANCE hInstance);
LRESULT CALLBACK currentBooksWndProc(HWND crntbookshWnd, UINT message, WPARAM wParam, LPARAM lParam);
HWND createMainWindow(HINSTANCE hInstance);
HWND createTitleWindow(HINSTANCE hInstance,HWND MainWindow);
HWND CreateCurrentBooksWindow(HINSTANCE hInstance,HWND MainWindow);
HWND CreateBookInfoWindow(HINSTANCE hInstance,HWND MainWindow);
void registerBookInfoWindow(HINSTANCE hInstance);
LRESULT CALLBACK BookInfoWindowProc(HWND bookinfohWnd,UINT message,WPARAM wParam,LPARAM lParam);

//buttons:

HWND ShowBooksBtn;
HWND AddBookBtn;
HWND ModifyBookBtn;
HWND RemoveBookBtn;
HWND SubmitNewBookBtn;
HWND CreateShowAllBooksButton(HINSTANCE hInstance,HWND MainWindow);
HWND CreateAddBookButton(HINSTANCE hInstance, HWND MainWindow);
HWND CreateModifyBookButton(HINSTANCE hInstance,HWND MainWindow);
HWND CreateRemoveBookButton(HINSTANCE hInstance,HWND MainWindow);
HWND CreateSubmitBtn(HINSTANCE hInstance, HWND MainWindow);
LRESULT CALLBACK ButtonWindowsProc(HWND BtnWndProc,UINT message,WPARAM wParam, LPARAM lParam);
void registerBtnWindow(HINSTANCE hInstance);


//text input fields:
HWND BookNameInput;
HWND AuthorNameInput;
HWND BookId;
HWND BookDescriptionInput;
BOOK newObj;
std::string storedBookName;
std::string storedAuthorName;
int storedBookId;
HWND createBookNameInput(HINSTANCE hInstance,HWND MainWindow);
HWND createAuthorNameInput(HINSTANCE hInstance, HWND MainWindow);
HWND createBookIdInput(HINSTANCE hInstance, HWND MainWindow);
HWND createBookDescriptionInput(HINSTANCE hInstance,HWND MainWindow);
//

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
    "Arial"   
    );/*font test*/
//metrics
int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);
int windowWidth = screenWidth *0.3;
int windowHeight = screenHeight * 0.6;
int windowXpos = (screenWidth - windowWidth)/2;
int windowYpos = (screenHeight - windowHeight)/2;
int TitleWindowWidth = windowWidth*0.99;
int TitleWindowHeight = windowHeight * 0.07;
int TitleWindowXpos =0;
int TitleWindowYpos = windowHeight *0.01;
int CrntBooksWndWidth = windowWidth *0.5;
int CrntBooksWndXpos = 0;
int CrntBooksWndYpos = TitleWindowYpos + (windowHeight *0.07);
int crntBooksWndHeight = windowHeight * 0.351;
int bookInfoWndWidth = windowWidth * 0.5;
int bookInfoWndHeight= windowHeight - crntBooksWndHeight;
int bookInfoWndXpos=0;
int bookInfoWndYpos=crntBooksWndHeight + (windowHeight *0.08);
int BtnWidth = windowWidth *0.48;
int BtnHeight=windowWidth *0.1;
int showBooksBtnXpos=windowWidth *0.5;
int showBooksBtnYpos=CrntBooksWndYpos;
int addBookBtnXpos = showBooksBtnXpos;
int addBookBtnYpos = showBooksBtnYpos + BtnHeight;
int modifyBookBtnXpos=showBooksBtnXpos;
int modifyBookBtnYpos = addBookBtnYpos+ BtnHeight ;
int removeBookBtnXpos = showBooksBtnXpos;
int removeBookBtnYpos=modifyBookBtnYpos + BtnHeight;
int submitBookBtnXpos= showBooksBtnXpos;
int submitBookBtnYpos= removeBookBtnYpos + (windowHeight * 0.4);
int  addedBooksYPos = 20;

int enterBookNameXpos = showBooksBtnXpos + (windowWidth *0.03);
int enterBookNameYpos = removeBookBtnYpos + (windowHeight * 0.11);
int BookNameInputBoxXpos =  enterBookNameXpos + (windowWidth * 0.17);
int BookNameInputBoxYpos = removeBookBtnYpos + (windowHeight *0.1);
int enterAuthorNameXpos=enterBookNameXpos;
int enterAuthorNameYpos = BookNameInputBoxYpos + (windowHeight * 0.06);
int AuthorNameBoxXpos= enterAuthorNameXpos + (windowWidth * 0.17);
int AuthorNameBoxYpos =BookNameInputBoxYpos + (windowHeight *0.05);
int enterBookIdXpos=enterBookNameXpos;
int enterBookIdYpos = AuthorNameBoxYpos + (windowHeight * 0.06);
int enterBookDescriptionXpos = enterBookNameXpos;
int enterBookDescriptionYpos = enterBookIdYpos + (windowHeight * 0.06);
int BookIdBoxXpos= enterBookIdXpos + (windowWidth * 0.17);
int BookIdBoxYpos = AuthorNameBoxYpos + (windowHeight *0.05);
int bookDescriptionBoxXpos =  enterBookDescriptionXpos + (windowWidth * 0.17);
int bookDescriptionBoxYpos = BookIdBoxYpos + (windowHeight *0.05);
std:: string enterBookName = "Book Name:";
std::string enterAuthorName = "Author Name:";
std:: string enterBookId = "Book Id:";
std:: string enterDescription = "Description:";
/*the function below might have to be remade*/
void automateBookShowing(BOOK& bookObject,HDC hdc,int xpos,int ypos){
    /*TextOut(hdc,xpos,ypos,bookObject.getBookTitle().c_str(),bookObject.getBookTitle().length());
    TextOut(hdc,xpos,ypos +20,bookObject.getBookAuthor().c_str(),bookObject.getBookAuthor().length());
    int bookID= bookObject.getBookID();
    std::string bookIDstr = std::to_string(bookID);
    TextOut(hdc,xpos,ypos + 35,bookIDstr.c_str(),bookIDstr.length());*/
    TextOut(hdc,xpos,ypos,bookObject.getBookDescription().c_str(),bookObject.getBookDescription().length());
}
bool drawInputTexts = false;
/*get the texts from the user*/
std::string GetTextFromInput(HWND hwnd){
    std:: string text;
    int txtLen = GetWindowTextLength(hwnd);
    text.resize(txtLen + 1);
    int textSize = GetWindowText(hwnd,&text[0],txtLen + 1 );
    text.resize(textSize);
    return text;
}
/*what im trying to do:
check the textinput fields, the text inside will be added as params to a new book object which will be stored somewhere
so we got the button, the three text fields and a new book object*/
//sql & database settings
const char* schema = "CREATE TABLE IF NOT EXISTS Books(bookName TEXT PRIMARY KEY,authorName TEXT,bookID INTEGER,BookDescription TEXT);";
sqlite3 * database;
int rc;
std::vector<BOOK> booksVec;
void addBookToDB(sqlite3* db,BOOK & bookObj){
    const char* sql = "INSERT INTO Books (bookName, authorName, bookID,BookDescription) VALUES (?,?,?,?);"; 
    sqlite3_stmt* statement;
    if(sqlite3_prepare_v2(db,sql,-1,&statement,nullptr)== SQLITE_OK){
        sqlite3_bind_text(statement,1,bookObj.getBookTitle().c_str(),-1,SQLITE_TRANSIENT);
        sqlite3_bind_text(statement,2,bookObj.getBookAuthor().c_str(),-1,SQLITE_TRANSIENT);
        sqlite3_bind_int(statement,3,bookObj.getBookID());
        sqlite3_bind_text(statement,4,bookObj.getBookDescription().c_str(),-1,SQLITE_TRANSIENT);
    if(sqlite3_step(statement) != SQLITE_DONE){
        MessageBox(hWnd,"insert error","error",MB_ICONERROR);
        }
    else{
        MessageBox(hWnd,"insert successfull!","success",MB_ICONEXCLAMATION);
    }
    }
    sqlite3_finalize(statement);
}
/*show all books in the database*/
void retrieveALLFromDB(sqlite3* db,std::vector<BOOK>& booksVec){
    const char* sql = "SELECT * FROM Books";
    sqlite3_stmt* statement;
    if(sqlite3_prepare_v2(db,sql,-1,&statement,nullptr) == SQLITE_OK){
        while(sqlite3_step(statement) == SQLITE_ROW){
            const unsigned char* bookName = sqlite3_column_text(statement,0);
            const unsigned char* AuthorName = sqlite3_column_text(statement,1);
            int bookID = sqlite3_column_int(statement,2);
            const unsigned char* bookDescription= sqlite3_column_text(statement,3);
            BOOK newObj(std::string(reinterpret_cast<const char*>(bookName)),std::string(reinterpret_cast<const char*>(AuthorName)),bookID,std::string(reinterpret_cast<const char*>(bookDescription)));
            booksVec.push_back(newObj);
        }
    }
}
/*book buttons measurements */
int bookBtnXpos = CrntBooksWndXpos ;
int bookBtnYpos = CrntBooksWndYpos *0.1;
int bookBtnWidth = CrntBooksWndWidth;
int bookBtnHeight= crntBooksWndHeight * 0.1;
std::vector<BOOK>usedBooks;
std::unordered_map<int, BOOK>BooksMap;
struct bookWindows{
    int wParam;
    HWND BTNWINDOW;
};
int selectedBookWparam;
std::vector<bookWindows> bookbuttons;
BOOK foundBook;
int bookBtnWparam = 5000;
void createBookButtons(HWND ParentWindow,sqlite3*db,std::vector<BOOK>&booksVec,std::vector<BOOK>&usedBooks,std::unordered_map<int,BOOK>&BooksMap,std::vector<bookWindows>&bookBtnsVec){
    retrieveALLFromDB(db,booksVec);
    for(BOOK el:booksVec){
        if(std::find(usedBooks.begin(),usedBooks.end(),el)== usedBooks.end()){//had to create equality operator to proprely check books
        std::string bookName = el.getBookTitle();
        std:: string AuthorName = el.getBookAuthor();
        int bookID = el.getBookID();
        std:: string BtnText = bookName + " | " + AuthorName;
        //problem with this line
        HWND BTNWINDOW = CreateWindowEx(WS_EX_APPWINDOW,TEXT("BUTTON"),TEXT(BtnText.c_str()),WS_CHILD|WS_VISIBLE,bookBtnXpos,bookBtnYpos,bookBtnWidth,bookBtnHeight,ParentWindow,(HMENU)bookBtnWparam,window.hInstance,NULL);
        /*store the added book in a map, the key is the wparam and the value is the book object itself, to retrieve it when the button is pressed*/
        BooksMap.emplace(bookBtnWparam,el);
        bookWindows newWindow = {bookBtnWparam,BTNWINDOW};
        bookBtnsVec.push_back(newWindow);
        bookBtnWparam++;
        bookBtnYpos = bookBtnYpos + bookBtnHeight;
        usedBooks.push_back(el);
    }
}
}
void shiftBTNS(HWND ParentWindow,HWND BTN,std::vector<bookWindows>&bookButtonsVec){
    auto it = std::find_if(bookButtonsVec.begin(),bookButtonsVec.end(),[BTN](const bookWindows & bookwnd){
        return bookwnd.BTNWINDOW == BTN;
    });
    if(it != bookButtonsVec.end()){

        HWND btn2shift = it->BTNWINDOW;
    }
}

/*modify a book */
void modifyBookfromDB(sqlite3* db, BOOK & bookObj){

}
/*delete a book from db*/
//basically, remove the book from the db, then reshow buttons

void deleteFromDB(sqlite3*db,std::string BookTitle){
    const char* sql = "DELETE FROM Books WHERE bookName = ?";
    sqlite3_stmt* statement;
        if(sqlite3_prepare_v2(db,sql,-1,&statement,nullptr)== SQLITE_OK){
            sqlite3_bind_text(statement,1,BookTitle.c_str(),-1,SQLITE_TRANSIENT);
            if(sqlite3_step(statement) != SQLITE_DONE){
                MessageBox(hWnd,"deletion error","error",MB_ICONERROR);
            }
            else{
                MessageBox(hWnd,"book deleted!","success",MB_ICONINFORMATION);
            }
        }
    }
void deleteBookBTN(std::vector<bookWindows>&BookBTNS,int wParam){
    auto it = std::find_if(BookBTNS.begin(),BookBTNS.end(),[wParam](const bookWindows& bookwnd){
        return bookwnd.wParam == wParam; 
    });
    if(it != BookBTNS.end()){
        HWND windowTodestroy = it->BTNWINDOW;
        /*grab the y pos of the btn, if its the last element do nothing, if not move the element that's after it to its position, and the same to the one after that, until you
        reach the end*/
        size_t index = std::distance(BookBTNS.begin(),it);
        size_t vecSize = BookBTNS.size();
        if(index < BookBTNS.size()-1){//check if the index of the element is NOT the last element
        for(size_t i =  index; i<vecSize - 1;i++){
        RECT rect;
        GetWindowRect(BookBTNS[i].BTNWINDOW,&rect);
        POINT pt = {rect.left,rect.top};
        MapWindowPoints(HWND_DESKTOP,crntbookshWnd,&pt,1);
        int y = pt.y;
        int x = pt.x;
            SetWindowPos(BookBTNS[i+1].BTNWINDOW,HWND_TOP,x,y,0,0,SWP_NOSIZE);
        }
    }
        if(DestroyWindow(windowTodestroy)){
        BookBTNS.erase(it);
        
        }
    }
}
/*[wParam](const bookWindows& bookwnd){
        return bookwnd.wParam == wParam; }); lambda function used here */
#endif