#include <iostream>
using namespace std;
int main(){
    int i=0;
    for (i = 1; i <= 99; ++i){
        if (i % 3 == 0 && i % 10 == 6) 
            cout << i << ' ';
    }
    //system("pause > nul");
    return 0;
}