#include <iostream>
#include <string>
#include <vector>
#include <map>
 
using namespace std;
 
int main(){
    int iNum;
    int iSum = 0;
    cin >> iNum;
 
    for (int i = 1; i < iNum; ++i){
        if (iNum%i == 0){
            iSum += i;
        }
    }
 
    cout << (iSum == iNum ? "YES" : "NO");
 
endapp:
    //system("pause > nul");
 
    return 0;
}