#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int i,a,b,c,n;
    n=0;
    for (i = 1; i < 1000; ++i){
        a = i / 100;
        b = (i - a * 100) / 10;
        c = i - a * 100 - b * 10;
        if (a <= b && b <= c) ++n;
    }
    cout << n;
    //system("pause > nul");
}