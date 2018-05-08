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
class Bigint{
public:
    //constructor 
    Bigint(long long = 0);
    Bigint(const string &);
    Bigint(const char *str) { *this = string(str); }
 
    //assignment operators
    Bigint &operator=(long long num) { return *this = Bigint(num); }
    Bigint &operator=(const string &str) { return *this = Bigint(str); }
    Bigint &operator=(const char *str) { return *this = Bigint(str); }
 
    //relatiional operators 
    bool operator<(const Bigint &obj) const { return cmp(obj) < 0; }
    bool operator>(const Bigint &obj) const { return cmp(obj) > 0; }
    bool operator<=(const Bigint &obj) const { return cmp(obj) <= 0; }
    bool operator>=(const Bigint &obj) const { return cmp(obj) >= 0; }
    bool operator==(const Bigint &obj) const { return cmp(obj) == 0; }
    bool operator!=(const Bigint &obj) const { return cmp(obj) != 0; }
 
    //arithmetic operators
    Bigint operator+() const { return *this; }
    Bigint operator-() const { return Bigint(-sign_, val_); }
    Bigint operator+(const Bigint &) const;
    Bigint operator-(const Bigint &) const;
    Bigint operator*(const Bigint &) const;
    Bigint operator/(const Bigint &) const;
    Bigint operator%(const Bigint &) const;
 
    //compound assignment operators
    Bigint &operator+=(const Bigint &obj) { return *this = *this + obj; }
    Bigint &operator-=(const Bigint &obj) { return *this = *this - obj; }
    Bigint &operator*=(const Bigint &obj) { return *this = *this * obj; }
    Bigint &operator/=(const Bigint &obj) { return *this = *this / obj; }
    Bigint &operator%=(const Bigint &obj) { return *this = *this % obj; }
 
    //increment and decrement operators
    Bigint &operator++() { return *this += 1; }
    Bigint &operator--() { return *this -= 1; }
    Bigint operator++(int);
    Bigint operator--(int);
 
    //input and output
    friend istream &operator>>(istream &, Bigint &);
    friend ostream &operator<<(ostream &, const Bigint &);
 
protected:
    enum div_type { division, remainder };
    enum cmp_type { with_sign, without_sign };
    static const int base_ = (int)1e4;
    static const int width_ = 4;
    Bigint(int s, const vector<int> &v) : sign_(s), val_(v) {}
    int cmp(const Bigint &, cmp_type = with_sign) const;
    Bigint &delZero();
    Bigint &add(const Bigint &);
    Bigint &sub(const Bigint &);
    Bigint &mul(const Bigint &, const Bigint &);
    Bigint &div(Bigint &, Bigint, div_type = division);
 
private:
    int sign_;
    vector<int> val_;
};
 
 
Bigint::Bigint(long long num) : sign_(0){
    if (num < 0) sign_ = -1, num = -num;
    else if (num > 0) sign_ = 1;
    do
    {
        val_.push_back(num % base_);
        num /= base_;
    } while (num);
}
 
Bigint::Bigint(const string &str){
    sign_ = str[0] == '-' ? -1 : 1;
    int be = str[0] == '-' ? 1 : 0, en = str.size();
    while ((en -= width_) >= be)
    {
        stringstream ss(str.substr(en, width_));
        int temp;
        ss >> temp;
        val_.push_back(temp);
    }
    if ((en += width_) > be)
    {
        stringstream ss(str.substr(be, en - be));
        int temp;
        ss >> temp;
        val_.push_back(temp);
    }
    delZero();
}
 
Bigint Bigint::operator+(const Bigint &obj) const{
    if (sign_ * obj.sign_ == 1){
        Bigint temp;
        return cmp(obj, without_sign) >= 0 ? (temp = *this).add(obj) : (temp = obj).add(*this);
    }
    else if (sign_ * obj.sign_ == -1) return *this - -obj;
    else return sign_ == 0 ? obj : *this;
}
 
Bigint Bigint::operator-(const Bigint &obj) const{
    if (sign_ * obj.sign_ == 1){
        Bigint temp;
        return cmp(obj, without_sign) >= 0 ? (temp = *this).sub(obj) : (temp = -obj).sub(*this);
    }
    else if (sign_ * obj.sign_ == -1) return *this + -obj;
    else return sign_ == 0 ? -obj : *this;
}
 
