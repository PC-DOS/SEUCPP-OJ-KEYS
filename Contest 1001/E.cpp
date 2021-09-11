#include <iostream>
using namespace std;
 
int main(){
    double dNum1,dNum2;
    cin>>dNum1>>dNum2;
    while (dNum1>=dNum2){
        dNum1-=dNum2;
    }
    cout<<dNum1;
    return 0;
}