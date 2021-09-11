#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
 
int main() {
    double ans;
    double tmp;
    int n;
    ans = 0;
    n = 1;
    tmp = 1;
    ++n;
    while (fabs(tmp) >= pow(10, -6)){
        ans += tmp;
        tmp = double(pow(-1, n - 1) / (2 * n - 1));
        //cout << 4 * ans<<endl;
        ++n;
    };
    cout << 4*ans;
    //system("pause>nul");
    return 0;
}