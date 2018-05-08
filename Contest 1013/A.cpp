#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct Student{
    string iIndex;
    string sName;
    int Math, Phi, Com, Sum;
};
int main(){
    ios::sync_with_stdio(false);
    Student stuStudent;
    cin >> stuStudent.iIndex >> stuStudent.sName >> stuStudent.Math >> stuStudent.Phi >> stuStudent.Com;
    stuStudent.Sum = stuStudent.Com + stuStudent.Phi + stuStudent.Math;
    cout << "No:" << stuStudent.iIndex << endl << "Name:" << stuStudent.sName << endl << "Math:" << stuStudent.Math << endl << "Phi:" << stuStudent.Phi <<endl<<"Com:"<< stuStudent.Com<<"\nTotal:"<<stuStudent.Sum;
endapp:
    //system("pause > nul");
    return 0;
}