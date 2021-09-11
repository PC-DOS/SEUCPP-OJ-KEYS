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
string strReverse(string strOrigin){
    if (strOrigin.length() == 0){
        return "";
    }
    long long i;
    string ans;
    for (i = strOrigin.length() - 1; i >= 0; --i) ans += strOrigin[i];
    return ans;
}
string ToRadix(long long iOrig, int iRadixTarget){
    if (iRadixTarget == 10)
        return to_string(iOrig);
    if (iRadixTarget <= 1 || iRadixTarget > 36)
        return "";
    string ans("");
    long long i, iTemp;
    char arrSeed[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    i = iOrig%iRadixTarget;
    iTemp = iOrig / iRadixTarget;
    while (iTemp != 0){
        if (i < 10)
            ans += to_string(i);
        else
            ans += arrSeed[i - 10];
        i = iTemp%iRadixTarget;
        iTemp = iTemp / iRadixTarget;
    }
    if (i < 10)
        ans += to_string(i);
    else
        ans += arrSeed[i - 10];
    return strReverse(ans);
}
int main(){
    ios::sync_with_stdio(false);
    long long iNum;
    int iTarget;
    cin >> iNum >> iTarget;
    cout << ToRadix(iNum, iTarget);
endapp:
    //system("pause > nul");
    return 0;
}