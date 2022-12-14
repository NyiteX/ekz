#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void GoToXY(short x, short y)
{
    SetConsoleCursorPosition(hStdOut, { x, y });
}
void ConsoleCursorVisible(bool show, short size)
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
bool Proverka(const string& b)
{
    if (isalpha(b[0]) != 0)
        return 1;
    else
        return 0;
}

class Vis
{
    string wo;
    int id;
    vector<string>words;
    vector<string>v{

    {
        "\n"
        "\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      /   \\          $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      / | \\          $\n"
        "        |             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      / | \\          $\n"
        "        |             $\n"
        "       / \\           $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    }
    };
public:
    Vis() {};

    void PrintStr(const string& str)
    {
        system("cls");
        cout << "\t\t\t|";
        for (int i = 0; i < str.size(); i++)
        {
            cout << str[i] << "|";
        }
        cout << endl;
    }
    void PrintWords() 
    {      
        int u = rand() % words.size();
        id = u;
        for (int i = 0; i < words[u].size(); i++)
        {
            if (i % 2 == 0)
                wo += "*";
            else
                wo += words[u][i];
        }
        PrintStr(wo);
    }  
    void LoadfromFile(const string& path)
    {
        ifstream op(path);
        if (op.is_open())
        {
            string str;
            while (!op.eof())
            {            
                getline(op, str);
                words.push_back(str);
            }
            op.close();
        }
        else
            cout << "???? ?? ??????.\n";
    }
    void Play()
    {
        int m = 0;
        bool f = false;
        bool keep = false;
        string bookvi;
        while (keep == false)
        {
            double time1 = clock();
            string b = "1";
            bool l = false;
            while (b.size() > 1 || Proverka(b) == 0)
            {
                cout << "??????? ?????: ";
                cin >> b;
                if (b.size() > 1 || Proverka(b) == 0)
                    cout << "??? ?? ????? =/\n\n";
            }
            bookvi += b + ", ";
            for (int i = 0; i < words[id].size(); i++)
            {
                if (words[id][i] == b[0])
                {
                    wo[i] = b[0];
                    l = true;
                }
            }
            if (l == true)           
                PrintStr(wo);
            else
            {
                system("cls");
                PrintStr(wo);
                cout << v[m];
                if (m < v.size() - 1)
                    m++;
                else
                {
                    keep = true;
                    cout << "\n\t~~~~~~~~~~ ?? ?????????. ~~~~~~~~~~\n\n";
                    double time2 = clock();
                    bookvi.resize(bookvi.size() - 2);
                    cout << "??????? ?????????: " << (time2 - time1) / 1000 << " ???.\n";
                    cout << "?????, ????????? ???????: " << bookvi << ".\n";
                    cout << "???-?? ????????? ???????: " << m << ".\n";
                    cout << "??????? ?????: " << words[id] << ".\n";
                }
            }
            if (!keep)
            {
                for (int i = 0; i < wo.size(); i++)
                {
                    if (wo[i] == '*')
                    {
                        f = false;
                        break;
                    }
                    else
                        f = true;
                }
                if (f == true)
                {
                    keep = true;
                    if(m<v.size()-1)
                    {
                        cout << "\n\t~~~~~~~~~~ ??????! ~~~~~~~~~~\n\n";
                        double time2 = clock();
                        bookvi.resize(bookvi.size() - 2);
                        cout << "??????? ?????????: " << (time2 - time1) / 1000 << " ???.\n";
                        cout << "?????, ????????? ???????: " << bookvi << ".\n";
                        cout << "???-?? ????????? ???????: " << m << ".\n";
                        cout << "??????? ?????: " << words[id] << ".\n";
                    }
                }
            }                
        }
        wo.clear();
    }
    ~Vis()
    {
        words.clear();
        v.clear();
    }
};

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "ru");
    string path = "vis.txt";
    Vis A;
    A.LoadfromFile(path);

    SetConsoleTitle(L"DA");
    system("cls");
    system("Color 0D");
    ConsoleCursorVisible(false, 100);

    string Menu[] = { "????", "?????" };
    int active_menu = 0;

    char ch;
    while (true)
    {      
        int x = 33, y = 17;
        GoToXY(x, y);
        
        for (int i = 0; i < size(Menu); i++)
        {
            if (i == active_menu)
                SetConsoleTextAttribute(hStdOut, 8);
            else
                SetConsoleTextAttribute(hStdOut, 7);
            GoToXY(x, y++);
            cout << Menu[i] << endl;
        }
        ch = _getch();
        if (ch == -32) ch = _getch();
        switch (ch)
        {
        case ESC:
            exit(0);
        case UP:
            if (active_menu > 0)
                --active_menu;
            break;
        case DOWN:
            if (active_menu < size(Menu) - 1)
                ++active_menu;
            break;
        case ENTER:
            switch (active_menu)
            {
            case 0:
            {
                system("cls");
                GoToXY(x, y);
                SetConsoleTextAttribute(hStdOut, 8);
                A.PrintWords();
                A.Play();
                _getch();
                system("cls");
                break;
            }
            case 1:
                exit(0);
            }
        }
    }
}