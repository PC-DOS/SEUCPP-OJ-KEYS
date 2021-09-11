#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
long GetNonOddCount(long number){
    string num;
    long nCount = 0;
    num = to_string(number);
    long i;
    int tmp;
    for (i = 0; i <= num.length() - 1; ++i){
        tmp = num[i] - '0';
        if (tmp % 2 == 0)
            ++nCount;
    }
    return nCount;
}
void Process(int n){
    n = abs(n);
    int Num;
    int Count_NotOdd;
    int Count_Odd;
    int i=0;
    if (n == 321)
        cout << 321;
    else
        if (n == 0){
            cout << 101 << endl;
            Process(101);
        }
        else{
            Num = int(log10(n)) + 1;
            Count_NotOdd = GetNonOddCount(n);
            Count_Odd = Num - Count_NotOdd;
            i += Count_NotOdd;
            if (i == 0)
                i += Count_Odd * 10;
            else
                i += Count_Odd*pow(10, int(log10(i)) + 1);
            i +=Num*pow(10, int(log10(i)) + 1);
            if (i != 321) cout << i << endl;
            Process(i);
        }
 
}
int main(){
    long n;
    cin >> n;
    Process(n);
    //system("pause > nul");
    return 0;
}