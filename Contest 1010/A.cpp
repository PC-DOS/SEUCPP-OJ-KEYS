#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int a[10][10];
    int N;
    long lSum = 0;
    int i, j;
    cin >> N;
    for (i = 0; i <= N - 1; ++i){
        for (j = 0; j <= N - 1; ++j){
            cin >> a[i][j];
        }
    }
    for (i = 0; i <= N - 1; ++i){
        lSum += a[i][i];
    }
    for (i = N - 1; i >= 0; --i){
        if (N % 2 != 0 && i == N-1-i) continue;
        lSum += a[N - 1 - i][i];
    }
    cout << lSum;
    //system("pause > nul");
    return 0;
}