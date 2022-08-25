#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

static bool win = false;

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

    void PrintWords() 
    {
        cout << "\t\t\t|";
        int u = rand() % words.size();
        id = u;
        for (int i = 0; i < words[u].size(); i++)
        {
            if (i % 2 == 0)
            {
                wo += "*";
                wo += "|";
            }
            else
            {
                wo += words[u][i];
                wo += "|";
            }
        }
        cout << wo << endl;
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
            cout << "‘айл не открыт.\n";
    }
    void Play()
    {
        int m = 0;
        while(win == false)
        {
            string b = "1";
            while (b.size() > 1 || Proverka(b) == 0)
            {
                cout << "¬ведите букву: ";
                cin >> b;
            }
            for (int i = 0; i < words[id].size(); i++)
            {
                if (words[id][i] == b[0])
                {
                    wo.clear();
                    cout << "\t\t\t|";
                    for (int u = 0; u < words[id].size(); u++)
                    {
                        if (u % 2 != 0 || words[id][u] == b[0])
                        {                           
                            wo += words[id][u];
                            wo += "|";
                        }
                        else
                        {
                            wo += "*";
                            wo += "|";
                        }
                    }
                    cout << wo << endl;
                    break;
                }
                else
                {
                    cout << v[m];
                    m++;
                }
            }
            bool f = false;
            for (int i = 0; i < words[id].size(); i++)
            {
                if (words[id][i] == '*')
                {
                    f = false;
                    break;
                }
                else
                    f = true;
            }
            /*if (f == true)
                win = true;*/
        }
    }
};


int main()
{
    srand(time(0));
    setlocale(LC_ALL, "ru");
    string path = "vis.txt" ;

    Vis A;
    A.LoadfromFile(path);

    A.PrintWords();
    A.Play();


    return 0;
}