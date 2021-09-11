#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
long CombineSpecial(int M, int N){
    if (M == 1)
        return 1;
    else if (M == 0)
        return 1;
    else if (N == 1)
        return 1;
    else if (N == 0)
        return 0;
    else if (M < N){
        N = M;
        return CombineSpecial(M, N - 1) + CombineSpecial(M - N, N);
    }
    else
        return CombineSpecial(M, N - 1) + CombineSpecial(M - N, N);
}
int main(){
    int M, N;
    cin >> M >> N;
    cout << CombineSpecial(M, N);
    //system("pause > nul");
    return 0;
}