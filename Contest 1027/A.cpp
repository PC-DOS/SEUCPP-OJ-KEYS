#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main(){
    double a,b,c,delta,x1,x2;
    cin>>a>>b>>c;
    delta=b*b-4*a*c;
    if (delta>0){
        x1=(-b+sqrt(delta))/(2*a);
        x2=(-b-sqrt(delta))/(2*a);
        cout<<"x1="<<fixed<<setprecision(5)<<x1<<";x2="<<x2<<endl;
    }
    else if (delta==0){
        x1=(-b+sqrt(delta))/(2*a);
        x2=(-b-sqrt(delta))/(2*a);
        cout<<"x1=x2="<<fixed<<setprecision(5)<<x2<<endl;
    }
    else{
        if (b!=0){
            cout<<fixed<<setprecision(5)
                <<"x1="<<(-b)/(2*a)<<"+"<<sqrt(-delta)/(2*a)<<"i;x2="
                <<(-b)/(2*a)<<"-"<<sqrt(-delta)/(2*a)<<"i"<<endl;
        }
        else{
            cout<<fixed<<setprecision(5)
                <<"x1="<<(b)/(2*a)<<"+"<<sqrt(-delta)/(2*a)<<"i;x2="
                <<(b)/(2*a)<<"-"<<sqrt(-delta)/(2*a)<<"i"<<endl;
        }
    }
    return 0;
}