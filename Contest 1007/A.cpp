#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
double squaresum(double a,double b){
    return a*a+b*b;
}
int main(){
    double a, b;
    cin >> a >> b;
    cout << squaresum(a,b);
    //system("pause > nul");
    return 0;
}