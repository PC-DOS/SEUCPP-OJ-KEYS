#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int a[3][3];
    int i, j;
    for (i = 0; i <= 2; ++i){
        for (j = 0; j <= 2; ++j){
            cin >> a[i][j];
        }
    }
    cout << a[2][0] << ' ' << a[1][0] << ' ' << a[0][0] << endl;
    cout << a[2][1] << ' ' << a[1][1] << ' ' << a[0][1] << endl;
    cout << a[2][2] << ' ' << a[1][2] << ' ' << a[0][2] << endl;
    //system("pause > nul");
    return 0;
}