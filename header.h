#ifndef HEADER
#define HEADER
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <vector>
WNDCLASS window = {};
int * Ptr;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void registerWindow(HINSTANCE hInstance);
HWND createMainWindow(HINSTANCE hInstance);
int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);
int windowWidth = screenWidth *0.3;
int windowHeight = screenHeight * 0.6;
int windowXpos = (screenWidth - windowWidth)/2;
int windowYpos = (screenHeight - windowHeight)/2;
#endif