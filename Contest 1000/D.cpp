#include <iostream>
using namespace std;
int main(){
    double h,r,V,S1,S2;
    const double pi = 3.14;
    cin >> h >> r;
    V = h*pi*r*r;
    S1 = 2 * pi*r*h;
    S2 = S1 + 2 * pi*r*r;
    cout << V << ' ' << S1 << ' ' << S2;
    //system("pause > nul");
}