#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
struct Student{
    int iID;
    int iCpp;
    int iMath;
    int iPhys;
    int iTotal;
};
 
bool cmp(Student stuStudent1, Student stuStudent2){
    if (stuStudent1.iTotal != stuStudent2.iTotal){
        return stuStudent1.iTotal > stuStudent2.iTotal;
    }
    else if (stuStudent1.iCpp != stuStudent2.iCpp){
        return stuStudent1.iCpp > stuStudent2.iCpp;
    }
    else{
        return stuStudent1.iID < stuStudent2.iID;
    }
}
 
int main(){
    int nCount;
    vector<Student> arrStudents;
    cin>>nCount;
    Student stuTemp;
    for (int i=1; i<=nCount; ++i){
        stuTemp.iID=i;
        cin>>stuTemp.iCpp>>stuTemp.iMath>>stuTemp.iPhys;
        stuTemp.iTotal=stuTemp.iCpp+stuTemp.iMath+stuTemp.iPhys;
        arrStudents.push_back(stuTemp);
    }
    sort(arrStudents.begin(),arrStudents.end(),cmp);
    for (int i=0; i<=4;++i){
        cout<<arrStudents[i].iID<<' '<<arrStudents[i].iTotal;
        cout<<endl;
    }
    return 0;
}