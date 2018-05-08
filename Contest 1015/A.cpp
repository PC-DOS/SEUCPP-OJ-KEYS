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
bool isTriangle(double iLength1, double iLength2, double iLength3){
    return (iLength1 + iLength2 > iLength3 && iLength1 + iLength3 > iLength2 && iLength3 + iLength2 > iLength1);
}
class Triangle{
public:
    bool IsFail;
    double iL1, iL2, iL3;
    Triangle(double a, double b, double c);
    int GetType();
    double GetArea();
    double GetLength();
};
 
Triangle::Triangle(double a, double b, double c){
    if (a <= 0 || b <= 0 || c <= 0){
        iL1 = a;
        iL2 = b;
        iL3 = c;
        IsFail = true;
    }
    else if (!isTriangle(a, b, c)){
        iL1 = a;
        iL2 = b;
        iL3 = c;
        IsFail = true;
    }
    else{
        iL1 = a;
        iL2 = b;
        iL3 = c;
        IsFail = false;
    }
}
 
int Triangle::GetType(){
    if (IsFail)
        return 0;
    if (iL1 == iL2 && iL2 == iL3 && iL1 == iL3)
        return 1;
    if ((iL1 == iL2 && fabs(iL3 - sqrt(iL1*iL1 + iL2*iL2)) <= 1e-12) || (iL1 == iL3 && fabs(iL2 - sqrt(iL1*iL1 + iL3*iL3)) <= 1e-12) || (iL2 == iL3 && fabs(iL1 - sqrt(iL3*iL3 + iL2*iL2)) <= 1e-12))
        return 2;
    if (iL1 == iL2 || iL2 == iL3 || iL1 == iL3)
        return 3;
    if ((fabs(iL3 - sqrt(iL1*iL1 + iL2*iL2)) <= 1e-12) || (fabs(iL2 - sqrt(iL1*iL1 + iL3*iL3)) <= 1e-12) || (fabs(iL1 - sqrt(iL3*iL3 + iL2*iL2)) <= 1e-12))
        return 4;
    return 5;
}
 
double Triangle::GetLength(){
    if (IsFail)
        return 0;
    return (iL1 + iL2 + iL3);
}
 
double Triangle::GetArea(){
    if (IsFail)
        return 0;
    double p=(iL1+iL2+iL3)/2;
    return sqrt(p*(p - iL1)*(p - iL2)*(p - iL3));
}
 
int main(){
    ios::sync_with_stdio(false);
    double a, b, c;
    cin >> a >> b >> c;
    Triangle t1(a, b, c);
    cin >> a >> b >> c;
    Triangle t2(a, b, c);
    cout << t1.iL1 << ' ' << t1.iL2 << ' ' << t1.iL3 << ' ' << t1.GetLength() << ' ' << t1.GetArea() << ' ' << t1.GetType() << endl;
    cout << t2.iL1 << ' ' << t2.iL2 << ' ' << t2.iL3 << ' ' << t2.GetLength() << ' ' << t2.GetArea() << ' ' << t2.GetType() << endl;
    if (t1.GetArea() < t2.GetArea())
        cout << "YES\n";
    else
        cout << "NO\n";
    if (t1.GetArea() > t2.GetArea())
        cout << "YES\n";
    else
        cout << "NO\n";
endapp:
    //system("pause > nul");
    return 0;
}