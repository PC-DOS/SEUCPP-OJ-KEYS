#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
  
int main(){
    string sNum;
    cin>>sNum;
    for (int i=sNum.length()-1;i>=0;--i){
        cout<<sNum[i];
    }
    return 0;
}