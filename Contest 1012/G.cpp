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
bool isIn(string s1, string s2, long long iStart){
    string stmp("");
    long long j, i;
    for (i = iStart; i <= s1.length() - s2.length(); ++i){
        for (j = 0; j <= s2.length() - 1; ++j){
            stmp += char(s1[i+j]);
        }
        //cout << stmp<<endl;
        if (stmp == s2) return true;
        stmp = "";
    }
    return false;
}
int main(){
    string s1, s2("");
    int iCompareMode = 0, iCompareStart = 0;
    getline(cin, s1);
    getline(cin, s2);
    cin >> iCompareStart >> iCompareMode;
    if (iCompareMode == 0){
        if (isIn(s1, s2, iCompareStart))
            cout << "YES";
        else
            cout << "NO";
    }
    else{
        if (isIn(toLower(s1), toLower(s2), iCompareStart))
            cout << "YES";
        else
            cout << "NO";
    }
    //system("pause > nul");
    return 0;
}