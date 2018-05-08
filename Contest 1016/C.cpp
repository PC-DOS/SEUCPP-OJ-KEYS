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
    bool IsFail = true;
    int iInput, i;
    for (i = 1; i <= 5; ++i){
        cin >> iInput;
        arrNums.push_back(iInput);
        cout << iInput << ' ';
    }
    cout << endl;
    cin >> iInput;
    arrNums.push_back(iInput);
    for (i = 0; i <= 5; ++i){
        cout << arrNums[i] << ' ';
    }
    cout << endl;
    cin >> iInput;
    if (iInput >= 0 && iInput <= 5){
        IsFail = false;
        arrNums.erase(arrNums.begin()+iInput);
    }
    for (i = 0; i <= 4 + int(IsFail); ++i){
        cout << arrNums[i] << ' ';
    }
    cout << endl;
    reverse(arrNums.begin(), arrNums.end());
    for (i = 0; i <= 4+int(IsFail); ++i){
        cout << arrNums[i] << ' ';
    }
    cout << endl;
    cout << *max_element(arrNums.begin(), arrNums.end());
endapp:
    //system("pause > nul");
    return 0;
}