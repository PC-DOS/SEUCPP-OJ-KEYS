#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#ifndef _DATE_H_
#define _DATE_H_
#pragma once
#include <iostream>
#include <string>
using namespace std;
 
#define _INVALID_MONTH_ERROR -2;
#define _INVALID_DAY_ERROR - 3;
 
class Date{
private:
    long long iYearVal;
    int iMonthVal;
    int iDayVal;
    char chrDateSeparator;
    bool IsLeap;
public:
    //Constructor
    Date(long long iYear, int iMonth, int iDay);
    Date();
 
    //Compound assignment operators
    Date operator+=(long long nDays);
    Date operator-=(long long nDays);
 
    //Arithmetic operators
    Date operator+(long long nDays);
    friend Date operator+(long long nDays, Date datDate);
    Date operator-(long long nDays);
    long long operator-(Date datDate);
 
    //Increment and decrement operators
    Date &operator++();
    Date &operator--();
    Date operator++(int iTemp);
    Date operator--(int iTemp);
 
    //Relational operators 
    bool operator>(const Date &datDate);
    bool operator<(const Date &datDate);
    bool operator>=(const Date &datDate);
    bool operator<=(const Date &datDate);
    bool operator==(const Date &datDate);
    bool operator!=(const Date &datDate);
 
    //IO operators
    friend ostream& operator<<(ostream &osOut, const Date &datDate);
    friend istream& operator>>(istream &isIn, Date &datDate);
 
    //Type converting operators
    operator string();
 
    //Functional functions
    string ToString(char chrSeparator) const;
    string ToString() const;
    string GetValue(char chrSeparator) const;
    string GetValue() const;
    Date SetDate(long long iYear, int iMonth, int iDay);
    Date SetYear(long long iYear);
    Date SetMonth(int iMonth);
    Date SetDay(int iDay);
    long long GetYear() const;
    int GetMonth() const;
    int GetDay() const;
    void SetSeparator(char chrSeparator);
    bool IsLeapYear() const;
    int GetMonthDayCount() const;
    int GetYearDayCount() const;
    int GetDayFromYearBeginning() const;
 
    //Static functions
    static bool IsLeapYear(long long iYear);
    static int GetMonthDayCount(long long iYear, int iMonth);
    static int GetYearDayCount(long long iYear);
};
 
Date::Date(){
    iYearVal = 1970;
    iMonthVal = 1;
    iDayVal = 1;
    chrDateSeparator = '-';
    IsLeap = false;
}
 
Date::Date(long long iYear, int iMonth, int iDay){
    iYearVal = iYear;
    if ((iYear % 100 != 0 && iYear % 4 == 0) || (iYear % 100 == 0 && iYear % 400 == 0))
        IsLeap = true;
    else
        IsLeap = false;
    if (iMonth < 1 || iMonth>12){
        iYearVal = 2000;
        iMonthVal = 1;
        iDayVal = 1;
        chrDateSeparator = '-';
        return;
    }
    else{
        iMonthVal = iMonth;
    }
    if (iDay <= 0 || iDay > GetMonthDayCount(iYear, iMonth)){
        iYearVal = 2000;
        iMonthVal = 1;
        iDayVal = 1;
        chrDateSeparator = '-';
        return;
    }
    else{
        iDayVal = iDay;
    }
    chrDateSeparator = '-';
}
 
string Date::ToString() const {
    string sRet = to_string(iYearVal) + chrDateSeparator + to_string(iMonthVal) + chrDateSeparator + to_string(iDayVal);
    return sRet;
}
 
string Date::ToString(char chrSeparator) const {
    string sRet = to_string(iYearVal) + chrSeparator + to_string(iMonthVal) + chrSeparator + to_string(iDayVal);
    return sRet;
}
 
string Date::GetValue() const {
    string sRet = to_string(iYearVal) + chrDateSeparator + to_string(iMonthVal) + chrDateSeparator + to_string(iDayVal);
    return sRet;
}
 
string Date::GetValue(char chrSeparator) const {
    string sRet = to_string(iYearVal) + chrSeparator + to_string(iMonthVal) + chrSeparator + to_string(iDayVal);
    return sRet;
}
 
Date Date::SetDate(long long iYear, int iMonth, int iDay){
    iYearVal = iYear;
    if ((iYear % 100 != 0 && iYear % 4 == 0) || (iYear % 100 == 0 && iYear % 400 == 0))
        IsLeap = true;
    else
        IsLeap = false;
    if (iMonth < 1 || iMonth>12){
        iYearVal = 2000;
        iMonthVal = 1;
        iDayVal = 1;
        chrDateSeparator = '-';
        return *this;
    }
    else{
        iMonthVal = iMonth;
    }
    if (iDay <= 0 || iDay > GetMonthDayCount(iYear, iMonth)){
        iYearVal = 2000;
        iMonthVal = 1;
        iDayVal = 1;
        chrDateSeparator = '-';
        return *this;
    }
    else{
        iDayVal = iDay;
    }
    chrDateSeparator = '-';
    return *this;
}
 
