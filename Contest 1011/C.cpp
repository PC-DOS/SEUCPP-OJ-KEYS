#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
bool cmp(char chr1, char chr2){
    return chr1>chr2;
}
 
int main(){
    string sInput;
    getline(cin,sInput);
    sInput=sInput.erase(sInput.length()-1,1);
    sort(sInput.begin(), sInput.end(), cmp);
    cout<<sInput;
    return 0;
}