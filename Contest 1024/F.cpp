/*
Character Drawing Adapted from FAKEUPDATE.NET
           _    _____         _
           \`,""   ,'7"r-..__/ \
          ,'\ `, ,',','    _/   \
         /   \, 7 / /     (   \ |
        J     \/ j  L______\  / |
        L   __JF"""/""\"\_,    /
        L,-"| O|  f O |  L_  _/
        F   \_ /  \__/   `-  j|
            .-'    `"""    ,' |          _..====.._
            \__/         r"_  A        ,' _..---.._`,
             `-.______,,-L// / \  ___,' ,'_..:::.. `,`,
                      j   / / / 7"    `-<""=:'  '':. \ \
                     /   <,' /  F  . i , \   `,    :T W I
                     |    \,'  /    >X<  |     \   :| | L
                     |     `._/    ' ! ` |      I  :| |  G
                      \           \     /       |  :H T  |
                     __>-.__   __,-\   |        |  S P   |
                    /     /|   | \  \  \_       | 'A R   |
                   /   __/ |   |  L  L   \      K./ /    L
                  /   |    |   4  I  I    |    E./ /   ,'
                 J    \    I    L F  I    |    // / _,'
        _________|     |   F    |J   F    |   //_/-'
        \   __   |    /   J     |/  J     |  /="
        \\  \_\  \__,' \  F     |   F     |
        \\\_____________\/      F__/      F
         \\| 计算机编程 |_____/  (______/
          \/从入门到入土/
*/
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
#include <functional>
#include <cstdint>
using namespace std;
int arrMap[5][5] = { 0 };
vector<int> lstRow[5],lstCol[5];
bool IsFound = false;
int main(){
    int i, j;
    for (i = 0; i <= 4; ++i)
        for (j = 0; j <= 4; ++j)
            cin >> arrMap[i][j];
    for (i = 0; i <= 4; ++i)
        for (j = 0; j <= 4; ++j)
            lstRow[i].push_back(arrMap[i][j]);
    for (i = 0; i <= 4; ++i)
        for (j = 0; j <= 4; ++j)
            lstCol[i].push_back(arrMap[j][i]);
    for (i = 0; i <= 4; ++i){
        for (j = 0; j <= 4; ++j){
            if (arrMap[i][j] == *max_element(lstRow[i].begin(), lstRow[i].end()) && arrMap[i][j] == *min_element(lstCol[j].begin(), lstCol[j].end())){
                IsFound = true;
                cout << i + 1 << ' ' << j + 1 << ' ' << arrMap[i][j] << endl;
            }
        }
    }
    if (!IsFound){
        cout << "not found" << endl;
    }
endapp:
    //system("pause > nul");
    return 0;
}