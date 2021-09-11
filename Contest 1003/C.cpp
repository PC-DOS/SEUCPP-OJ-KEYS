#include <iostream>
#include <cmath>
using namespace std;
double distance(double x1, double y1, double x2, double y2){
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}
 
int main(){
    double x1, y1, x2, y2, x3, y3,l1,l2,l3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    l1 = distance(x1, y1, x2, y2);
    l2 = distance(x2, y2, x3, y3);
    l3 = distance(x3, y3, x1, y1);
    if ((l1 + l2 > l3) && (l1 + l3 > l2) && (l3 + l2 > l1) )
        cout << "OK";
    else
        cout << "BAD";
    //system("pause>nul");
}