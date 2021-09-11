#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int a[7], i;
bool isExist(int n, int ptr){
    int j;
    for (j = 0; j <= ptr - 1; ++j){
        if (a[j] == n)
            return true;
    }
    return false;
}
int main(){
    bool p=false;
    for (i = 0; i <= 6; ++i){
        cin >> a[i];
        if (isExist(a[i], i))
            p = true;
    }
    if (p)
        cout << "YES";
    else
        cout << "NO";
    //system("pause > nul");
    return 0;
}