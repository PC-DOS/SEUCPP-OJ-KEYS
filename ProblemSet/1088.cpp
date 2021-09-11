#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a[5], i, k;
    for (i = 0; i <= 4; ++i) cin >> a[i];
    cin >> k;
    sort(a, a + 5);
    if (k == 0){
        for (i = 4; i >= 1; --i) cout << a[i] << ' ';
        cout << a[0];
    }
    else{
        for (i = 0; i <= 3; ++i){
            cout << a[i] << ' ';
        }
        cout << a[4];
    }
    return 0;
}