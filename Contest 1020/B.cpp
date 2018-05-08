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
    vector<int> a;
    cin >> iInput;
    while (iInput != -1){
        a.push_back(iInput);
        cin >> iInput;
    }
    cout << a[ceil(a.size() / 2.0)-1];
endapp:
    //system("pause > nul");
    return 0;
}