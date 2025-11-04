#ifndef HEADER
#define HEADER
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <vector>
#include <string>
#include "bookclass.h"
WNDCLASS window = {};
HWND hWnd;
HWND TitleWindow; 
HWND CurrentBooksWindow;
HWND BookInfoWindow;
HWND ShowBooksBtn;
HWND AddBookBtn;
HWND ModifyBookBtn;
HWND RemoveBookBtn;
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
HWND CreateShowAllBooksButton(HINSTANCE hInstance,HWND MainWindow);
HWND CreateAddBookButton(HINSTANCE hInstance, HWND MainWindow);
HWND CreateModifyBookButton(HINSTANCE hInstance,HWND MainWindow);
HWND CreateRemoveBookButton(HINSTANCE hInstance,HWND MainWindow);
LRESULT CALLBACK ButtonWindowsProc(HWND BtnWndProc,UINT message,WPARAM wParam, LPARAM lParam);
void registerBtnWindow(HINSTANCE hInstance);
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
int CrntBooksWndWidth = windowWidth *0.4;
int CrntBooksWndHeight = windowHeight *0.3;
int CrntBooksWndXpos = 0;
int CrntBooksWndYpos = TitleWindowYpos + (windowHeight *0.07);
int crntBooksWndWidth = windowWidth *0.2;
int crntBooksWndHeight = windowHeight * 0.3;
int bookInfoWndWidth = windowWidth * 0.5;
int bookInfoWndHeight= windowHeight - crntBooksWndHeight;
int bookInfoWndXpos=0;
int bookInfoWndYpos=crntBooksWndHeight + (windowHeight *0.08);
int BtnWidth = windowWidth *0.48;
int BtnHeight=windowWidth *0.1;
int showBooksBtnXpos=windowWidth *0.5;
int showBooksBtnYpos=bookInfoWndYpos;
int addBookBtnXpos = showBooksBtnXpos;
int addBookBtnYpos = showBooksBtnYpos + BtnHeight;
int modifyBookBtnXpos=showBooksBtnXpos;
int modifyBookBtnYpos = addBookBtnYpos+ BtnHeight ;
int removeBookBtnXpos = showBooksBtnXpos;
int removeBookBtnYpos=modifyBookBtnYpos + BtnHeight;
BOOK newObj;
void automateBookShowing(BOOK& bookObject,HDC hdc,int xpos,int ypos){
    TextOut(hdc,xpos,ypos,bookObject.getBookTitle().c_str(),bookObject.getBookTitle().length());
    TextOut(hdc,xpos,ypos +20,bookObject.getBookAuthor().c_str(),bookObject.getBookAuthor().length());
    int bookID= bookObject.getBookID();
    std::string bookIDstr = std::to_string(bookID);
    TextOut(hdc,xpos,ypos + 40,bookIDstr.c_str(),bookIDstr.length());
}
#endif