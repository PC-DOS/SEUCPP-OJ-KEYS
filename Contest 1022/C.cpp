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
    double iRadix, a, b, c, p, s;
    cin >> iRadix >> a >> b >> c;
    cout << 3.14*iRadix*iRadix<<' ';
    p = (a + b + c) / 2;
    s = sqrt(p*(p - a)*(p - b)*(p - c));
    cout << s;
endapp:
    //system("pause > nul");
    return 0;
}