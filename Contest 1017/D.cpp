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
    vector<vector<int>> arrMatrix;
    vector<int> arrLine;
    int iIn, nRow, nCol;
    register int i, j;
    cin >> nRow >> nCol;
    for (i = 1; i <= nRow; ++i){
        arrLine.clear();
        for (j = 1; j <= nCol; ++j){
            cin >> iIn;
            arrLine.push_back(iIn);
        }
        arrMatrix.push_back(arrLine);
    }
    for (i = 0; i < nRow; ++i){
        for (j = 0; j < nCol; ++j){
            cout << arrMatrix[i][j] << ' ';
        }
        cout << endl;
    }
    for (j = 0; j < nCol; ++j){
        for (i = 0; i < nRow; ++i){
            cout << arrMatrix[i][j] << ' ';
        }
        cout << endl;
    }
    //system("pause > nul");
    return 0;
}