#include <iostream>
#include <vector> //一開始以為會用到
#include <string> //原本要用find

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        string t1, t2; // input 1 2
        string n1, n2; // 字尾號碼 (沒試過不知道char行不行)
        /*
        核心思路:(暴力解)
        0.一樣直接輸出"="
        1.先比尾號(尾號大小確定再多X也沒用)
        2.尾號相同看是S還是L
        3.X越多在S中越小在L中越大，反之

        p.s. 題目不存在XM、LL等非正常衣服尺寸。故不用另外排除
        */
        cin >> t1 >> t2;
        n1 = t1[t1.length() - 1]; // 抓取字尾(S、M、L)
        n2 = t2[t2.length() - 1]; // 抓取字尾(S、M、L)

        if (t1 == t2) // same
        {
            cout << "=" << endl;
        }
        else if (n1 == "L" && n2 != "L") // L  >( M or S )
        {
            cout << ">" << endl;
        }
        else if (n1 != "L" && n2 == "L")
        {
            cout << "<" << endl;
        }
        else if (n1 == "M" && n2 == "S") // also S  >　M
        {
            cout << ">" << endl;
        }
        else if (n2 == "M" && n1 == "S")
        {
            cout << "<" << endl;
        }
        else if (n1 == "S" && n2 == "S") // 在S號中 X越多代表越小
        {
            if (t1.length() > t2.length())
            {
                cout << "<" << endl;
            }
            else
            {
                cout << ">" << endl;
            }
        }
        else if (n1 == "L" && n2 == "L") // 在L號中，X越多代表越大
        {
            if (t1.length() > t2.length())
            {
                cout << ">" << endl;
            }
            else
            {
                cout << "<" << endl;
            }
        }
    }

    return 0;
}
