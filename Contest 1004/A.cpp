#include <iostream>
#include <cmath>
using namespace std;
 
 
int main(){
    long ans = 0, i = 1;
    for (i = 1; i <= 99; i=i+2) ans = ans+i*(i+1)*(i+2);
    cout << ans;
    //system("pause > nul");
}