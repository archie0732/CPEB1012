#include <iostream>
#include <vector>
#define ll long long int

using namespace std;

int main(int argc, char const *argv[])
{
    int t, n;
    cin >> t;
    while (t--)
    {
        int ans, count = 0;
        cin >> n;
        vector<ll> v(n);

        /*
        核心思路:
        1.找到糖果數量最少的盒子
        2.把(其他盒子糖果的數量)-最少糖果的數量
        */

        cin >> v[0]; // 在這裡是為了避免等等可能會產生V[-1]<V[0]的情況
        ans = v[0];
        for (int i = 1; i < n; i++) // 因為v[0]已經輸入了，從v[1]開始迴圈
        {
            cin >> v[i];
            if (ans > v[i]) // 找到最少糖果的盒子裡糖果的數量
            {
                ans = v[i];
            }
        }
        // 開始計算要吃掉幾顆
        for (int i = 0; i < n; i++)
        {
            if (ans < v[i]) // 盒子內的數量不是最小的數量
            {
                count = (v[i] - ans) + count; // 吃掉糖果+已經累積吃掉的糖果
            }
        }

        cout << count << endl;
    }

    return 0;
}
