#include <iostream>
using namespace std;
int main(){
    int i=0,j=0;
    for (i = 1; i <= 5; ++i){
        for (j = 1; j <= i*2-1; ++j) cout << '*';
        cout << endl;
    }
    //system("pause > nul");
    return 0;
}