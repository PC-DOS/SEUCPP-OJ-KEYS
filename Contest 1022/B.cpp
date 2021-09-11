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
struct Teacher{
    string sName,sGender,sAge,sID,sTitle,sSalary;
};
struct Student{
    string sName, sGender, sAge, sID, sClass,sMajor, sGrade;
};
int main(){
    ios::sync_with_stdio(false);
    Teacher tch;
    Student stu;
    cin >> tch.sName >> tch.sGender >> tch.sAge >> tch.sID >> tch.sTitle >> tch.sSalary;
    cin >> stu.sName >> stu.sGender >> stu.sAge >> stu.sID >> stu.sClass >> stu.sMajor >> stu.sGrade;
    cout << "name:" << tch.sName << " gender:" << tch.sGender << " age:" << tch.sAge << " ID:" << tch.sID << " title:" << tch.sTitle << " wage:" << tch.sSalary << endl;
    cout << "name:" << stu.sName << " gender:" << stu.sGender << " age:" << stu.sAge << " ID:" << stu.sID << " class:" << stu.sClass << " major:" << stu.sMajor<< " grade:"<< stu.sGrade << endl;
 
endapp:
    //system("pause > nul");
    return 0;
}