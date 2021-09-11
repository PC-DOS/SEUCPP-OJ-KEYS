#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
int factorsum(int n){
    int i,sum=0;
    for (i = 2; i <= n - 1; ++i){
        if (n%i == 0) sum+=i;
    }
    return sum;
}
int main(){
    int i, j;
    for (i = 2; i <= 400; ++i){
        for (j = 2; j <= 400; ++j){
            if ((factorsum(i) ==j) && (factorsum(j)==i) && (factorsum(i)!=0) && (i < j)) cout << i << ' ' << j<<endl;
        }
    }
    //system("pause > nul");
    return 0;
}