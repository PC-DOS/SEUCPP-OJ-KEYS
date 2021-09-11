#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    int nCount;
    int iCurrentID;
    vector<int> arrIDs;
    int arrCount[1001]={0};
    cin>>nCount;
    for (int i=1; i<=nCount; ++i){
        cin>>iCurrentID;
        if (!arrCount[iCurrentID]){
            arrIDs.push_back(iCurrentID);
            ++arrCount[iCurrentID];
        }
    }
    sort(arrIDs.begin(),arrIDs.end());
    cout<<arrIDs.size()<<endl;
    for (int i=0; i<arrIDs.size(); ++i){
        cout<<arrIDs[i]<<' ';
    }   
    return 0;
}