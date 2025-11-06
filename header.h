#ifndef HEADER
#define HEADER
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <vector>
#include <string>
#include "bookclass.h"

//main windows:

WNDCLASS window = {};
HWND hWnd;
HWND TitleWindow; 
HWND CurrentBooksWindow;
HWND BookInfoWindow;
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
BOOK newObj;
std::string storedBookName;
std::string storedAuthorName;
int storedBookId;
HWND createBookNameInput(HINSTANCE hInstance,HWND MainWindow);
HWND createAuthorNameInput(HINSTANCE hInstance, HWND MainWindow);
HWND createBookIdInput(HINSTANCE hInstance, HWND MainWindow);

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
int submitBookBtnYpos= removeBookBtnYpos + (windowHeight * 0.25);

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
int BookIdBoxXpos= enterBookIdXpos + (windowWidth * 0.17);
int BookIdBoxYpos = AuthorNameBoxYpos + (windowHeight *0.05);
std:: string enterBookName = "Book Name:";
std::string enterAuthorName = "Author Name:";
std:: string enterBookId = "Book Id:";
void automateBookShowing(BOOK& bookObject,HDC hdc,int xpos,int ypos){
    TextOut(hdc,xpos,ypos,bookObject.getBookTitle().c_str(),bookObject.getBookTitle().length());
    TextOut(hdc,xpos,ypos +20,bookObject.getBookAuthor().c_str(),bookObject.getBookAuthor().length());
    int bookID= bookObject.getBookID();
    std::string bookIDstr = std::to_string(bookID);
    TextOut(hdc,xpos,ypos + 40,bookIDstr.c_str(),bookIDstr.length());
}
bool drawInputTexts = false;
/*what im trying to do:
check the textinput fields, the text inside will be added as params to a new book object which will be stored somewhere
so we got the button, the three text fields and a new book object*/
#endif