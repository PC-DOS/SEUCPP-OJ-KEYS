#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int i, j, n=0, count;
    int dada[10][10] = { 0 };
    int M;
    cin >> M;
    n = M;
    count = 1;
    for (i = 0; i<(n + 1) / 2; i++){
        for (j = i; j<n - i; j++){
            dada[i][j] = count++;
        }
        for (j = i + 1; j<n - i; j++){
            dada[j][n - i - 1] = count++;
        }
        for (j = n - i - 2; j >= i; j--){
            dada[n - i - 1][j] = count++;
        }
        for (j = n - i - 2; j>i; j--){
            dada[j][i] = count++;
        }
    }
    for (i = 0; i<n; i++){
        for (j = 0; j<n; j++){
            cout << dada[i][j] << ' ';
        }
        cout << endl;
    }
 
    //system("pause > nul");
    return 0;
}