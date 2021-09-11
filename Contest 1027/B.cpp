#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    int iNum;
    cin>>iNum;
    cout<<(iNum%2==0 && (iNum>4 && iNum<=12) ? 1 : 0)<<' '
        <<(iNum%2==0 || (iNum>4 && iNum<=12) ? 1 : 0)<<' '
        <<(iNum%2==0 ^ (iNum>4 && iNum<=12) ? 1 : 0)<<' '
        <<(iNum%2!=0 && !(iNum>4 && iNum<=12) ? 1 : 0)<<' ';
    return 0;
}