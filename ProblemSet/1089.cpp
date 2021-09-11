#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    double a, b, c, x1, x2;
    double delta;
    cin >> a >> b >> c;
    delta = b*b - 4 * a*c;
    if (delta < 0){
        cout << "NO";
        exit(0);
    }
    x1 = (-b - sqrt(delta)) / (2 * a);
    x2 = (-b + sqrt(delta)) / (2 * a);
    cout << x1 << ' ' << x2;
    //system("pause > nul");
    return 0;
}