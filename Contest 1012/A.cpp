#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
bool isIn(string s1, string s2){
    string stmp("");
    long long j, i;
    for (i = 0; i <= s1.length() - s2.length(); ++i){
        for (j = i; j <= s2.length() - 1; ++j){
            stmp += char(s1[j]);
        }
        if (stmp == s2) return true;
        stmp = "";
    }
    return false;
}
int main(){
    string s1, s2,stmp;
    long long j,i;
    getline(cin, s1);
    getline(cin, s2);
    if (isIn(s1, s2))
        cout << "YES";
    else
        cout << "NO";
    //system("pause > nul");
    return 0;
}