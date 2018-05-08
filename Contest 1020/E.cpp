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
    bool arrPeople[100];
    int nPeopleCurrent, nPeopleCount, iM, i, j = 1;
    for (i = 0; i <= 99; ++i) arrPeople[i] = true;
    cin >> nPeopleCount >> iM;
    nPeopleCurrent = nPeopleCount;
    while (nPeopleCurrent > 1){
        for (i = 0; i <= nPeopleCount - 1; ++i){
            if (arrPeople[i] == false) continue;
            if (j == iM){
                arrPeople[i] = false;
                cout << i + 1 << ' ';
                --nPeopleCurrent;
                j = 0;
            }
            ++j;
        }
    }
    cout << endl;
    for (i = 0; i <= nPeopleCount - 1; ++i){
        if (arrPeople[i])
            cout << i + 1;
    }
endapp:
    //system("pause > nul");
    return 0;
}