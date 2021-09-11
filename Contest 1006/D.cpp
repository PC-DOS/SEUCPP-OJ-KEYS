#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main() {
    unsigned long orig,i,j,tmp;
    cin >> orig;
    tmp = orig;
    if (orig == 1){
        cout << "1=1"<<endl;
        goto endapp;
    }
    cout << orig << '=';
    for (i = 2; tmp != 1 && i<=orig; ++i){
        while (tmp%i == 0){
            cout << i;
            tmp /= i;
            if (tmp != 1) cout << '*';
        }
    }
    cout << endl;
    //system("pause>nul");
    endapp:
    return 0;
}