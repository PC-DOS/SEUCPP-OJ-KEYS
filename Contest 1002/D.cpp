#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if (n % 3 != 0){
        if (n % 5 == 0)
            cout << 'D';
        else
            cout << 'B';
    }
    else if (n % 3 == 0){
        if (n % 5 == 0)
            cout << 'A';
        else
            cout << 'C';
    }
 
    //system("pause > nul");
}