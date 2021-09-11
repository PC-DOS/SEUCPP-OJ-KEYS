#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a[8],i;
    for (i=0;i<=7;++i){
        cin>>a[i];
    }
    sort(a,a+8);
    for (i=0;i<=6;++i){
        cout<<a[i]<<' ';
    }
    cout<<a[7];
    return 0;
}