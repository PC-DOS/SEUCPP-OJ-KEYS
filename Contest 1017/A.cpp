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
    string sInput;
    cin >> sInput;
    register int i;
    for (i = 0; i < sInput.length(); ++i){
        if (sInput[i] >= '0' && sInput[i] <= '9'){
            cout << sInput[i] << ' ';
        }
    }
    //system("pause > nul");
    return 0;
}