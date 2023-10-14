#include <iostream>
#include <vector>
#define oo long long

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        oo x, y, n, c = 1;
        cin >> x >> y >> n;

        vector<oo> v(n);
        v[n - 1] = y;
        v[0] = x;
        for (oo i = n - 2; i >= 1; i--) // f u
        {
            v[i] = v[i + 1] - c;
            c++; //
        }
        if ((v[1] - v[0]) > (v[2] - v[1]))
        {
            for (oo i = 0; i < n; i++)
            {
                cout << v[i] << " ";
            }
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}
