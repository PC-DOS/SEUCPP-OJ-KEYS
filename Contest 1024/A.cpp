#include <iostream>
#include <iomanip>
using namespace std;
struct data{
    int school;
    int extra;
    int unhappy_value;
};
int main(){
    data aweek[7];
    int i;
    for (i = 0; i <= 6; ++i){
        cin >> aweek[i].school >> aweek[i].extra;
        aweek[i].unhappy_value = aweek[i].school + aweek[i].extra - 8;
    }
    int max=0,day=0;
    for (i = 0; i <= 6; ++i){
        if (aweek[i].unhappy_value > max){
            max = aweek[i].unhappy_value;
            day = i+1;
        }
        else
            continue;
    }
    cout << day;
    //system("pause > nul");
    return 0;
}