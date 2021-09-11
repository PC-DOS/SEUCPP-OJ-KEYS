#include <iostream>
using namespace std;
int main(){
    const double pi = 3.14159;
    double h, r, V;
    cin >> h >> r;
    V = pi*r*r*h;
    cout << int(20000 / V) + 1;
    //system("pause > nul");
    return 0;
}