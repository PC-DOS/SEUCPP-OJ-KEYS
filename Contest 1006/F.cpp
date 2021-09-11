#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
 
int main() {
    int sum=0,day,c=0;
    int i, j;
    cin >> day;
    for (i = 1; ; ++i){
        for (j = 1; j <= i; ++j){
            sum += i;
            ++c;
            if (c == day) goto t;
        }
    }
    t:
    cout << sum << endl;
    //system("pause>nul");
    return 0;
}