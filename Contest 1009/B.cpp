#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int a[7],i,nZero=0;
    for (i = 0; i <= 6; ++i) cin >> a[i];
    for (i = 0; i <= 6; ++i){
        if (a[i] != 0){
            cout << a[i] << ' ';
        }
        else
            ++nZero;
    }
    for (i = 1; i <= nZero - 1; ++i) cout << '0' << ' ';
    cout << '0';
    //system("pause > nul");
    return 0;
}