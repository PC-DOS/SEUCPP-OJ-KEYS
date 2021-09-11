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
int main(){
    string s1, s2("");
    long long iMove, i;
    getline(cin, s1);
    cin >> iMove;
    iMove = iMove%s1.length();
    s2 = strLeft(s1, iMove);
    s1 = strRight(s1, s1.length() - iMove);
    cout << s1 << s2;
    //system("pause > nul");
    return 0;
}