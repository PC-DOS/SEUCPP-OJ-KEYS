#include <iostream>
using namespace std;
int main(){
    int trip;
    double fee;
    cin >> trip;
    if (trip <= 3)
        cout << 9+2;
    else{
        fee = 9 + 2 + 2.4*(trip - 3);
        cout << fee;
    }
    //system("pause > nul");
}