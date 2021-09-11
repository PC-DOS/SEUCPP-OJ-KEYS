#include <iostream>
using namespace std;
int main(){
    int n,tmp;
    //s:
    cin >> n;
    if (n <= 0 || n > 12){
        cout << "bad";
        goto end;
    }
    if (n == 1 || n == 2) n = 13;
    tmp = n / 3;
    switch (tmp){
    case 1:{
        cout << "spring";
        break; }
    case 2:{
        cout << "summer";
        break; }
    case 3:{
        cout << "autumn";
        break; }
    case 4:{
        cout << "winter"; 
        break; }
 
    }
    //goto s;
    end:
    return 0;
    //system("pause > nul");
}