#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
  
int main(){
    int nCount;
    int iCurrentVotes;
    int iCurrentMin=2147483647;
    cin>>nCount;
    for (int i=1;i<=nCount;++i){
        cin>>iCurrentVotes;
        if (iCurrentVotes<iCurrentMin){
            iCurrentMin=iCurrentVotes;
        }
    }
    cout<<iCurrentMin<<endl;
    return 0;
}