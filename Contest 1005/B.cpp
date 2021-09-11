#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int x,y;
    for (x = 1; x <= 44; ++x){
        y = sqrt(2017 - x*x);
        if (x*x + y*y == 2017) cout << x << ' ' << y<<endl;
    }
    //system("pause > nul");
}