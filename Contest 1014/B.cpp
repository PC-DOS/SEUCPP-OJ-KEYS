#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
 
#define _FRACTION_ZERO_DIVIDE -1;
#define _FRACTION_ZERO_DENOMINATOR -2;
 
#define _FRACTION_ZERO_DENOMINATOR_ERROR_LEVEL_NOERR 0
#define _FRACTION_ZERO_DENOMINATOR_ERROR_LEVEL_WARN 1
#define _FRACTION_ZERO_DENOMINATOR_ERROR_LEVEL_ABORT 2
 
#define _FRACTION_ZERO_DIVIDE_ERROR_LEVEL_WARN 0
#define _FRACTION_ZERO_DIVIDE_ERROR_LEVEL_ABORT 1
 
class Fraction{
private:
    long long iNumeratorVal;
    long long iDenominatorVal;
    long long GetGreatestCommonDivision(long long iNum1, long long iNum2);
public:
    //Constructor
    Fraction(long long iNumerator, long long iDenominator);
    Fraction(long long iNum);
    Fraction();
 
    //Compound assignment operators
    Fraction operator+=(const Fraction &fracFraction);
    Fraction operator-=(const Fraction &fracFraction);
    Fraction operator*=(const Fraction &fracFraction);
    Fraction operator/=(const Fraction &fracFraction);
 
    //Arithmetic operators
    Fraction operator+(const Fraction &fracFraction);
    Fraction operator-(const Fraction &fracFraction);
    Fraction operator*(const Fraction &fracFraction);
    Fraction operator/(const Fraction &FracFraction);
    Fraction operator-();
    Fraction operator+();
 
    //Relational operators 
    bool operator>(Fraction FracFraction);
    bool operator<(Fraction FracFraction);
    bool operator>=(Fraction FracFraction);
    bool operator<=(Fraction FracFraction);
    bool operator==(Fraction FracFraction);
    bool operator!=(Fraction FracFraction);
 
    //Assignment operators
    Fraction operator=(long long iNum);
 
    //IO operators
    friend ostream& operator<<(ostream &osOut, const Fraction &fracFraction);
    friend istream& operator>>(istream &isIn, Fraction &fracFraction);
 
    //Type converting operators
    operator double();
    operator int();
    operator long();
 
    //Functional functions
    bool IsInteger();
    double ToDouble();
    long long ToInt(bool bCeil);
    Fraction Numden(Fraction &fracFraction);
    Fraction Reduction();
    void SetValue(long long iNumerator, long long iDenominator);
    void SetValue(long long iNum);
    long long GetNumerator();
    long long GetDenominator();
 
    //Static functions
    static Fraction Reduction(Fraction fracFraction);
    static bool bIgnoreDivideZeroErrors;
    static int iErrInputDenominatorZeroErrors;
};
 
bool Fraction::bIgnoreDivideZeroErrors = _FRACTION_ZERO_DIVIDE_ERROR_LEVEL_WARN;
 
int Fraction::iErrInputDenominatorZeroErrors = _FRACTION_ZERO_DENOMINATOR_ERROR_LEVEL_NOERR;
 
long long Fraction::GetGreatestCommonDivision(long long iNum1, long long iNum2){
    if (iNum2 == 0)
        return iNum1;
    else
        return GetGreatestCommonDivision(iNum2, iNum1%iNum2);
}
 
Fraction::Fraction(){
    iNumeratorVal = 0;
    iDenominatorVal = 1;
}
 
Fraction::Fraction(long long iNumerator, long long iDenominator){
    if (iDenominator == 0){
        if (iErrInputDenominatorZeroErrors == _FRACTION_ZERO_DENOMINATOR_ERROR_LEVEL_ABORT){
            cerr << "\nError: Zero denominator auto-recovery has been disabled due to security settings.\n";
            throw _FRACTION_ZERO_DENOMINATOR;
        }
        else if (iErrInputDenominatorZeroErrors == _FRACTION_ZERO_DENOMINATOR_ERROR_LEVEL_WARN){
            cerr << "\nError: Zero denominator auto-recovery has been disabled due to security settings.\n";
        }
        else{
 
            iNumeratorVal = 0;
            iDenominatorVal = 1;
        }
    }
    else if (iDenominator < 0){
        iNumeratorVal = -iNumerator;
        iDenominatorVal = -iDenominator;
    }
    else{
        iNumeratorVal = iNumerator;
        iDenominatorVal = iDenominator;
    }
}
 
