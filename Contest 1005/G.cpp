#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long i;
    long l1, l2;
    cout << '1' << endl;
    for (i = 4; i <= 10000; ++i){
        l2 = long(log10l(i)) + 1;
        l1 = long(log10l(i*i)) + 1;
        if ((i*i) % long((pow(10 , l2))) == i) cout << i<<endl;
    }
    //system("pause > nul");
}