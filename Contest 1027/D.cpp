#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    long dist=0, start, n, current,passed=0;
    cin >> start >> n;
    current = start;
    while (passed < n){
        if (current >= 1 && current <= 5) dist += 250;
        ++current;
        ++passed;
        if (current > 7) current = 1;
    }
    cout << dist;
    //system("pause > nul");
    return 0;
}