Date Date::SetYear(long long iYear){
    iYearVal = iYear;
    if ((iYear % 100 != 0 && iYear % 4 == 0) || (iYear % 100 == 0 && iYear % 400 == 0))
        IsLeap = true;
    else
        IsLeap = false;
    return *this;
}
 
Date Date::SetMonth(int iMonth){
    iMonthVal = iMonth;
    if (iMonth < 1 || iMonth>12)
        iMonthVal = 1;
    return *this;
}
 
Date Date::SetDay(int iDay){
    iDayVal = iDay;
    if (iDay <= 0 || iDay > GetMonthDayCount(iYearVal, iMonthVal))
        iDayVal = 1;
    return *this;
}
 
void Date::SetSeparator(char chrSeparator = '-'){
    chrDateSeparator = chrSeparator;
}
 
long long Date::GetYear() const{
    return iYearVal;
}
 
int Date::GetMonth() const{
    return iMonthVal;
}
 
int Date::GetDay() const{
    return iDayVal;
}
 
int Date::GetMonthDayCount() const{
    if (iMonthVal == 1 || iMonthVal == 3 || iMonthVal == 5 || iMonthVal == 7 || iMonthVal == 8 || iMonthVal == 10 || iMonthVal == 12)
        return 31;
    else if (iMonthVal == 4 || iMonthVal == 6 || iMonthVal == 9 || iMonthVal == 11)
        return 30;
    else if (iMonthVal == 2)
        if (IsLeap)
            return 29;
        else
            return 28;
    else
        return 31;
}
 
int Date::GetMonthDayCount(long long iYear, int iMonth){
    if (iMonth == 1 || iMonth == 3 || iMonth == 5 || iMonth == 7 || iMonth == 8 || iMonth == 10 || iMonth == 12)
        return 31;
    else if (iMonth == 4 || iMonth == 6 || iMonth == 9 || iMonth == 11)
        return 30;
    else if (iMonth == 2)
        if (IsLeapYear(iYear))
            return 29;
        else
            return 28;
    else
        return 31;
}
 
int Date::GetYearDayCount() const {
    if (IsLeapYear(iYearVal))
        return 366;
    else
        return 365;
}
 
int Date::GetYearDayCount(long long iYear){
    if (IsLeapYear(iYear))
        return 366;
    else
        return 365;
}
 
int Date::GetDayFromYearBeginning() const {
    int iSum = 0;
    register int i;
    for (i = 1; i < iMonthVal; ++i){
        iSum += GetMonthDayCount(iYearVal, i);
    }
    iSum += iDayVal;
    return iSum;
}
 
bool Date::IsLeapYear() const{
    return IsLeap;
}
 
bool Date::IsLeapYear(long long iYear){
    if ((iYear % 100 != 0 && iYear % 4 == 0) || (iYear % 100 == 0 && iYear % 400 == 0))
        return true;
    else
        return false;
}
 
Date::operator string(){
    string sRet = to_string(iYearVal) + chrDateSeparator + to_string(iMonthVal) + chrDateSeparator + to_string(iDayVal);
    return sRet;
}
 
//Date& Date::add(int day){
//  d += day;
//  while (d > 30){
//      switch (m){
//      case 1:
//      case 3:
//      case 5:
//      case 7:
//      case 8:
//      case 10:
//      case 12:
//          if (d > 31){
//              d -= 31;
//              m++;
//              break;
//          }
//          else
//              break;
//      case 2:
//          if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0){
//              d -= 29;
//              m++;
//              break;
//          }
//          else{
//              d -= 28;
//              m++;
//              break;
//          }
//      case 4:
//      case 6:
//      case 9:
//      case 11:
//          d -= 30;
//          m++;
//          break;
//      default:
//          y++;
//          m -= 12;
//          break;
//      }
//      if (d == 31)
//          break;
//      if (m > 12){
//          m -= 12;
//          y++;
//      }
//  }
//  return *this;
//}
 
Date Date::operator+=(long long nDays){
    if (nDays > 0){
        while (nDays--){
            ++(*this);
        }
    }
    else{
        while (nDays++){
            --(*this);
        }
    }
    return *this;
}
 
Date Date::operator-=(long long nDays){
    if (nDays > 0){
        while (nDays--){
            --(*this);
        }
    }
    else{
        while (nDays++){
            ++(*this);
        }
    }
    return *this;
}
 
Date Date::operator+(long long nDays){
    Date datTemp = *this;
    datTemp += nDays;
    return datTemp;
}
 
