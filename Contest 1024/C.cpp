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
bool arrIsIn[5001] = { 0 };
int main(){
    int nCount, iTemp;
    cin >> nCount;
    for (int i = 1; i <= nCount; ++i){
        cin >> iTemp;
        if (arrIsIn[iTemp]){
            continue;
        }
        else{
            cout << iTemp << ' ';
            arrIsIn[iTemp] = true;
        }
    }
    return 0;
}