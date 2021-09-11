#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int i,a[7],t;
    for (i = 0; i <= 6; ++i) cin >> a[i];
    i = 0;
    if (a[i] > a[i + 1]){
        t = a[i];
        a[i] = a[i + 1];
        a[i + 1] = t;
    }
    for (i = 1; i <= 5; i+=2){
        if (a[i] <= a[i + 1]){
            t = a[i];
            a[i] = a[i + 1];
            a[i + 1] = t;
        }
    }
    for (i = 0; i <= 5; i += 2){
        if (a[i] >= a[i + 1]){
            t = a[i];
            a[i] = a[i + 1];
            a[i + 1] = t;
        }
    }
    for (i = 0; i <= 5; ++i) cout << a[i]<<' ';
    cout << a[6];
    //system("pause > nul");
    return 0;
}