# B - Compare T-Shirt Sizes
## 題目  
Two T-shirt sizes are given: a
 and b
. The T-shirt size is either a string M or a string consisting of several (possibly zero) characters X and one of the characters S or L.

For example, strings M, XXL, S, XXXXXXXS could be the size of some T-shirts. And the strings XM, LL, SX are not sizes.

The letter M stands for medium, S for small, L for large. The letter X refers to the degree of size (from eXtra). For example, XXL is extra-extra-large (bigger than XL, and smaller than XXXL).

You need to compare two given sizes of T-shirts a
 and b
.

The T-shirts are compared as follows:

any small size (no matter how many letters X) is smaller than the medium size and any large size;
any large size (regardless of the number of letters X) is larger than the medium size and any small size;
the more letters X before S, the smaller the size;
the more letters X in front of L, the larger the size.
For example:

* XXXS < XS
* XXXL > XL
* XL > M
* XXL = XXL
* XXXXXS < M
* XL > XXXS    
***
**input:**  
The first line of the input contains a single integer t
 (1≤t≤104
) — the number of test cases.

Each test case consists of one line, in which a
 and b
 T-shirt sizes are written. The lengths of the strings corresponding to the T-shirt sizes do not exceed 50
. It is guaranteed that **`all sizes are correct`**.  
***
**output:**  
For each test case, print on a separate line the result of comparing a
 and b
 T-shirt sizes (lines "<", ">" or "=" without quotes).  
 ***
 ### sample
 t=6  
 |T-Shirt Sizes(1)|T-Shirt Sizes(2)|output|
 |----------------|----------------|------|
 |XXXS | XS|<|
 |XXXL |XL|>|
 |XL |M|>|
 |XXL |XXL|=|
 |XXXXXS |M|>|
 |L | M|>|  
 ***
 ## 解題
 **要先了解以下狀況**
 >1. `L`**永遠大於** `M`或`S`(**不管加了幾個X**)
> 2. `M`**永遠大於**`S`(**不管加了幾個X**)
> 3. `尾號`相同
>    >1. `L`:`X`越多==>越大
>    >2. `S`:`X`越多==>越小
> 5. `M`**沒有在加X的**(ex:`XM` is wrong size)

這樣就能決定如何比較大小
>1. 看兩個是否相同大小
>2. 比尾號(尾號不同就略`3.`)
>3. 比`X`
***

## 程式碼
我婆真香(兩個都是):   
![](https://github.com/archie0732/CPEB1012/blob/main/picture1/yaemiko001.jpg)  
[點我進入](https://github.com/archie0732/CPEB1012/blob/main/B/B_Compare_T_Shirt_Sizes.cpp)  
`cpp:`
```cpp
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
```
