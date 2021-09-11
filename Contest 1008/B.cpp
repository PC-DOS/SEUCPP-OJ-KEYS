#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
int GetNum(int n){
    if (n == 1 || n == 2)
        return 1;
    else if (n == 3)
        return 2;
    else
        return GetNum(n - 1) + GetNum(n - 2)+GetNum(n-3);
}
int main(){
    int n;
    cin >> n;
    cout << GetNum(n);
    //system("pause > nul");
    return 0;
}