Date operator+(long long nDays, Date datDate){
    return datDate + nDays;
}
 
Date Date::operator-(long long nDays){
    Date datTemp = *this;
    datTemp -= nDays;
    return datTemp;
}
 
long long Date::operator-(Date datDate){
    if (datDate.iYearVal == iYearVal)
        return (this->GetDayFromYearBeginning() - datDate.GetDayFromYearBeginning());
    int iSum;
    register int i;
    if (*this > datDate){
        iSum = datDate.GetYearDayCount() - datDate.GetDayFromYearBeginning();
        for (i = datDate.iYearVal + 1; i < iYearVal; ++i){
            iSum += GetYearDayCount(i);
        }
        iSum += (*this).GetDayFromYearBeginning();
        return iSum;
    }
    else{
        iSum = this->GetYearDayCount() - this->GetDayFromYearBeginning();
        for (i = iYearVal + 1; i < datDate.iYearVal; ++i){
            iSum += GetYearDayCount(i);
        }
        iSum += datDate.GetDayFromYearBeginning();
        return -iSum;
    }
}
 
Date &Date::operator++(){
    if (iMonthVal == 12 && iDayVal == 31){
        ++iYearVal;
        iMonthVal = 1;
        iDayVal = 1;
    }
    else if (iMonthVal != 12 && iDayVal == GetMonthDayCount()){
        ++iMonthVal;
        iDayVal = 1;
    }
    else{
        ++iDayVal;
    }
    return *this;
}
 
Date &Date::operator--(){
    if (iMonthVal == 1 && iDayVal == 1){
        --iYearVal;
        iMonthVal = 12;
        iDayVal = 31;
    }
    else if (iMonthVal != 1 && iDayVal == 1){
        --iMonthVal;
        iDayVal = GetMonthDayCount();
    }
    else{
        --iDayVal;
    }
    return *this;
}
 
Date Date::operator++(int iTemp){
    Date datTemp = *this;
    if (iMonthVal == 12 && iDayVal == 31){
        ++iYearVal;
        iMonthVal = 1;
        iDayVal = 1;
    }
    else if (iMonthVal != 12 && iDayVal == GetMonthDayCount()){
        ++iMonthVal;
        iDayVal = 1;
    }
    else{
        ++iDayVal;
    }
    return datTemp;
}
 
Date Date::operator--(int iTemp){
    Date datTemp = *this;
    if (iMonthVal == 1 && iDayVal == 1){
        --iYearVal;
        iMonthVal = 12;
        iDayVal = 31;
    }
    else if (iMonthVal != 1 && iDayVal == 1){
        --iMonthVal;
        iDayVal = GetMonthDayCount();
    }
    else{
        --iDayVal;
    }
    return datTemp;
}
 
bool Date::operator>(const Date &datDate){
    if (iYearVal != datDate.iYearVal)
        return iYearVal > datDate.iYearVal;
    else if (iMonthVal != datDate.iMonthVal)
        return iMonthVal > datDate.iMonthVal;
    else
        return iDayVal > datDate.iDayVal;
}
 
bool Date::operator<(const Date &datDate){
    if (iYearVal != datDate.iYearVal)
        return iYearVal < datDate.iYearVal;
    else if (iMonthVal != datDate.iMonthVal)
        return iMonthVal < datDate.iMonthVal;
    else
        return iDayVal < datDate.iDayVal;
}
 
bool Date::operator>=(const Date &datDate){
    return (*this > datDate || *this == datDate);
}
 
bool Date::operator<=(const Date &datDate){
    return (*this < datDate || *this == datDate);
}
 
bool Date::operator==(const Date &datDate){
    return (iYearVal == datDate.iYearVal && iMonthVal == datDate.iMonthVal && iDayVal == datDate.iDayVal);
}
 
bool Date::operator!=(const Date &datDate){
    return (iYearVal != datDate.iYearVal || iMonthVal != datDate.iMonthVal || iDayVal != datDate.iDayVal);
}
 
ostream& operator<<(ostream &osOut, const Date &datDate){
    osOut << datDate.ToString();
    return osOut;
}
 
istream& operator>>(istream &isIn, Date &datDate){
    long long iYear;
    int iDay, iMonth;
    if (isIn >> iYear >> iMonth >> iDay){
        datDate.SetDate(iYear, iMonth, iDay);
    }
    return isIn;
}
#endif
int main(){
    ios::sync_with_stdio(false);
    Date d1, d2;
    int iDist;
    cin >> d1 >> d2 >> iDist;
    cout << d1 << endl;
    cout << d2 << endl;
    cout << (d1 < d2 ? "YES\n" : "NO\n");
    cout << d1 - d2 << endl;
    cout << d1 + iDist <<endl;
endapp:
    //system("pause > nul");
    return 0;
}