/**
 * channel
 * @author 綾華的狗
 * @link https://codeforces.com/problemset/problem/1863/A
 */
#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        ll sub, online, no, read, flag = 0;
        string s;
        cin >> sub >> online >> no;
        cin >> s;
        if (sub == online)
        {
            cout << "YES" << endl;
            continue;
        }
        read = online;
        for (ll i = 0; i < no; i++)
        {
            if (s[i] == '+')
            {
                read++;
                online++;
            }
            else
            {
                read--;
            }
            if (read == sub)
            {
                flag = 1; // mark
                break;
            }
        }
        if (flag == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            if (online >= sub)
            {
                cout << "MAYBE" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
