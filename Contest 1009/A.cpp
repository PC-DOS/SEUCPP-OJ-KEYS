#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int a[10], i,maxP,minP,maxN,minN,nP=0,nN=0,SumP=0,SumN=0,avgP,avgN;
    vector<int> N, P;
    for (i = 0; i <= 9; ++i) cin >> a[i];
    maxP = a[0];
    maxN = a[0];
    minP = a[0];
    minN = a[0];
    for (i = 0; i <= 9; ++i){
        if (a[i] < 0){
            ++nN;
            SumN+=a[i];
            N.push_back(a[i]);
        }
        else{
            ++nP;
            SumP+=a[i];
            P.push_back(a[i]);
        }
    }
     
    cout << *max_element(begin(P),end(P)) << ' ' <<*min_element(begin(P),end(P))<<' '<< double(SumP) / double(nP)<<endl;
    cout << *max_element(begin(N), end(N)) << ' ' << *min_element(begin(N), end(N)) <<' '<< double(SumN) / double(nN);
    //system("pause > nul");
    return 0;
}