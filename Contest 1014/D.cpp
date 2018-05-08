#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct Data{
    string sName;
    string sType;
    long long iLevel;
    long long iExpNext;
    long long iExp;
    long long iHP;
    long long iATK;
    long long iDEF;
    long long iSPD;
};
class Game{
public:
    Data data;
    Game operator++();
    Game(Data datSet);
};
Game::Game(Data datSet){
    data = datSet;
    data.iExpNext = 1000 * pow(1.1, data.iLevel - 1);
}
Game Game::operator++(){
    if (data.sType == "swordman"){
        ++data.iLevel;
        data.iExp = 0;
        data.iExpNext *= 1.1;
        data.iHP += 100;
        data.iATK += 20;
        data.iDEF += 5;
        data.iSPD += 10;
    }
    else if (data.sType == "dwarf"){
        ++data.iLevel;
        data.iExp = 0;
        data.iExpNext *= 1.1;
        data.iHP += 200;
        data.iATK += 10;
        data.iDEF += 20;
        data.iSPD += 5;
    }
    else if (data.sType == "shooter"){
        ++data.iLevel;
        data.iExp = 0;
        data.iExpNext *= 1.1;
        data.iHP += 150;
        data.iATK += 5;
        data.iDEF += 10;
        data.iSPD += 20;
    }
    return *this;
}
int main(){
    ios::sync_with_stdio(false);
    Data dat;
    cin >> dat.sName >> dat.sType >> dat.iLevel >> dat.iExp >> dat.iHP >> dat.iATK >> dat.iDEF >> dat.iSPD;
    Game gme(dat);
    long long iExp;
    cin >> iExp;
    iExp -= dat.iExp;
    while ((iExp -= gme.data.iExpNext) >= 0){
        ++gme;
        gme.data.iExp = iExp;
    }
    cout << gme.data.sName << ' ' << gme.data.sType << ' ' << gme.data.iLevel << ' ' << gme.data.iExp << ' ' << gme.data.iHP << ' ' << gme.data.iATK << ' ' << gme.data.iDEF << ' ' << gme.data.iSPD << endl;
endapp:
    //system("pause > nul");
    return 0;
}