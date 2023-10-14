#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        double A = max(a, b);
        double B = min(a, b);
        int count = 0;
        while (A > B)
        {
            count++;
            double sub = A - B;
            if (sub >= c)
            {
                A = A - c;
                B = B + c;
            }
            else
            {
                double sub2 = (A - B) / 2;
                A = A - sub2;
                B = B + sub2;
            }
        }
        cout << count << endl;
    }
}
