#ifndef HEADER
#define HEADER
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <vector>
WNDCLASS window = {};
HWND hWnd;
HWND TitleWindow; 
HWND CurrentBooksWindow;
int * Ptr;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void registerMainWindow(HINSTANCE hInstance);
void registercurrentBooksWindow(HINSTANCE hInstance);
LRESULT CALLBACK currentBooksWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
HWND createMainWindow(HINSTANCE hInstance);
HWND createTitleWindow(HINSTANCE hInstance,HWND MainWindow);
HWND CreateCurrentBooksWindow(HINSTANCE hInstance,HWND MainWindow);
HWND CreateBookInfoWindow(HINSTANCE hInstance,HWND MainWindow);
HWND CreateShowAllBooksButton(HINSTANCE hInstance,HWND MainWindow);
HWND CreateAddBookButton(HINSTANCE hInstance, HWND MainWindow);
HWND CreateModifyBookButton(HINSTANCE hInstance,HWND MainWindow);
HWND CreateRemoveBookButton(HINSTANCE hInstance,HWND MainWindow);
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
int TitleWindowXpos = windowWidth * 0.01;
int TitleWindowYpos = windowHeight *0.01;
int CrntBooksWndWidth = windowWidth *0.4;
int CrntBooksWndHeight = windowHeight *0.3;
int CrntBooksWndXpos = windowWidth * 0.01;
int CrntBooksWndYpos = TitleWindowYpos + (windowHeight *0.07);
int crntBookInfWndWidth = windowWidth *0.2;
int crntBookInfWndHeight = windowHeight * 0.3;
#endif