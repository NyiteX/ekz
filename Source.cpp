#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

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
            cout << "Файл не открыт.\n";
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
                cout << "Введите букву: ";
                cin >> b;
                if (b.size() > 1 || Proverka(b) == 0)
                    cout << "Это не буква =/\n\n";
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
                    cout << "\n\t~~~~~~~~~~ Вы проиграли. ~~~~~~~~~~\n\n";
                    double time2 = clock();
                    bookvi.resize(bookvi.size() - 2);
                    cout << "Времени затрачено: " << (time2 - time1) / 1000 << " сек.\n";
                    cout << "Буквы, введённые игроком: " << bookvi << ".\n";
                    cout << "Кол-во неудачных попыток: " << m << ".\n";
                    cout << "Искомое слово: " << words[id] << ".\n";
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
                        cout << "\n\t~~~~~~~~~~ Победа! ~~~~~~~~~~\n\n";
                        double time2 = clock();
                        bookvi.resize(bookvi.size() - 2);
                        cout << "Времени затрачено: " << (time2 - time1) / 1000 << " сек.\n";
                        cout << "Буквы, введённые игроком: " << bookvi << ".\n";
                        cout << "Кол-во неудачных попыток: " << m << ".\n";
                        cout << "Искомое слово: " << words[id] << ".\n";
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
    char vvod;
    do
    {
        system("cls");
        cout << "1. Игра.\nESC. Выход.\n";
        vvod = _getch();
        switch (vvod)
        {
        case'1':
        {
            A.PrintWords();
            A.Play();

            system("pause");
            break;
        }
        }
    } while (vvod != 27);

    return 0;
}