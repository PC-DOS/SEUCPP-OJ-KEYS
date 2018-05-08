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
    vector<int> arrNums;
    register int i, iIn;
    int nCount,iFind;
    cin >> nCount;
    for (i = 1; i <= nCount; ++i){
        cin >> iIn;
        arrNums.push_back(iIn);
    }
    cin >> iFind;
    for (i = 0; i < nCount; ++i){
        cout << arrNums[i] << ' ';
    }
    cout << endl;
    for (i = 0; i < nCount; ++i){
        if (arrNums[i] > iFind){
            cout << arrNums[i] << ' ';
            arrNums.push_back(arrNums[i]);
        }
    }
    cout << endl;
    for (i = 0; i < arrNums.size(); ++i){
        cout << arrNums[i] << ' ';
    }
    //system("pause > nul");
    return 0;
}