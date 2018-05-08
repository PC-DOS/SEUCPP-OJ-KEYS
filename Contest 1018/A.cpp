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
#define MATH_PI 3.14159265358979323846
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
                gamObject.data.iHP -= max((data.iATK - gamObject.data.iDEF + data.iBasicHurt)*data.iSPD / (data.iSPD + gamObject.data.iSPD),1LL);
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
    ios::sync_with_stdio(false);
    register int i;
    int nCount = 0;
    Data dat;
    cin >> dat.sName >> dat.sType >> dat.iLevel >> dat.iExp >> dat.iHP >> dat.iBasicHurt >> dat.iATK >> dat.iDEF >> dat.iSPD;
    cout << dat.sName << ' ' << dat.sType << ' ' << dat.iLevel << ' ' << dat.iExp << ' ' << dat.iHP << ' ' << dat.iBasicHurt << ' ' << dat.iATK << ' ' << dat.iDEF << ' ' << dat.iSPD<<endl;
    Game gme(dat);
    Data datZombie;
    datZombie.sName = "Zombie";
    datZombie.iLevel = 0;
    datZombie.sType = "dwarf";
    datZombie.iExp = 0;
    datZombie.iHP = 2500;
    datZombie.iATK = 15;
    datZombie.iDEF = 20;
    datZombie.iSPD = 30;
    datZombie.iBasicHurt = 0; //TODO: WAITING FOR RESPONSE
    Game objZombie(datZombie);
    Weapon wepYitianjian, wepTianlongdun, wepTianshizhiyi;
    wepYitianjian.sName = "Yi Tian Jian";
    wepYitianjian.iBasicHurtAdd = 0;
    wepYitianjian.iAttackAdd = 100;
    wepYitianjian.iDefenceAdd = 20;
    wepYitianjian.iSpeedAdd = 20;
    wepYitianjian.iHPAdd = 500;
    wepYitianjian.iPrice = 5000;
    wepTianlongdun.sName = "Tian Long Dun";
    wepTianlongdun.iBasicHurtAdd = 0;
    wepTianlongdun.iAttackAdd = 20;
    wepTianlongdun.iDefenceAdd = 100;
    wepTianlongdun.iSpeedAdd = 20;
    wepTianlongdun.iHPAdd = 1000;
    wepTianlongdun.iPrice = 5000;
    wepTianshizhiyi.sName = "Tian Shi Zhi Yi";
    wepTianshizhiyi.iBasicHurtAdd = 0;
    wepTianshizhiyi.iAttackAdd = 20;
    wepTianshizhiyi.iDefenceAdd = 20;
    wepTianshizhiyi.iSpeedAdd = 100;
    wepTianshizhiyi.iHPAdd = 300;
    wepTianshizhiyi.iPrice = 5000;
    Pill pilXiaohuandan, pilJinghuadan, pilBaojidan;
    pilXiaohuandan.sName = "Xiao Huan Dan";
    pilXiaohuandan.iBasicHurtAdd = 0;
    pilXiaohuandan.iAttackAdd = 0;
    pilXiaohuandan.iDefenceAdd = 0;
    pilXiaohuandan.iSpeedAdd = 0;
    pilXiaohuandan.iHPAdd = 500;
    pilXiaohuandan.iPrice = 1000;
    pilJinghuadan.sName = "Jing Hua Dan";
    pilJinghuadan.iBasicHurtAdd = 5;
    pilJinghuadan.iAttackAdd = 10;
    pilJinghuadan.iDefenceAdd = 10;
    pilJinghuadan.iSpeedAdd = 10;
    pilJinghuadan.iHPAdd = 100;
    pilJinghuadan.iPrice = 1000;
    pilBaojidan.sName = "Bao Ji Dan";
    pilBaojidan.iBasicHurtAdd = 5;
    pilBaojidan.iAttackAdd = 30;
    pilBaojidan.iDefenceAdd = 0;
    pilBaojidan.iSpeedAdd = 0;
    pilBaojidan.iHPAdd = 0;
    pilBaojidan.iPrice = 1000;
    int iWepIndex;
    int nMoney = 10000;
    cin >> iWepIndex;
    switch (iWepIndex){
    case 1:
        gme += wepYitianjian;
        nMoney -= wepYitianjian.iPrice;
        break;
    case 2:
        gme += wepTianlongdun;
        nMoney -= wepTianlongdun.iPrice;
        break;
    case 3:
        gme += wepTianshizhiyi;
        nMoney -= wepTianshizhiyi.iPrice;
        break;
    };
    cout << gme.data.sName << ' ' << gme.data.sType << ' ' << gme.data.iLevel << ' ' << gme.data.iExp << ' ' << gme.data.iHP << ' ' << gme.data.iBasicHurt << ' ' << gme.data.iATK << ' ' << gme.data.iDEF << ' ' << gme.data.iSPD<<endl;
    int iPilIndex, nPill;
    Pill pilCurrent;
    cin >> iPilIndex >> nPill;
    switch (iPilIndex){
    case 1:
        pilCurrent = pilXiaohuandan;
        break;
    case 2:
        pilCurrent = pilJinghuadan;
        break;
    case 3:
        pilCurrent = pilBaojidan;
        break;
    }
    nPill = min(nPill, nMoney / pilCurrent.iPrice);
    nMoney -= pilCurrent.iPrice*nPill;
    for (i = 1; i <= nPill; ++i){
        gme += pilCurrent;
    }
    cout << gme.data.sName << ' ' << gme.data.sType << ' ' << gme.data.iLevel << ' ' << gme.data.iExp << ' ' << gme.data.iHP << ' ' << gme.data.iBasicHurt << ' ' << gme.data.iATK << ' ' << gme.data.iDEF << ' ' << gme.data.iSPD << endl;
    //while (gme.Battle(datZombie)){
    //  ++nCount;
    //}
    //cout << nCount;
    endapp:
    //system("pause > nul");
    return 0;
}