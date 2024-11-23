
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

class SinhVien
{

private:
    string id_class;
    string id_student;
    float average_score;
    string name;
    int day, month, year;

public:
    void SetDate(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void SetId(int cl, string st)
    {
        id_class = cl;
        id_student = st;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    string Return_id_class()
    {
        return id_class;
    }
    string Return_id_student()
    {
        return id_student;
    }
    float Return_Average_score()
    {
        return average_score;
    }
    string Return_name()
    {
        return name;
    }
    int Return_day()
    {
        return day;
    }
    int Return_month()
    {
        return month;
    }
    int Return_year()
    {
        return year;
    }
    friend istream &operator>>(istream &in, SinhVien &x)
    {

        getline(in >> std::ws, x.id_class);

        getline(in >> std::ws, x.id_student);
        in >> x.average_score;
        in.ignore();
        getline(in, x.name);
        in >> x.day;
        in >> x.month;
        in >> x.year;
        return in;
    };
    friend ostream &operator<<(ostream &out, const SinhVien &x)
    {

        out << x.id_class << endl;
        out << x.id_student << endl;
        out << x.average_score << endl;
        out << x.name << endl;
        out << x.day << endl;
        out << x.month << endl;
        out << x.year << endl;
        return out;
    };
};
void table(vector<SinhVien> sinhvien)
{
    int sum = sinhvien.size();
    for (int i = 0; i < 113; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "|STT  |" << setw(25) << left << "NAME" << setw(20) << left << "|ID_CLASS" << setw(20) << left << "|ID_STUDENT" << setw(20) << left << "|AVERAGE_SCORE" << setw(20) << left << "|DAY" << setw(20) << "|";
    cout << endl;
    for (int i = 0; i < 113; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < sum; i++)
    {
        string day = to_string(sinhvien[i].Return_day());
        string month = to_string(sinhvien[i].Return_month());
        string year = to_string(sinhvien[i].Return_year());
        string date = day + "/" + month + "/" + year;
        cout << "|" << setw(5) << i + 1 << "|" << setw(25) << sinhvien[i].Return_name() << "|" << setw(19) << sinhvien[i].Return_id_class() << "|" << setw(19) << sinhvien[i].Return_id_student() << "|" << setw(19) << sinhvien[i].Return_Average_score() << "|" << setw(19) << date << setw(0) << "|";
        cout << endl;
    }
}
void font(int colour)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, colour);
}
////////////////////////////////////////////////////////////

void Table1(int i, int n)
{

    for (int i = 0; i < 6; i++)
    {
        cout << " ";
    }

    if (i > 100 - n) // den 40 in ra
    {

        for (int i = 0; i < 3; i++) // cot rong 30
        {
            cout << "||";
        }
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            cout << " ";
        }
    }
}
void DrawChart_statistic(int *arr)
{

    for (int i = 0; i < 100; i++)
    {
        cout << "|";
        printf("%02d ", 101 - i);
        for (int m = 0; m < 4; m++)
        {
            font(m + 1);
            Table1(i, arr[m]);
        }

        cout << endl;
    }
    for (int i = 0; i < 100; i++)
    {
        cout << "=";
    }
    cout << endl;

    for (int i = 0; i < 7; i++)
    {
        cout << " ";
    }
    cout << "Gioi " << arr[0] << "%" << "      " << "Kha " << arr[1] << "%" << "   " << "Trung binh " << arr[2] << "%" << "   " << "yeu " << arr[3] << "%";
    cout << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << "=";
    }
}

void DisplayChart()
{
    string name;
    cout << " enter class :";
    getline(cin, name);
    int gioi = 0;
    int Kha = 0;
    int Trungbinh = 0;
    int Yeu = 0;
    ifstream infile("DATA.txt", ios::in); // đọc file
    vector<SinhVien> sinhvien;            // khai báo

    SinhVien s;         // khai báo đối tượng
    while (infile >> s) // đọc file
    {
        if (s.Return_id_class() == name)
        {
            if (s.Return_Average_score() > 8)
            {
                gioi = gioi + 1;
            }
            else if (s.Return_Average_score() <= 8 && s.Return_Average_score() > 7)
            {
                Kha = Kha + 1;
            }
            else if (s.Return_Average_score() <= 7 && s.Return_Average_score() > 5)
            {
                Trungbinh = Trungbinh + 1;
            }
            else
            {
                Yeu = Yeu + 1;
            }
        }
    }
    if (gioi == 0 && Kha == 0 && Trungbinh == 0 && Yeu == 0)
    {
        cout << "id class error";
    }
    else
    {
        int a[3];
        a[0] = gioi;
        a[1] = Kha;
        a[2] = Trungbinh;
        a[3] = Yeu;
        infile.close(); // trả về vector
        int tong = gioi + Kha + Trungbinh + Yeu;
        int array[3];
        cout << endl;
        for (int i = 0; i < 4; i++)
        {
            array[i] = ((float)a[i] / tong) * 100;
        }
        font(1);
        cout << "Gioi : blue" << endl;
        font(2);
        cout << "Kha : green" << endl;
        font(3);
        cout << "Trung binh : light green" << endl;
        font(4);
        cout << "Yeu : red" << endl;
        std::cout << "                         |||||   " << std::endl;
        std::cout << "  ENTER TO DISPLAY CHART  |||   " << std::endl;
        std::cout << "                          |||   " << std::endl;
        std::cout << "                           V    " << std::endl;
        while (_getch() != 13)
        {
            // wait for enter
        }

        DrawChart_statistic(array);
    }
}

