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
using namespace std;
void font(int colour)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, colour);
}
void Table1(int i, int n)
{

    for (int i = 0; i < 10; i++)
    {
        cout << " ";
    }

    if (i > 100 - n) // den 40 in ra
    {

        for (int i = 0; i < 5; i++) // cot rong 30
        {
            cout << "||";
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            cout << " ";
        }
    }
}

void DrawTable()
{

    for (int i = 0; i < 100; i++)
    {
        cout << "==";
        font(1);
        Table1(i, 100);
        font(2);
        Table1(i, 11);
        font(3);
        Table1(i, 48);
         font(4);
        Table1(i, 17);

        cout << endl;
    }
    for (int i = 0; i < 600; i++)
    {
        cout << "=";
    }
}
void set()
{
    cout << "|" << setw(25) << "|";
}
int main()
{
    // set();
    DrawTable();
    return 0;
}