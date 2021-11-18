/*
@ Author: Alessandro Frau

*/
#include<iostream>
using namespace std;

int main(){
    int a;
    cin>>a;
    cout<<"ore: "<<a/3600<<endl;
    a = a % 3600;
    cout<<"minuti: "<<a/60<<endl;
    a= a % 60;
    cout<<"secondi: "<<a<<endl;

    return 0;
}