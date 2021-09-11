#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <map>
#include <climits>
#include <bitset>
 
using namespace std;
 
class Weapon{
public:
    string sName;
    int iBasicHurtAdd;
    int iAttackAdd;
    int iDefenceAdd;
    int iSpeedAdd;
    int iHPAdd;
    int iPrice;
};
class Pill{
public:
    string sName;
    int iBasicHurtAdd;
    int iAttackAdd;
    int iDefenceAdd;
    int iSpeedAdd;
    int iHPAdd;
    int iPrice;
};
struct Data{
    string sName;
    string sType;
    long long iLevel;
    long long iExpNext;
    long long iExp;
    long long iHP;
    long long iHPCurrent;
    long long iATK;
    long long iDEF;
    long long iSPD;
    long long iBasicHurt;
};
class Game{
public:
    Data data;
    Weapon wepWeapon;
    vector<Pill> arrPills;
    Game operator++();
    Game operator+=(Weapon wepWeaponAdd);
    Game operator-=(Weapon wepWeaponAdd);
    Game operator+=(Pill pilPillAdd);
    Game(Data datSet);
    bool Battle(Game gmeObj);
};
Game::Game(Data datSet){
    data = datSet;
    data.iExpNext = 1000 * pow(1.1, data.iLevel - 1);
    data.iHPCurrent = data.iHP;
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
Game Game::operator+=(Weapon wepWeaponAdd){
    data.iBasicHurt += wepWeaponAdd.iBasicHurtAdd;
    data.iATK += wepWeaponAdd.iAttackAdd;
    data.iDEF += wepWeaponAdd.iDefenceAdd;
    data.iHP += wepWeaponAdd.iHPAdd;
    data.iHPCurrent += wepWeaponAdd.iHPAdd;
    data.iSPD += wepWeaponAdd.iSpeedAdd;
    this->wepWeapon = wepWeaponAdd;
    return *this;
}
Game Game::operator-=(Weapon wepWeaponAdd){
    if (wepWeaponAdd.sName != this->wepWeapon.sName){
        return *this;
    }
    data.iBasicHurt -= wepWeaponAdd.iBasicHurtAdd;
    data.iATK -= wepWeaponAdd.iAttackAdd;
    data.iDEF -= wepWeaponAdd.iDefenceAdd;
    data.iHP -= wepWeaponAdd.iHPAdd;
    data.iSPD -= wepWeaponAdd.iSpeedAdd;
    this->wepWeapon.sName = "";
    return *this;
}
Game Game::operator+=(Pill pilPillAdd){
    data.iBasicHurt += pilPillAdd.iBasicHurtAdd;
    data.iATK += pilPillAdd.iAttackAdd;
    data.iDEF += pilPillAdd.iDefenceAdd;
    data.iHP += pilPillAdd.iHPAdd;
    data.iSPD += pilPillAdd.iSpeedAdd;
    return *this;
}
bool Game::Battle(Game gamObject){
    long long iHPBack = gamObject.data.iHP;
    while (1){
        if (this->data.iSPD >= gamObject.data.iSPD){
            if (this->data.iATK > gamObject.data.iDEF){
                gamObject.data.iHP -= max((data.iATK - gamObject.data.iDEF + data.iBasicHurt)*data.iSPD / (data.iSPD + gamObject.data.iSPD), 1LL);
            }
            else{
                gamObject.data.iHP -= max((data.iBasicHurt)*data.iSPD / (data.iSPD + gamObject.data.iSPD), 1LL);
            }
            if (gamObject.data.iHP <= 0){
                long long iExp = iHPBack;
                while ((iExp -= data.iExpNext) >= 0){
                    ++(*this);
                    data.iExp = iExp;
                }
                return true;
            }
            if (data.iDEF < gamObject.data.iATK){
                data.iHP -= max((gamObject.data.iATK - data.iDEF + gamObject.data.iBasicHurt)*gamObject.data.iSPD / (data.iSPD + gamObject.data.iSPD), 1LL);
            }
            else{
                data.iHP -= max((gamObject.data.iBasicHurt)*gamObject.data.iSPD / (data.iSPD + gamObject.data.iSPD), 1LL);
            }
            if (data.iHP <= 0){
                return false;
            }
        }
        else{
            if (data.iDEF < gamObject.data.iATK){
                data.iHP -= max((gamObject.data.iATK - data.iDEF + gamObject.data.iBasicHurt)*gamObject.data.iSPD / (data.iSPD + gamObject.data.iSPD), 1LL);
            }
            else{
                data.iHP -= max((gamObject.data.iBasicHurt)*gamObject.data.iSPD / (data.iSPD + gamObject.data.iSPD), 1LL);
            }
            if (data.iHP <= 0){
                return false;
            }
            if (this->data.iATK > gamObject.data.iDEF){
                gamObject.data.iHP -= max((data.iATK - gamObject.data.iDEF + data.iBasicHurt)*data.iSPD / (data.iSPD + gamObject.data.iSPD), 1LL);
            }
            else{
                gamObject.data.iHP -= max((data.iBasicHurt)*data.iSPD / (data.iSPD + gamObject.data.iSPD), 1LL);
            }
            if (gamObject.data.iHP <= 0){
                long long iExp = iHPBack;
                while ((iExp -= data.iExpNext) >= 0){
                    ++(*this);
                    data.iExp = iExp;
                }
                return true;
            }
        }
    }
}
 
int main(){
    Data datChar;
    cin >> datChar.sName >> datChar.sType >> datChar.iLevel >> datChar.iExp >> datChar.iHP >> datChar.iATK >> datChar.iDEF >> datChar.iSPD;
 
    Game gamData(datChar);
 
    long long iExp;
    cin >> iExp;
    long long iExpCur;
    while (iExp>=gamData.data.iExpNext){
        iExpCur = gamData.data.iExpNext;
        ++gamData;
        iExp -= iExpCur;
    }
    gamData.data.iExp = iExp;
 
    cout << gamData.data.sName << ' ' << gamData.data.sType << ' ' << gamData.data.iLevel << ' ' << gamData.data.iExp << ' ' << gamData.data.iHP << ' ' << gamData.data.iATK << ' ' << gamData.data.iDEF << ' ' << gamData.data.iSPD<<endl;
 
endapp:
#ifdef _WIN32
    system("pause > nul");
#endif
 
    return 0;
}