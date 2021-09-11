#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    int nCount;
    int iTemp;
    vector<int> arrNums;
    nCount=3;
    for (int i=1;i<=nCount;++i){
        cin>>iTemp;
        arrNums.push_back(iTemp);
    }
    sort(arrNums.begin(),arrNums.end());
    for (int i=0;i<arrNums.size();++i){
        cout<<arrNums[i]<<' ';
    }
    return 0;
}