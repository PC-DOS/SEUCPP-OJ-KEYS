#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
  
int main(){
    int iLen;
    cin>>iLen;
    int iNum=1;
    for (int iHght=1; iHght<=iLen; ++iHght){
        for (int iWdth=1; iWdth<=iLen-iHght+1; ++iWdth){
            if (iNum<10){
                cout<<'0'<<iNum;
            }
            else{
                cout<<iNum;
            }
            ++iNum;
        }
        cout<<endl;
    }
    return 0;
}