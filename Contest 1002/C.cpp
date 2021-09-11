#include <iostream>
using namespace std;
bool IsLeapYear(int nYear){
    if ((nYear % 100 != 0 && nYear % 4 == 0) || (nYear % 100 == 0 && nYear % 400 == 0))
        return true;
    else
        return false;
}
int MonthCalc(int nMonth){
    if (nMonth == 1 || nMonth == 3 || nMonth == 5 || nMonth == 7 || nMonth == 8 || nMonth == 10 || nMonth == 12)
        return 31;
    else
        return 30;
}
int main(){
    int m,y;
    cin >> y >> m;
    if (m == 2){
        if (IsLeapYear(y)){
            cout << "29";
        }
        else{
            cout << "28";
        }
    }
    else
        cout << MonthCalc(m);
    //system("pause > nul");
}