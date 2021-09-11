#include <iostream>
using namespace std;
int main(){
    int sd, sh, sm, ad, ah, am;
    long s, a,t;
    cin >> sd >> sh >> sm >> ad >> ah >> am;
    s = sd * 24 * 60 + sh * 60 + sm;
    a = ad * 24 * 60 + ah * 60 + am;
    t = (a - s) / 60;
    cout << t << ' ' << (a - s) - 60 *t;
    //system("pause>nul");
}