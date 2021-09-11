#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int i, j,n,a[10][10];
    int ans[10][10] = {0};
    cin >> n;
    for (i = 0; i <= n - 1; ++i){
        for (j = 0; j <= n - 1; ++j){
            cin >> a[i][j];
            if (a[i][j] == 1)
                ans[i][j] = -1;
        }
    }
    for (i = 0; i <= n - 1; ++i){
        for (j = 0; j <= n - 1; ++j){
            if (ans[i][j] == -1) continue;
            if (i == 0 && j == 0){
                if (ans[0][1] ==-1) ++ans[i][j];
                if (ans[1][1] ==-1) ++ans[i][j];
                if (ans[1][0] == -1) ++ans[i][j];
            }
            else if (i == 0 && j == n-1){
                if (ans[0][n-2] ==-1) ++ans[i][j];
                if (ans[1][n-1] ==-1) ++ans[i][j];
                if (ans[1][n-2] ==-1) ++ans[i][j];
            }
            else if (i == n-1 && j == 0){
                if (ans[n-1][1] ==-1) ++ans[i][j];
                if (ans[n-2][0] ==-1) ++ans[i][j];
                if (ans[n-2][1] ==-1) ++ans[i][j];
            }
            else if (i == n-1 && j == n-1){
                if (ans[n-1][n-2] ==-1) ++ans[i][j];
                if (ans[n-2][n-1] ==-1) ++ans[i][j];
                if (ans[n-2][n-2] ==-1) ++ans[i][j];
            }
            else if (i == 0){
                if (ans[0][j - 1] ==-1) ++ans[i][j];
                if (ans[0][j + 1] ==-1) ++ans[i][j];
                if (ans[1][j - 1] ==-1) ++ans[i][j];
                if (ans[1][j] == -1) ++ans[i][j];
                if (ans[1][j + 1] ==-1) ++ans[i][j];
            }
            else if (i == n-1){
                if (ans[i][j - 1] ==-1) ++ans[i][j];
                if (ans[i][j + 1] ==-1) ++ans[i][j];
                if (ans[i-1][j - 1] ==-1) ++ans[i][j];
                if (ans[i-1][j] ==-1) ++ans[i][j];
                if (ans[i-1][j + 1] ==-1) ++ans[i][j];
            }
            else if (j == 0){
                if (ans[i-1][j] ==-1) ++ans[i][j];
                if (ans[i+1][j] ==-1) ++ans[i][j];
                if (ans[i-1][j + 1] ==-1) ++ans[i][j];
                if (ans[i][j+1] ==-1) ++ans[i][j];
                if (ans[i + 1][j + 1] ==-1) ++ans[i][j];
            }
            else if (j == n-1){
                if (ans[i - 1][j] == -1) ++ans[i][j];
                if (ans[i + 1][j] == -1) ++ans[i][j];
                if (ans[i][j-1] == -1) ++ans[i][j];
                if (ans[i-1][j- 1] == -1) ++ans[i][j];
                if (ans[i + 1][j - 1] == -1) ++ans[i][j];
            }
            else{
                if (ans[i][j - 1] == -1) ++ans[i][j];
                if (ans[i][j + 1] == -1) ++ans[i][j];
                if (ans[i - 1][j + 1] == -1) ++ans[i][j];
                if (ans[i - 1][j] == -1) ++ans[i][j];
                if (ans[i - 1][j - 1] == -1) ++ans[i][j];
                if (ans[i + 1][j + 1] == -1) ++ans[i][j];
                if (ans[i + 1][j] == -1) ++ans[i][j];
                if (ans[i + 1][j - 1] == -1) ++ans[i][j];
            }
        }
    }
    for (i = 0; i <= n - 1; ++i){
        for (j = 0; j <= n - 1; ++j){
            if (ans[i][j] != -1)
                cout << ans[i][j] << ' ';
            else
                cout << '*' << ' ';
        }
        cout << endl;
    }
    //system("pause > nul");
    return 0;
}