#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
long long moneytotal(int days){
    return pow(2, days) - 1;
}
int main(){
    long long money;
    cin >> money;
    if (money*100*30 < moneytotal(30))
        cout << "NO";
    else
        cout << "YES";
    //system("pause > nul");
    return 0;
}