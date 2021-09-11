#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
char a[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
string strReverse(string strOrigin){
    long i;
    string ans;
    for (i = strOrigin.length() - 1; i >= 0; --i) ans += strOrigin[i];
    return ans;
}
int main(){
    string ans("");
    int i, K,nOrig,t;
    cin >> nOrig>>K;
    i = nOrig%K;
    t = nOrig / K;
    while (t != 0){
        if (i < 10)
            ans += to_string(i);
        else
            ans += a[i - 10];
        i = t%K;
        t = t / K;
    }
    if (i < 10)
        ans += to_string(i);
    else
        ans += a[i - 10];
    cout << strReverse(ans);
    //system("pause > nul");
    return 0;
}