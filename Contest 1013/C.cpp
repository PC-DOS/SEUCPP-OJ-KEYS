#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct Date{
    int iYear,iDay,iMonth;
};
int main(){
    ios::sync_with_stdio(false);
    Date dteBirth, dteDeath;
    string sName;
    cin >> sName >> dteBirth.iYear >> dteBirth.iMonth >> dteBirth.iDay >> dteDeath.iYear >> dteDeath.iMonth >> dteDeath.iDay;
    cout << "Name:" << sName << endl << "Birth:" << dteBirth.iYear << '-' << dteBirth.iMonth << '-' << dteBirth.iDay << endl << "Death:" << dteDeath.iYear << '-' << dteDeath.iMonth << '-' << dteDeath.iDay;
endapp:
    //system("pause > nul");
    return 0;
}