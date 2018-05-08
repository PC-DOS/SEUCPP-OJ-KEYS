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
string strLeft(string strOrigin, long long nCount){
    if (nCount >= strOrigin.length()) return strOrigin;
    long long i;
    string ans("");
    if (strOrigin.length() == 0){
        return ans;
    }
    for (i = 0; i <= nCount - 1; ++i){
        ans += strOrigin[i];
    }
    return ans;
}
string strRight(string strOrigin, long long nCount){
    if (nCount >= strOrigin.length()) return strOrigin;
    long long i;
    string ans("");
    if (strOrigin.length() == 0){
        return ans;
    }
    for (i = strOrigin.length() - 1;; --i){
        ans += strOrigin[i];
        if (ans.length() == nCount) break;
    }
    ans = strReverse(ans);
    return ans;
}
string strMid(string strOrigin, long long iStart, long long iLength){
    string ans("");
    if (iStart > strOrigin.length() - 1) return ans;
    if (strOrigin.length() == 0){
        return ans;
    }
    long long i;
    for (i = iStart;; ++i){
        ans += strOrigin[i];
        if (i >= strOrigin.length() - 1) break;
        if (ans.length() == iLength) break;
    }
    return ans;
}
bool IsStringAllSpace(string sTest){
    if (sTest.length() == 0){
        return false;
    }
    long long i;
    for (i = 0; i <= sTest.length() - 1; ++i){
        if (sTest[i] != ' ') return false;
    }
    return true;
}
bool IsStringAllZero(string sToTest){
    if (sToTest.length() == 0){
        return false;
    }
    long long i;
    for (i = 0; i <= sToTest.length() - 1; ++i){
        if (sToTest[i] != '0'){
            return false;
            break;
        }
    }
    return true;
}
string ToUpper(string sOrigin){
    string ans("");
    if (sOrigin.length() == 0){
        return ans;
    }
    long long i;
    for (i = 0; i <= sOrigin.length() - 1; ++i){
        if (sOrigin[i] >= 'a' && sOrigin[i] <= 'z')
            ans += char(sOrigin[i] + ('A' - 'a'));
        else
            ans += sOrigin[i];
    }
    return ans;
}
string ToLower(string sOrigin){
    string ans("");
    if (sOrigin.length() == 0){
        return ans;
    }
    long long i;
    for (i = 0; i <= sOrigin.length() - 1; ++i){
        if (sOrigin[i] >= 'A' && sOrigin[i] <= 'Z')
            ans += char(sOrigin[i] + ('a' - 'A'));
        else
            ans += sOrigin[i];
    }
    return ans;
}
long long ToInt(string sNumber){
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
bool PathernMatch(char *sWildcard, char *sString)
{
    char *s = NULL;
    char *p = NULL;
    bool bStarChar = false;
    bool bBreak = false;
    do{
        bBreak = false;
        for (s = sString, p = sWildcard; *s; ++s, ++p){
            switch (*p){
            case '?':
                break;
            case '*':
                bStarChar = true;
                sString = s;
                sWildcard = p;
                if (!*++sWildcard)
                    return true;
                bBreak = true;
                break;
            default:
                if (*s != *p){
                    if (!bStarChar)
                        return false;
                    sString++;
                    bBreak = true;
                }
                break;
            }
            if (bBreak)
                break;
        }
        if (bBreak == false){
            if (*p == '*')
                ++p;
            return (!*p);
        }
    } while (true);
}
bool IsMatch(string sString1, string sString2, bool lpUseWildcard = false){
    if (!lpUseWildcard)
        return sString1 == sString2;
    else{
        return PathernMatch(const_cast<char*>(sString1.c_str()), const_cast<char*>(sString2.c_str()));
    }
}
double ToDouble(string sNumber, bool &IsErrorOccurred){
    long long i;
    IsErrorOccurred = false;
    if (sNumber.length() == 0){
        IsErrorOccurred = true;
        return 0;
    }
    for (i = 0; i <= sNumber.length() - 1; ++i){
        if (!((sNumber[i] <= '9' && sNumber[i] >= '0') || (sNumber[i] == '-') || (sNumber[i] == '.'))){
            IsErrorOccurred = true;
            return 0;
        }
    }
    stringstream ssStream;
    double dReturn;
    ssStream << sNumber;
    ssStream >> dReturn;
    ssStream.clear();
    return dReturn;
}
long long ToInt(string sNumber, bool &IsErrorOccurred){
    long long i;
    long long lRet = 0;
    IsErrorOccurred = false;
    if (sNumber.length() == 0){
        IsErrorOccurred = true;
        return 0;
    }
    for (i = 0; i <= sNumber.length() - 1; ++i){
        if (!((sNumber[i] <= '9' && sNumber[i] >= '0') || (sNumber[i] == '-'))){
            IsErrorOccurred = true;
            break;
        }
    }
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
long long ToDec(string sOrig, int iRadixOrig){
    if (sOrig.length() == 0)
        return 0;
    if (iRadixOrig > 36 || iRadixOrig <= 1)
        return 0;
    long long iAns = 0;
    sOrig = strReverse(sOrig);
    sOrig = ToUpper(sOrig);
    long long i;
    bool IsPositive = true;
    if (sOrig[sOrig.length() - 1] == '-')
        IsPositive = false;
    for (i = 0; i <= sOrig.length() - 1; ++i){
        if (sOrig[i] >= '0' && sOrig[i] <= '9')
            iAns += (sOrig[i] - '0')*pow(iRadixOrig, i);
        else if (sOrig[i] >= 'A' && sOrig[i] <= 'Z')
            iAns += (sOrig[i] - 'A' + 10)*pow(iRadixOrig, i);
        else
            iAns += 0;
    }
    if (IsPositive)
        return iAns;
    else
        return -iAns;
}
string CreateRequiedString(long long nCount, char chrChrarater){
    int i;
    string sAns;
    for (i = 1; i <= nCount; ++i)
        sAns += chrChrarater;
    return sAns;
}
inline bool IsInteger(double dNum){
    return (dNum == int(dNum));
}
inline bool IsNum(char chrTest){
    return (chrTest >= '0' && chrTest <= '9');
}
inline bool IsAllLower(string sTest, bool bStrictMode = false){
    if (sTest.length() == 0)
        return false;
    register int i;
    if (!bStrictMode){
        for (i = 0; i < sTest.length(); ++i){
            if (sTest[i] >= 'A' && sTest[i] <= 'Z')
                return false;
        }
        return true;
    }
    else{
        for (i = 0; i < sTest.length(); ++i){
            if (!(sTest[i] >= 'a' && sTest[i] <= 'z'))
                return false;
        }
        return true;
    }
}
inline bool IsAllUpper(string sTest, bool bStrictMode = false){
    if (sTest.length() == 0)
        return false;
    register int i;
    if (!bStrictMode){
        for (i = 0; i < sTest.length(); ++i){
            if (sTest[i] >= 'a' && sTest[i] <= 'z')
                return false;
        }
        return true;
    }
    else{
        for (i = 0; i < sTest.length(); ++i){
            if (!(sTest[i] >= 'A' && sTest[i] <= 'Z'))
                return false;
        }
        return true;
    }
}
inline bool IsVowel(char chrTest){
    return (chrTest == 'A' || chrTest == 'E' || chrTest == 'I' || chrTest == 'O' || chrTest == 'U' || chrTest == 'Y' || chrTest == 'a' || chrTest == 'e' || chrTest == 'i' || chrTest == 'o' || chrTest == 'u' || chrTest == 'y');
}
int main(){
    ios::sync_with_stdio(false);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    register int i;
    for (i = 0; i < s1.length(); ++i){
        cout << s1[i] << ' ';
    }
    cout << endl;
    cout << ToUpper(s2) << endl;
    cout << strReverse(s1) << endl;
    for (i = 0; i < s1.length() - s2.length() + 1; ++i){
        if (s1.substr(i, s2.length()) == s2){
            cout << i;
            goto endapp;
        }
    }
    cout << -1;
endapp:
    //system("pause > nul");
    return 0;
}