#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a,b,c,n;
    n = 0;
    for (c = 1; c <= 100; ++c){
        for (a = 1; a <= c; ++a){
            b = sqrt(c*c - a*a);
            if (a <= b && ((a*a + b*b) == (c*c))) ++n;
        }
    }
    cout << n;
    //system("pause > nul");
}