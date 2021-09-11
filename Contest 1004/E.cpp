#include <iostream>
#include <string>
using namespace std;
int main(){
    string current;
    long count = 0;
    unsigned long i=0;
    bool in, out;
    out = true;
    in = false;
    getline(cin, current);
    for (i = 0; i <= current.length()-1 ; ++i){
        if ((int(current[i]) >= 65 && int(current[i]) <= 90) || (int(current[i]) >= 97 && int(current[i]) <= 123))
        {
            in = true;
            if (out == true){
                ++count;
                out = false;
            }
        }
            else
        {
            in = false;
            out = true;
            //++count;
        }
 
    }
    std::cout << count;
    //system("pause > nul");
}