#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int a[3][4];
    double avgStu[3], avgCls[4];
    double tmp=0;
    int i, j;
    for (i = 0; i <= 2; ++i){
        for (j = 0; j <= 3; ++j){
            cin >> a[i][j];
        }
    }
    for (i = 0; i <= 2; ++i){
        for (j = 0; j <= 3; ++j){
            tmp += a[i][j];
        }
        avgStu[i] = tmp / 4.0;
        tmp = 0;
    }
    for (i = 0; i <= 3; ++i){
        for (j = 0; j <= 2; ++j){
            tmp += a[j][i];
        }
        avgCls[i] = tmp / 3.0;
        tmp = 0;
    }
    cout << avgStu[0] << ' ' << avgStu[1] << ' ' << avgStu[2] << endl;
    cout << avgCls[0] << ' ' << avgCls[1] << ' ' << avgCls[2] << ' ' << avgCls[3] << ' ' << endl;
    //system("pause > nul");
    return 0;
}