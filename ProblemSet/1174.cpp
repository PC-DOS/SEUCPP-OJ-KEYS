#include <iostream>
#include <string>
#include <vector>
#include <map>
 
using namespace std;
 
int main(){
    int iScore;
    cin >> iScore;
    if (iScore >= 90){
        cout << "A" << endl;
    }
    else if (iScore >= 80){
        cout << "B" << endl;
    }
    else if (iScore >= 70){
        cout << "C" << endl;
    }
    else if (iScore >= 60){
        cout << "D" << endl;
    }
    else{
        cout << "E" << endl;
    }
 
endapp:
    //system("pause > nul");
 
    return 0;
}