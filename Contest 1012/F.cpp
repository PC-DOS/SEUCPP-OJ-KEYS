#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
string strReverse(string strOrigin){
    long i;
    string ans;
    for (i = strOrigin.length() - 1; i >= 0; --i) ans += strOrigin[i];
    return ans;
}
string strLeft(string strOrigin, int nCount){
    if (nCount >= strOrigin.length()) return strOrigin;
    long i;
    string ans("");
    for (i = 0; i <= nCount - 1; ++i){
        ans += strOrigin[i];
    }
    return ans;
}
string strRight(string strOrigin, int nCount){
    if (nCount >= strOrigin.length()) return strOrigin;
    long i;
    string ans("");
    for (i = strOrigin.length() - 1;; --i){
        ans += strOrigin[i];
        if (ans.length() == nCount) break;
    }
    ans = strReverse(ans);
    return ans;
}
bool isStringAllSpace(string sTest){
    long i;
    for (i = 0; i <= sTest.length() - 1; ++i){
        if (sTest[i] != ' ') return false;
    }
    return true;
}
bool isStringAllZero(string sToTest){
    int i;
    for (i = 0; i <= sToTest.length() - 1; ++i){
        if (sToTest[i] != '0'){
            return false;
            break;
        }
    }
    return true;
}
string toUpper(string sOrigin){
    string ans("");
    long i;
    for (i = 0; i <= sOrigin.length() - 1; ++i){
        if (sOrigin[i] >= 'a' && sOrigin[i] <= 'z')
            ans += char(sOrigin[i] + ('A' - 'a'));
        else
            ans += sOrigin[i];
    }
    return ans;
}
string toLower(string sOrigin){
    string ans("");
    long i;
    for (i = 0; i <= sOrigin.length() - 1; ++i){
        if (sOrigin[i] >= 'A' && sOrigin[i] <= 'Z')
            ans += char(sOrigin[i] + ('a' - 'A'));
        else
            ans += sOrigin[i];
    }
    return ans;
}
long long to_int(string sNumber){
    long long i;
    long long lRet = 0;
    if (sNumber.length() == 0)
        return 0;
    sNumber = strReverse(sNumber);
    if (sNumber[sNumber.length() - 1] == '-'){
        for (i = 0; i <= sNumber.length() - 2; ++i)
            if ('0' <= sNumber[i] && sNumber[i] <= '9')lRet += (sNumber[i] - '0')*pow(10, i);
        return -lRet;
    }
    else{
        for (i = 0; i <= sNumber.length() - 1; ++i)
            if ('0' <= sNumber[i] && sNumber[i] <= '9')lRet += (sNumber[i] - '0')*pow(10, i);
        return lRet;
    }
}
int main(){
    string s1, s2("");
    bool isInNum = false;
    getline(cin, s1);
    long long i, lSum = 0;
    for (i = 0; i <= s1.length() - 1; ++i){
        if (s1[i] >= '0' && s1[i] <= '9' ){
            s2 += s1[i];
            isInNum = true;
        }
        if (!(s1[i] >= '0' && s1[i] <= '9') && isInNum){
            lSum += to_int(s2);
            s2 = "";
            isInNum = false;
        }
    }
    if (s2 != "") lSum += to_int(s2);
    cout << lSum;
    //system("pause > nul");
    return 0;
}