#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class Cow{
private:
    int iAge;
    int iMass;
public:
    Cow(){
        iAge = 0;
        iMass = 50;
    }
    Cow(int iMassSet){
        iMass = iMassSet;
        iAge = 0;
    }
    void FeedMilk(){
        if (iAge <= 12){
            iMass += 20;
            ++iAge;
        }
        return;
    }
    void FeedGrass(){
        iMass += 50;
        ++iAge;
    }
    void Milk(){
        iMass -= 40;
        ++iAge;
    }
    int GetAge(){
        return iAge;
    }
    int GetMass(){
        return iMass;
    }
};
int main(){
    ios::sync_with_stdio(false);
    Cow cowDef;
    int iMass;
    cin >> iMass;
    Cow cowNew(iMass);
    while (cowNew.GetAge() <= 12){
        cowNew.FeedMilk();
    }
    while (cowNew.GetAge() <= 120){
        cowNew.FeedGrass();
        cowNew.Milk();
    }
    cout << cowNew.GetMass() << ' ';
    while (cowDef.GetAge() <= 12){
        cowDef.FeedMilk();
    }
    while (cowDef.GetAge() <= 120){
        cowDef.FeedGrass();
        cowDef.Milk();
    }
    cout << cowDef.GetMass();
endapp:
    //system("pause > nul");
    return 0;
}