#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a,b,c,n;
    n = 0;
    for (a = 1; a <= 4; ++a){
        for (b = 1; b <= 4; ++b){
            for (c = 1; c <= 4; ++c){
                if (a!=b && b!=c && a!=c) cout << a << b << c<<endl;
            }
        }
    }
    //cout << n;
    //system("pause > nul");
}