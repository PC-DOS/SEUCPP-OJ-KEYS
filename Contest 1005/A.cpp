#include <iostream>
#include <string>
using namespace std;
int main(){
    int c5, c1, c2;
    for (c5 = 1; c5 <= 4; ++c5)
        for (c2 = 1; c2 <= 9; ++c2)
            for (c1 = 1; c1 <= 19; ++c1)
                if ((c5 * 5 + c2 * 2 + c1 * 1) == 20) cout << c5 << ' ' << c2 << ' ' << c1 << endl;
    //system("pause > nul");
}