#include <iostream>
#include <string>
using namespace std;
int main(){
    string current;
    int i = 0,c=0;
    cin >> current;
    for (i = 0; i <= current.length() -1; ++i){
        if (current[i] >= '0' && current[i] <= '9') ++c;
    }
    std::cout << c;
    //system("pause > nul");
}