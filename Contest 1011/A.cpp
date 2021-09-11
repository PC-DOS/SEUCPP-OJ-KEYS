#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int a[7],i;
    for (i = 0; i <= 6; ++i){
        cin >> a[i];
    }
    if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && a[3] == a[4] && a[4] == a[5] && a[5] == a[6]){
        cout << "EQUAL";
    }
    else if (a[0] <= a[1] && a[1] <= a[2] && a[2] <= a[3] && a[3] <= a[4] && a[4] <= a[5] && a[5] <= a[6]){
        cout << "UP";
    }
    else if (a[0] >= a[1] && a[1] >= a[2] && a[2] >= a[3] && a[3] >= a[4] && a[4] >= a[5] && a[5] >= a[6]){
        cout << "DOWN";
    }
    else{
        cout << "OTHER";
    }
    //system("pause > nul");
    return 0;
}