#include <iostream>
using namespace std;
int main(){
    int length, count_trees;
    int count_ranges;
    int metrostart[100];
    int metroend[100];
    int i,j;
    cin >> length >> count_ranges;
    count_trees = length + 1;
    for (i = 0; i <= count_ranges-1; ++i) cin >> metrostart[i] >> metroend[i];
    for (i = 0; i <= length; ++i){
        for (j = 0; j <= count_ranges - 1; ++j){
            if (metrostart[j] <= i && metroend[j] >= i){
                --count_trees;
                break;
            }
        }
    }
    cout << count_trees;
    //system("pause > nul");
    return 0;
}