#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int x_tot(int minute){
    return 3 * minute;
}
int x_rab(int minute){
    int i,dist=0;
    for (i = 1; i <= minute; ++i){
        if (i % 10 != 0)
            dist += 9;
        else
            if (dist > x_tot(i)){
                dist += 9;
                i += 30;
            }
            else
                dist += 9;
    }
    return dist;
}
 
int main() {
    int min;
    cin >> min;
    cout << x_rab(min) << ' ' << x_tot(min);
    //system("pause>nul");
    return 0;
}