Fraction::Fraction(long long iNum){
    iNumeratorVal = iNum;
    iDenominatorVal = 1;
}
 
void Fraction::SetValue(long long iNum){
    iNumeratorVal = iNum;
    iDenominatorVal = 1;
}
 
void Fraction::SetValue(long long iNumerator, long long iDenominator){
    if (iDenominator == 0){
        if (iErrInputDenominatorZeroErrors == _FRACTION_ZERO_DENOMINATOR_ERROR_LEVEL_ABORT){
            cerr << "\nError: Zero denominator auto-recovery has been disabled due to security settings.\n";
            throw _FRACTION_ZERO_DENOMINATOR;
        }
        else if (iErrInputDenominatorZeroErrors == _FRACTION_ZERO_DENOMINATOR_ERROR_LEVEL_WARN){
            cerr << "\nError: Zero denominator auto-recovery has been disabled due to security settings.\n";
        }
        else{
 
            iNumeratorVal = 0;
            iDenominatorVal = 1;
        }
    }
    else if (iDenominator < 0){
        iNumeratorVal = -iNumerator;
        iDenominatorVal = -iDenominator;
    }
    else{
        iNumeratorVal = iNumerator;
        iDenominatorVal = iDenominator;
    }
}
 
long long Fraction::GetNumerator(){
    return iNumeratorVal;
}
 
long long Fraction::GetDenominator(){
    return iDenominatorVal;
}
 
Fraction Fraction::Reduction(){
    long long iGCD = GetGreatestCommonDivision(iNumeratorVal, iDenominatorVal);
    iNumeratorVal /= iGCD;
    iDenominatorVal /= iGCD;
    if (iDenominatorVal < 0){
        iDenominatorVal = -iDenominatorVal;
        iNumeratorVal = -iNumeratorVal;
    }
    return *this;
}
 
Fraction Fraction::Reduction(Fraction fracFraction){
    return fracFraction.Reduction();
}
 
Fraction Fraction::Numden(Fraction &fracFraction){
    long long iGCD = GetGreatestCommonDivision(iDenominatorVal, fracFraction.iDenominatorVal);
    iNumeratorVal *= fracFraction.iDenominatorVal;
    fracFraction.iNumeratorVal *= iDenominatorVal;
    iDenominatorVal *= fracFraction.iDenominatorVal;
    fracFraction.iDenominatorVal = iDenominatorVal;
    fracFraction.iDenominatorVal /= iGCD;
    iDenominatorVal /= iGCD;
    iNumeratorVal /= iGCD;
    fracFraction.iNumeratorVal /= iGCD;
    return *this;
}
 
bool Fraction::IsInteger(){
    return bool(iNumeratorVal%iDenominatorVal == 0);
}
 
long long Fraction::ToInt(bool bCeil = false){
    if (bCeil)
        return ceil(double(iNumeratorVal) / double(iDenominatorVal));
    else
        return iNumeratorVal / iDenominatorVal;
}
 
double Fraction::ToDouble(){
    return double(iNumeratorVal) / double(iDenominatorVal);
}
 
Fraction::operator double(){
    return (double(iNumeratorVal) / double(iDenominatorVal));
}
 
Fraction::operator int(){
    return iNumeratorVal / iDenominatorVal;
}
 
Fraction::operator long(){
    return iNumeratorVal / iDenominatorVal;
}
 
Fraction Fraction::operator-(){
    iNumeratorVal = -iNumeratorVal;
    return *this;
}
 
Fraction Fraction::operator+(){
    return *this;
}
 
Fraction Fraction::operator+(const Fraction &fracFraction){
    Fraction fracTemp(iNumeratorVal*fracFraction.iDenominatorVal + fracFraction.iNumeratorVal*iDenominatorVal, iDenominatorVal*fracFraction.iDenominatorVal);
    fracTemp.Reduction();
    return fracTemp;
}
 
Fraction Fraction::operator-(const Fraction &fracFraction){
    Fraction fracTemp(iNumeratorVal*fracFraction.iDenominatorVal - fracFraction.iNumeratorVal*iDenominatorVal, iDenominatorVal*fracFraction.iDenominatorVal);
    fracTemp.Reduction();
    return fracTemp;
}
 
Fraction Fraction::operator*(const Fraction &fracFraction){
    Fraction fracTemp(iNumeratorVal*fracFraction.iNumeratorVal, iDenominatorVal*fracFraction.iDenominatorVal);
    fracTemp.Reduction();
    return fracTemp;
}
 
