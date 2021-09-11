#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <map>
#include <climits>
#include <bitset>
using namespace std;
#define MATH_PI 3.14159265358979323846
struct Weapon{
    string sType;
    string sName;
    string sHurt;
};
int main(){
    ios::sync_with_stdio(false);
    vector<Weapon> arrWeapon;
    Weapon wepTemp;
    string sType;
    int i;
    while (cin >> sType){
        if (sType == "END")
            break;
        wepTemp.sType = sType;
        cin >> wepTemp.sName >> wepTemp.sHurt;
        arrWeapon.push_back(wepTemp);
    }
    for (i = 0; i < arrWeapon.size(); ++i){
        cout << arrWeapon[i].sType << " name:" << arrWeapon[i].sName << " damage:" << arrWeapon[i].sHurt << endl;
    }
endapp:
    //system("pause > nul");
    return 0;
}