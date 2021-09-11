#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
 
int main(){
    int arrChar[26]={0};
    string sInput;
    getline(cin,sInput);
    for (int i=0; i<sInput.length()-1; ++i){
        if (sInput[i]>='A' && sInput[i]<='Z'){
            ++arrChar[sInput[i]-'A'];
        }
        else if (sInput[i]>='a' && sInput[i]<='z'){
            ++arrChar[sInput[i]-'a'];
        }
    }
    for (int i = 0; i<26; ++i){
        if (arrChar[i]){
            cout<<char('A'+i)<<'('<<char('a'+i)<<"):"<<arrChar[i]<<endl;
        }
    }
    return 0;
}