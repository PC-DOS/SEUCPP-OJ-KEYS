#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
struct Point
{
    long long lX;
    long long lY;
};
struct CriticalPoint{
    Point pntPosition;
    long long iLastBombed=0;
    long long nCount=0;
};
struct BombedRectangle{
    Point pntLeftUpper;
    Point pntRitghtDown;
};
bool isPointCovered(Point pntLeftUpper, Point pntRightDown, Point pntTest){
    if (pntLeftUpper.lX <= pntTest.lX && pntRightDown.lX >= pntTest.lX && pntLeftUpper.lY <= pntTest.lY && pntRightDown.lY >= pntTest.lY)
        return true;
    else
        return false;
}
int main(){
    ios::sync_with_stdio(false);
    long long nBombedCount, nCriticalPointsCount=1,i,j;
    vector<BombedRectangle> arrBombedArea;
    BombedRectangle rcdBombed;
    vector<CriticalPoint> arrCriticalPoints;
    CriticalPoint pntCritical;
    cin >> nBombedCount;
    for (i = 1; i <= nBombedCount; ++i){
        cin >> rcdBombed.pntLeftUpper.lX >> rcdBombed.pntLeftUpper.lY >> rcdBombed.pntRitghtDown.lX >> rcdBombed.pntRitghtDown.lY;
        rcdBombed.pntRitghtDown.lX = rcdBombed.pntLeftUpper.lX + rcdBombed.pntRitghtDown.lX;
        rcdBombed.pntRitghtDown.lY = rcdBombed.pntLeftUpper.lY + rcdBombed.pntRitghtDown.lY;
        arrBombedArea.push_back(rcdBombed);
    }
    for (i = 1; i <= nCriticalPointsCount; ++i){
        cin >> pntCritical.pntPosition.lX >> pntCritical.pntPosition.lY;
        for (j = 0; j <= nBombedCount - 1; ++j){
            if (isPointCovered(arrBombedArea[j].pntLeftUpper, arrBombedArea[j].pntRitghtDown, pntCritical.pntPosition)){
                ++pntCritical.nCount;
                pntCritical.iLastBombed = j + 1;
            }
        }
        arrCriticalPoints.push_back(pntCritical);
        pntCritical.nCount = 0;
        pntCritical.iLastBombed = 0;
    }
    for (i = 0; i <= nCriticalPointsCount - 1; ++i){
        if (arrCriticalPoints[i].nCount != 0)
            cout <<arrCriticalPoints[i].iLastBombed << endl;
        else
            cout << "-1";
    }
endapp:
    //system("pause > nul");
    return 0;
}