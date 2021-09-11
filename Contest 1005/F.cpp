#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a, b, c, d, e, h;
    a = b = c = d = e = h = 0;
    bool flag = true;
    while (flag)
    {
        e += 4;
        a = 0;
        while (flag)
        {
            a += 5;
            d = e + a / 5;
            c = d + e / 4;
            if (c % 2 != 0)
                continue;
            if (d % 3 != 0)
                continue;
            b = c + d / 3;
            if (b + c / 2 < a)
                break;
            if (b + c / 2 == a)
                flag = false;
        }
    }
 
    h = 2 * a + b;
    cout << h<<endl;
    cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e;
    //system("pause > nul");
}