inline Bigint Bigint::operator*(const Bigint &obj) const{
    Bigint temp;
    return (temp.sign_ = sign_ * obj.sign_) == 0 ? temp : temp.mul(*this, obj);
}
 
inline Bigint Bigint::operator/(const Bigint &obj) const{
    Bigint temp, mod = *this;
    return cmp(obj, without_sign) < 0 || (temp.sign_ = sign_ * obj.sign_) == 0 ? temp : temp.div(mod, obj);
}
 
inline Bigint Bigint::operator%(const Bigint &obj) const{
    Bigint temp, mod = *this;
    return cmp(obj, without_sign) < 0 || (temp.sign_ = sign_) == 0 ? mod : temp.div(mod, obj, remainder);
}
 
inline Bigint Bigint::operator++(int){
    Bigint temp = *this;
    ++*this;
    return temp;
}
 
inline Bigint Bigint::operator--(int){
    Bigint temp = *this;
    --*this;
    return temp;
}
 
inline istream &operator>>(istream &in, Bigint &obj){
    string str;
    if (in >> str) obj = str;
    return in;
}
 
ostream &operator<<(ostream &out, const Bigint &obj){
    if (obj.sign_ == -1) cout << '-';
    out << obj.val_.back();
    for (int i = obj.val_.size() - 2; i >= 0; i--)
        out << setw(Bigint::width_) << setfill('0') << obj.val_[i];
    return out;
}
 
int Bigint::cmp(const Bigint &obj, cmp_type typ) const{
    if (typ == with_sign && sign_ != obj.sign_) return sign_ - obj.sign_;
    int sign = typ == with_sign ? sign_ : 1;
    if (val_.size() != obj.val_.size()) return sign * (val_.size() - obj.val_.size());
    for (int i = val_.size() - 1; i >= 0; i--)
        if (val_[i] != obj.val_[i]) return sign * (val_[i] - obj.val_[i]);
    return 0;
}
 
inline Bigint &Bigint::delZero(){
    while (val_.back() == 0 && val_.size() > 1) val_.pop_back();
    if (val_.back() == 0) sign_ = 0;
    return *this;
}
 
Bigint &Bigint::add(const Bigint &obj){
    int ts = val_.size(), os = obj.val_.size();
    for (int i = 0; i < os; i++) val_[i] += obj.val_[i];
    val_.push_back(0);
    for (int i = 0; i < ts; i++)
        if (val_[i] >= base_) val_[i] -= base_, ++val_[i + 1];
    return delZero();
}
 
Bigint &Bigint::sub(const Bigint &obj){
    int pos = obj.val_.size();
    for (int i = 0; i < pos; i++)
        if ((val_[i] -= obj.val_[i]) < 0) val_[i] += base_, --val_[i + 1];
    while (val_[pos] < 0) val_[pos] += base_, --val_[++pos];
    return delZero();
}
 
Bigint &Bigint::mul(const Bigint &a, const Bigint &b){
    int as = a.val_.size(), bs = b.val_.size();
    val_.resize(as + bs);
    for (int i = 0; i < as; i++) for (int j = 0; j < bs; j++) {
        int x = i + j;
        val_[x] += a.val_[i] * b.val_[j];
        val_[x + 1] += val_[x] / base_;
        val_[x] %= base_;
    }
    return delZero();
}
 
Bigint &Bigint::div(Bigint &a, Bigint b, div_type typ){
    int move = a.val_.size() - b.val_.size();
    val_.resize(move + 1);
    b.val_.insert(b.val_.begin(), move, 0);
    for (int i = move; i >= 0; i--)  {
        int left = 0, right = base_;
        while (left + 1 < right)     {
            int mid = (left + right) >> 1;
            if (a.cmp(b * Bigint(mid), without_sign) >= 0) left = mid;
            else right = mid;
        }
        val_[i] = left;
        a.sub(b * Bigint(left));
        b.val_.erase(b.val_.begin());
    }
    return typ == division ? delZero() : a;
}
int main(){
    ios::sync_with_stdio(false);
    Bigint b1, b2, b3, b4;
    cin >> b1 >> b2;
    cout << b1<<endl<<b2<<endl;
    if (b1 > b2)
        cout << 1;
    else if (b1 == b2)
        cout << 0;
    else
        cout << -1;
endapp:
    //system("pause > nul");
    return 0;
}