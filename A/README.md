# A - Equal Candies
## 題目

[題目連結](https://vjudge.net/contest/587230#problem)

There are n
 boxes with different quantities of candies in each of them. The i
-th box has ai
 candies inside.

You also have n
 friends that you want to give the candies to, so you decided to give each friend a box of candies. But, you don't want any friends to get upset so you decided to eat some (possibly none) candies from each box so that **`all boxes have the same quantity of candies in them`**. Note that you may eat a different number of candies from different boxes and you **`cannot add candies to any of the boxes`**.

What's the ``minimum`` total number of candies you have to eat to satisfy the requirements?
***
* <strong>input:</strong>

The first line contains an integer t
(1≤t≤1000
) — the number of test cases.

The first line of each test case contains an integer n
 (1≤n≤50
) — the number of boxes you have.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤107
) — the quantity of candies in each box.

* <strong>output:</strong>

For each test case, print a single integer denoting the `minimum` number of candies you have to eat to satisfy the requirements.
***

### sample 
* input

t=5
| input   (n)   | input(a)      | output|
| ------------- |:-------------:| -----:|
|  5            | 1 2 3 4 5 |10 |
|  6            | 1000 1000 5 1000 1000 1000     |   4975 |
|  10           | 1 2 3 5 1 2 7 9 13 5      |    38 |
|  3            |8 8 8 | 0|
|  1            | 10000000 |0|

***

## 解題
**首先要了解以下幾個條件**

>1.不能把糖果換到其他盒  
>2.只能用減少(吃)的方式來達成平衡(每盒糖果數量相同)

所以我們能得出一個結論:  
要把**所有盒子的糖果數量**`減少`到跟**最少糖果數量**的盒子相同
***
### 工具
**不會的可以參考連結**  

1. vector (尚未製作)
2. defind (尚未製作)
***
### 程式碼

![](https://github.com/archie0732/CPEB1012/blob/main/picture1/ayaka002.jpg)

* [點我進入](https://github.com/archie0732/CPEB1012/blob/main/A/A_Equal_Candies.cpp)
  
`#cpp`
```cpp
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
```

