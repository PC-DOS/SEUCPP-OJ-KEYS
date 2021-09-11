#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long i,a1,n,k;
    cin >> i;
    for (n = 2; n <= i; ++n){
        for (a1 = 1; a1 < i; ++a1){
            if ((2 * a1 + n - 1)*n / 2 == i){
                for (k = 0; k <= n - 1; ++k) cout << a1 + k << ' ';
                cout << endl;
            }
        }
    }
    //system("pause > nul");
}