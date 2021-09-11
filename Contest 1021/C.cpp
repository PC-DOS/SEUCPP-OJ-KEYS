#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    string sCode;
    long long i, nCount = 0;
    getline(cin, sCode);
    for (i = 0; i <= sCode.length(); ++i){
        if (sCode[i] == '(')
            ++nCount;
        else if (sCode[i] == ')'){
            if (nCount>0) 
                --nCount;
            else{
                cout << "NO";
                goto endapp;
            }
        }
        if (sCode[i] == '@') break;
    }
    if (sCode[0] == ')'){
        cout << "NO";
        goto endapp;
    }
    if (sCode[i-1] == '('){
        cout << "NO";
        goto endapp;
    }
    if (nCount == 0)
        cout << "YES";
    else
        cout << "NO";
    endapp:
    //system("pause > nul");
    return 0;
}