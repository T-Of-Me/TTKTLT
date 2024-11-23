
#include <iomanip>
#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

void font(int colour)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, colour);
}

int main()
{
    for (int i = 17; i < 30; i++)
    {
        font(i);
        cout << "dasdasd" << endl;
        font(i);
    }
 
}