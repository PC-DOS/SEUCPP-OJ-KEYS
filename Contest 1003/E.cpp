#include <iostream>
#include <cmath>
using namespace std;
bool isLeap(int lpYear){
    if (((lpYear % 100 != 0) && (lpYear % 4 == 0)) || ((lpYear % 100 == 0) && (lpYear % 400 == 0)))
        return true;
    else
        return false;
}
 
int main(){
    int y;
    //for (i = 0; i <= 3; ++i) yleap[i] = 0;
    cin >> y;
    if (isLeap(y))
        cout << y;
    else{
        if (isLeap(y - 1))
            cout << y - 1;
        else if (isLeap(y + 1))
            cout << y + 1;
        else if (isLeap(y - 2) && isLeap(y + 2))
            cout << y - 2 << ' ' << y + 2;
        else if (isLeap(y - 2))
            cout << y - 2;
        else if (isLeap(y - 3))
            cout << y - 3;
        else if (isLeap(y + 3))
            cout << y + 3;
        else
            cout << y + 2;
    }
    //system("pause > nul");
}