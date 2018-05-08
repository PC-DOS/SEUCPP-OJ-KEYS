#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <map>
#include <climits>
#include <bitset>
using namespace std;
#define MATH_PI 3.14159265358979323846
int main(){
    ios::sync_with_stdio(false);
    int iInput;
    vector<int> a,b;
    cin >> iInput;
    while (iInput != -1){
        a.push_back(iInput);
        cin >> iInput;
    }
    cin >> iInput;
    while (iInput != -1){
        b.push_back(iInput);
        cin >> iInput;
    }
    register int i;
    for (i = 0; i < b.size(); ++i){
        a.push_back(b[i]);
    }
    sort(a.begin(), a.end());
    for (i = 0; i < a.size(); ++i){
        cout << a[i] << ' ';
    }
endapp:
    //system("pause > nul");
    return 0;
}