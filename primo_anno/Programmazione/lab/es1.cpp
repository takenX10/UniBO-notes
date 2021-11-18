/*
@ Author: Alessandro Frau

*/
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    cout<<(float)a/b<<endl;
    cout<<setprecision(2)<<(float)a/b<<"\n";
    cout<<setprecision(3)<<(float)a/b<<"\n";
    cout<<setprecision(4)<<(float)a/b<<"\n";
    return 0;
}