Fraction Fraction::operator/(const Fraction &fracFraction){
    Fraction fracTemp;
    if (fracFraction.iNumeratorVal == 0){
        cerr << "\nError: Fraction \'" << *this << "\' was divided by zero.\n";
        if (bIgnoreDivideZeroErrors)
            return fracTemp;
        else
            throw _FRACTION_ZERO_DIVIDE;
    }
    fracTemp.SetValue(iNumeratorVal*fracFraction.iDenominatorVal, iDenominatorVal*fracFraction.iNumeratorVal);
    fracTemp.Reduction();
    return fracTemp;
}
 
Fraction Fraction::operator+=(const Fraction &fracFraction){
    *this = *this + fracFraction;
    return *this;
}
 
Fraction Fraction::operator-=(const Fraction &fracFraction){
    *this = *this - fracFraction;
    return *this;
}
 
Fraction Fraction::operator*=(const Fraction &fracFraction){
    *this = *this * fracFraction;
    return *this;
}
 
Fraction Fraction::operator/=(const Fraction &fracFraction){
    if (fracFraction.iNumeratorVal == 0){
        cerr << "\nError: Fraction \'" << *this << "\' was divided by zero.\n";
        if (bIgnoreDivideZeroErrors)
            return Fraction();
        else
            throw _FRACTION_ZERO_DIVIDE;
    }
    *this = *this / fracFraction;
    return *this;
}
 
Fraction Fraction::operator=(long long iNum){
    *this = Fraction(iNum);
    return *this;
}
 
bool Fraction::operator>(Fraction fracFraction){
    Fraction fracMe = *this;
    fracMe.Numden(fracFraction);
    return fracMe.GetNumerator() > fracFraction.GetNumerator();
}
 
bool Fraction::operator<(Fraction fracFraction){
    Fraction fracMe = *this;
    fracMe.Numden(fracFraction);
    return fracMe.GetNumerator() < fracFraction.GetNumerator();
}
 
bool Fraction::operator>=(Fraction fracFraction){
    Fraction fracMe = *this;
    fracMe.Numden(fracFraction);
    return fracMe.GetNumerator() >= fracFraction.GetNumerator();
}
 
bool Fraction::operator<=(Fraction fracFraction){
    Fraction fracMe = *this;
    fracMe.Numden(fracFraction);
    return fracMe.GetNumerator() <= fracFraction.GetNumerator();
}
 
bool Fraction::operator==(Fraction fracFraction){
    Fraction fracMe = *this;
    fracMe.Numden(fracFraction);
    return fracMe.GetNumerator() == fracFraction.GetNumerator();
}
 
bool Fraction::operator!=(Fraction fracFraction){
    Fraction fracMe = *this;
    fracMe.Numden(fracFraction);
    return fracMe.GetNumerator() != fracFraction.GetNumerator();
}
 
ostream& operator<<(ostream &osOut, const Fraction &fracFraction){
    osOut << fracFraction.iNumeratorVal << '/' << fracFraction.iDenominatorVal;
    return osOut;
}
 
istream& operator>>(istream &isIn, Fraction &fracFraction){
    long long iNum, iDenomi;
    if (isIn >> iNum >> iDenomi){
        fracFraction.SetValue(iNum, iDenomi);
    }
    return isIn;
}
 
int main(){
    ios::sync_with_stdio(false);
    Fraction frac1, frac2;
    cin >> frac1 >> frac2;
    cout << '(' << frac1 << ")>(" << frac2 << "):" << (frac1 > frac2 ? "yes" : "no") << endl;
    cout << '(' << frac1 << ")<(" << frac2 << "):" << (frac1 < frac2 ? "yes" : "no") << endl;
    cout << '(' << frac1 << ")==(" << frac2 << "):" << (frac1 == frac2 ? "yes" : "no") << endl;
    cout << '(' << frac1 << ")!=(" << frac2 << "):" << (frac1 != frac2 ? "yes" : "no") << endl;
    cout << '(' << frac1 << ")>=(" << frac2 << "):" << (frac1 >= frac2 ? "yes" : "no") << endl;
    cout << '(' << frac1 << ")<=(" << frac2 << "):" << (frac1 <= frac2 ? "yes" : "no") << endl;
endapp:
    //system("pause > nul");
    return 0;
}