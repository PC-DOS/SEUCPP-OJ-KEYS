#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int i, j, a[3][4];
    for (i = 0; i <= 2; ++i){
        for (j = 0; j <= 3; ++j){
            cin >> a[i][j];
        }
    }
    for (i = 0; i <= 2; ++i){
        cout << a[i][3] << ' ';
        for (j = 0; j <= 2; ++j){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    //system("pause > nul");
    return 0;
}