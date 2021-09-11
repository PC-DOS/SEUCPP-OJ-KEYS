#include <iostream>
using namespace std;
int main(){
    int n, x, y;
    cin >> n >> x >> y;
    if (y%x != 0)
        cout << n - (y / x) - 1;
    else
        cout << n - y / x;
    //system("pause > nul");
    return 0;
}