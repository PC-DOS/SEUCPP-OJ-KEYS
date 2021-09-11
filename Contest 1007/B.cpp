#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
bool isprime(long a){
    long i;
    for (i = 2; i <= sqrt(a); ++i){
        if (a%i == 0) return false;
    }
    return true;
}
int main(){
    long num;
    int count = 0;
    cin >> num;
    long i;
    for (i = 2;count<num; ++i){
        if (isprime(i)) ++count;
    }
    cout << i-1;
    //system("pause > nul");
    return 0;
}