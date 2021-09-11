#include <iostream>
#include <iomanip>
using namespace std;
 
int main(){
    int iMonthSal;
    cin>>iMonthSal;
    double iTotal=iMonthSal*12.0-60000.0;
    double iTax;
    if (iTotal<=0){
        cout<<0;
        return 0;
    }
    if (iTotal<=36000){
        iTax=iTotal*0.03;
    }
    else if (iTotal > 36000 && iTotal <=144000){
        iTax=36000.0*0.03+(iTotal-36000.0)*0.1;
    }
    else if (iTotal > 144000 && iTotal <=300000){
        iTax=36000.0*0.03+(144000.0-36000.0)*0.1+(iTotal-144000.0)*0.2;
    }
    else if (iTotal > 300000 && iTotal <=420000){
        iTax=36000.0*0.03+(144000.0-36000.0)*0.1+(300000.0-144000.0)*0.2+(iTotal-300000.0)*0.25;
    }
    else if (iTotal > 420000 && iTotal <=660000){
        iTax=36000.0*0.03+(144000.0-36000.0)*0.1+(300000.0-144000.0)*0.2+(420000.0-300000.0)*0.25+(iTotal-420000.0)*0.3;
    }
    else if (iTotal > 660000 && iTotal <=960000){
        iTax=36000.0*0.03+(144000.0-36000.0)*0.1+(300000.0-144000.0)*0.2+(420000.0-300000.0)*0.25+(660000.0-420000.0)*0.3+(iTotal-660000.0)*0.35;
    }
    else{
        iTax=36000.0*0.03+(144000.0-36000.0)*0.1+(300000.0-144000.0)*0.2+(420000.0-300000.0)*0.25+(660000.0-420000.0)*0.3+(960000.0-660000.0)*0.35+(iTotal-960000.0)*0.45;
    }
    cout<<iTax;
    return 0;
}