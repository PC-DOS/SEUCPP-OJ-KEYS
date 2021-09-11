#include <iostream>
#include <cstdlib>
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
    vector<int> arrOdd, arrEven;
    int nCount, iInput, i;
    cin >> nCount;
    while (nCount--){
        cin >> iInput;
        if (iInput % 2 == 0)
            arrEven.push_back(iInput);
        else
            arrOdd.push_back(iInput);
    }
    nCount = min(arrOdd.size(), arrEven.size());
    for (i = 0; i < nCount; ++i){
        cout << arrOdd[i] << ' ' << arrEven[i] << endl;
    }
    if (arrOdd.size() > arrEven.size()){
        for (i = nCount; i < arrOdd.size(); ++i){
            cout << arrOdd[i] << ' ';
        }
    }
    if (arrOdd.size() < arrEven.size()){
        for (i = nCount; i < arrEven.size(); ++i){
            cout << arrEven [i] << ' ';
        }
    }
endapp:
    //system("pause > nul");
    return 0;
}