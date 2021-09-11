#include <iostream>
#include <iomanip>
using namespace std;
 
int main(){
    int iTotal, iDeath;
    cin>>iTotal>>iDeath;
    cout<<fixed<<setprecision(3)<<(double(iDeath)/double(iTotal))*100<<"%";
    return 0;
}