int removeDuplicates_Statistic(std::string arr[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {

                for (int k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }
    return n;
}

void Statistic_class()
{
    ifstream infile("DATA.txt", ios::in); // đọc file
    vector<SinhVien> sinhvien;            // khai báoF
    SinhVien s;
    string arr[1000];
    int i = 0;

    while (infile >> s)
    {
        arr[i] = s.Return_id_class();
        i++;
    }
    infile.close();
    int num = i;

    int n = removeDuplicates_Statistic(arr, num); // lay duoc ten lop
    int num_class[n];
    for (int i = 0; i < n; i++)
    {
        ifstream infile("DATA.txt", ios::in);
        while (infile >> s)
        {
            if (s.Return_id_class() == arr[i])
            {
                num_class[i]++; // lay duoc so lop
            }
        }
    }
    for (int i = 0; i < 37; i++)
    {
        cout << "=";
    }
    cout << endl;
    cout << "|" << setw(10) << "id_class" << setw(8) << "|" << "number of student|";
    for (int i = 0; i < n; i++)
    {
        cout << endl;

        cout << "|" << setw(9) << arr[i] << setw(9) << "|" << setw(9) << num_class[i] << setw(9) << " |";
    }
    cout << endl;
    for (int i = 0; i < 37; i++)
    {
        cout << "=";
    }
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += num_class[i];
    }
    cout << endl;
    cout << setw(20) << "Total :" << tong;
    cout << endl;
    for (int i = 0; i < 37; i++)
    {
        cout << "=";
    }
}

void Statistic_score()
{
    ifstream infile("DATA.txt", ios::in); // đọc file
    vector<SinhVien> sinhvien;            // khai báoF
    SinhVien s;
    string arr[1000];
    int i = 0;

    while (infile >> s)
    {
        arr[i] = s.Return_id_class();
        i++;
    }
    infile.close();
    int num = i;
    int g[3];
    int k[3];
    int tb[3];
    int y[3];
    int n = removeDuplicates_Statistic(arr, num); // lay duoc ten lop
    // int num_class[n];
    for (int i = 0; i < n; i++)
    {
        ifstream infile("DATA.txt", ios::in);
        while (infile >> s)
        {
            if (s.Return_id_class() == arr[i])
            {
                if (s.Return_Average_score() > 8)
                {
                    g[i] += 1;
                }
                else if (s.Return_Average_score() <= 8 && s.Return_Average_score() > 7)
                {
                    k[i] += 1;
                }
                else if (s.Return_Average_score() <= 7 && s.Return_Average_score() > 5)
                {
                    tb[i] += 1;
                }
                else
                {
                    y[i] += 1;
                }
            }
        }
        infile.close();
    }
    /////////////////////////////////////////////////////////
    int TB[3][n];
    int total[n];
    for (int i = 0; i < n; i++) // so luong class
    {
        total[i] = g[i] + k[i] + tb[i] + y[i];
    }

    for (int i = 0; i < n; i++)
    {
        TB[0][i] = (int)(((float)g[i] / total[i]) * 100);  // gioi
        TB[1][i] = (int)(((float)k[i] / total[i]) * 100);  // kha
        TB[2][i] = (int)(((float)tb[i] / total[i]) * 100); // tb
        TB[3][i] = (int)(((float)y[i] / total[i]) * 100);  // yeu
    }

    // table
    for (int i = 0; i < 100; i++)
    {
        cout << "=";
    }
    cout << endl;
    cout << left << "|" << setw(15) << "id_class"
         << "|" << setw(10) << "Gioi" << "|" << setw(5) << "%"
         << "|" << setw(10) << "Kha" << "|" << setw(5) << "%"
         << "|" << setw(12) << "Trung binh" << "|" << setw(5) << "%"
         << "|" << setw(10) << "Yeu" << "|" << setw(5) << "%" << "|";

    for (int i = 0; i < n; i++)
    {
        cout << endl;
        font(i + 1);
        cout << left << "|" << setw(15) << arr[i]
             << "|" << setw(10) << g[i] << "|" << setw(5) << TB[0][i]
             << "|" << setw(10) << k[i] << "|" << setw(5) << TB[1][i]
             << "|" << setw(12) << tb[i] << "|" << setw(5) << TB[2][i]
             << "|" << setw(10) << y[i] << "|" << setw(5) << TB[3][i] << "|";
        font(i + 1);
    }
}

void Menu_for_display_extra(int Option)
{
    system("cls");

    cout << "---- Student Management Program ----" << endl;
    for (int i = 1; i <= 3; i++)
    {
        if (i == Option)
        {

            cout << "*  =>>     ";
        }
        else
        {

            cout << "*     ";
        }
        switch (i)
        {
        case 1:
            cout << "  statistics by class " << endl;
            break;
        case 2:
            cout << "  statistics by  score " << endl;
            break;
        case 3:
            cout << "  statistics by chart score " << endl;
            break;
        }
    }
}
void Menu_for_display()
{
    int Option = 1;
    char keyboard;
    while (true)
    {

        do
        {
            Menu_for_display_extra(Option);
            keyboard = getch();
            switch (keyboard)
            {
            case 72:
                if (Option > 1)
                    Option--;
                break;
            case 80:
                if (Option < 3)
                    Option++;
                break;
            default:
                break;
            }
        } while (keyboard != 13);
        switch (Option)
        {
        case 1:
            system("cls");
            Statistic_class();
            getch();
            break;
        case 2:
            system("cls");
            Statistic_score();
            getch();
            break;
        case 3:
            system("cls");
            DisplayChart();
            getch();
            break;
        }
        if (keyboard == 13)
        {
            break;
        }
    }
}

int main()
{
    Menu_for_display();

    return 0;
}
