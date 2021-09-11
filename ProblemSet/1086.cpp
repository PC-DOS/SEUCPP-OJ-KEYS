#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a[5],i,k;
    for (i=0;i<=4;++i) cin>>a[i];
    cin>>k;
    for (i=0;i<=4;++i){
        if (a[i]==k){
            cout<<i;
            exit(0);
        }
    }
    cout<<-1;
    return 0;
}