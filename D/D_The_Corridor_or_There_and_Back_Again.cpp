#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, time, k = INT_MAX;
        cin >> n;
        vector<pair<int, int>> trap(n);
        for (int i = 0; i < trap.size(); i++)
        {
            cin >> trap[i].first >> trap[i].second;
        }
        for (int i = 0; i < trap.size(); i++)
        {
            k = std::min(trap[i].first + (trap[i].second - 1) / 2, k);
        }
        cout << k << endl;
    }

    return 0;
}
