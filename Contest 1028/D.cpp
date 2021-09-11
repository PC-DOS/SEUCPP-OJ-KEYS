#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int> arrNumbers;
    int nCount = 0, i, n,tmp,max=0;
    cin >> n;
    for (i = 0; i <= n - 1; ++i){
        cin >> tmp;
        arrNumbers.push_back(tmp);
    }
    for (i = 1; i <= n - 1; ++i){
        //cout << arrNumbers[i] << ' ' <<arrNumbers[i-1]<< ' '<<nCount << endl;
        if (arrNumbers[i] == arrNumbers[i - 1] + 1){
            ++nCount;
            if (nCount >= max)
                max = nCount;
        }
        else
            nCount = 0;
    }
    cout << max+1;
    //system("pause > nul");
    return 0;
}