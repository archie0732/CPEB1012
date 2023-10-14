# D - The Corridor or There and Back Again
## 題目
[題目連結](https://vjudge.net/contest/587230#problem/C)  
You are in a corridor that extends infinitely to the right, divided into square rooms. You start in room 1
, proceed to room k
, and then return to room 1
. You can choose the value of k
. Moving to an adjacent room takes 1
 second.

Additionally, there are n
 traps in the corridor: the i
-th trap is located in room di
 and will be activated si
 seconds after you enter the room di
. Once a trap is activated, you cannot enter or exit a room with that trap.  
![](https://github.com/archie0732/CPEB1012/blob/main/picture1/2023-10-14%20200844.png)  
A schematic representation of a possible corridor and your path to room k
***
 and back.<br>   
 <br>
 Determine the maximum value of k
 that allows you to travel from room 1
 to room k
 and then return to room 1
 safely.
***
For instance, if n=1
 and d1=2,s1=2
, you can proceed to room k=2
 and return safely (the trap will activate at the moment 1+s1=1+2=3
, it can't prevent you to return back). But if you attempt to reach room k=3
, the trap will activate at the moment 1+s1=1+2=3
, preventing your return (you would attempt to enter room 2
 on your way back at second 3
, but the activated trap would block you). Any larger value for k
 is also not feasible. Thus, the answer is k=2
.  
***
**input:**  
The first line of the input contains an integer t
 (1≤t≤1000
) — the number of test cases.

The descriptions of the test cases follow.

The first line of each test case description contains an integer n
 (1≤n≤100
) — the number of traps.

The following n
 lines of each test case description present two integers di
 and si
 (1≤di,si≤200
) — the parameters of a trap (you must leave room di
 strictly before si
 seconds have passed since entering this room). It's possible for multiple traps to occupy a single room (the values of di
 can be repeated).  
 ***
 **output:**  
 For each test case, print the maximum value of k
 that allows you to travel to room k
 and return to room 1
 without encountering an active trap  
 ***
 ### Sample 1
 t=7
 |trap number|trap distance |active second|output|
 |-----------|--------------|-------------|------|
 |1|2 |2|2|
 |3|2<br>4<br>5|8<br>3<br>2|5|
 |1|200 |200|299|
 |4|1<br>5<br>3<br>100|20<br>9<br>179<br>1|9|
 |2|10<br>1|1<br>18|9|
 |2|1<br>1|1<br>2|1|
 |3|1<br>1<br>1|3<br>1<br>3|1|  
 ***
 ### note
 The first test case is explained in the problem statement above.

In the second test case, the second trap prevents you from achieving k≥6
. If k≥6
, the second trap will activate at the moment 3+s2=3+3=6
 (the time you enter room 4
 plus s2
). In the case of k≥6
, you will return to room 4
 at time 7
 or later. The trap will be active at that time. It can be shown that room k=5
 can be reached without encountering an active trap.

In the third test case, you can make it to room 299
 and then immediately return to room 1
.  
***
## 解題
暫無
***
## 程式碼
![](https://github.com/archie0732/CPEB1012/blob/main/picture1/5467cb0da93ac9858a7a43ef7780130194d96b3b.jpg1256w_1260h_!web-article-pic.jpg)  

[點我進入](https://github.com/archie0732/CPEB1012/blob/main/D/D_The_Corridor_or_There_and_Back_Again.cpp)

```cpp
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
```
