# F - Increasing and Decreasing
[題目連結](https://vjudge.net/contest/587230#problem/F)
***
## 題目
You are given three integers x
, y
, and n
.

Your task is to construct an array a
 consisting of n
 integers which satisfies the following conditions:

1. a1=x
, an=y
;
2. a
 is strictly increasing (i.e. a1<a2<…<an
);
3. if we denote bi=ai+1−ai
 for 1≤i≤n−1
, then b
 is strictly decreasing (i.e. b1>b2>…>bn−1
).  

If there is no such array a
, print a single integer −1
.  
***
**input:**  
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤1000
). The description of the test cases follows.

The only line of each test case contains three integers x
, y
, n
 (1≤x<y≤1000,3≤n≤1000
).  
***
**output:**  
For each test case, output n
 integers a1,a2,…,an
. If there are multiple solutions, print any of them.

**If there is no solution, print a single integer −1**
.  
***
### sample :
t=3
|x|y|n|output|
|-|-|-|------|
|1|4|3|1 3 4|
|1|3|3|-1|
|100|200|4|100 150 180 200|
***
### 解題
暫無
***
## 程式碼
![](https://github.com/archie0732/CPEB1012/blob/main/F/v0EMdcL.jpg)
[點我進入](https://github.com/archie0732/CPEB1012/blob/main/F/F_Increasing_and_Decreasing.cpp)  

`c++:`
```cpp
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
```


