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
    int iInput,i;
    while (cin >> iInput){
        if (iInput == -1)
            break;
        arrNums.push_back(iInput);
    }
    for (i = 1; i <= arrNums.size();++i){
        cout << *min_element(arrNums.begin(), arrNums.begin() + i) << ' ';
    }
    cout << endl;
    for (i = arrNums.size()-1; i >= 1; --i){
        cout << *min_element(arrNums.begin(), arrNums.begin() + i) << ' ';
    }
endapp:
    //system("pause > nul");
    return 0;
}