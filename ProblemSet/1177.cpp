#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;
 
int main(){
    vector<int> arrNums;
    int iNum;
    bool IsFound = false;
 
    for (int i = 1; i <= 5; ++i){
        cin >> iNum;
        arrNums.push_back(iNum);
    }
    cin >> iNum;
 
    for (int i = 0; i < arrNums.size(); ++i){
        if (arrNums[i] == iNum){
            IsFound = true;
            break;
        }
    }
 
    cout << (IsFound ? "YES" : "NO");
 
endapp:
    //system("pause > nul");
 
    return 0;
}