#include <iostream>
#include <cmath>
using namespace std;
 
 
int main(){
    double m1, m2, m3;
    cin >> m1 >> m2 >> m3;
    //m = m1;
    if (m2 == m1)
        cout << 'C';
    else
        if (m3 == m2)
            cout << 'A';
        else
            cout << 'B';
 
    //system("pause>nul");
}