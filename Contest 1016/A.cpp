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
    double d1, d2;
    int i1, i2;
    cin >> i1 >> i2 >> d1 >> d2;
    swap(d1, d2);
    swap(i1, i2);
    cout << i1 << ' ' << i2 << endl << d1 << ' ' << d2;
 
endapp:
    //system("pause > nul");
    return 0;
}