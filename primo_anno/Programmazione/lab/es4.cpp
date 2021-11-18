/*
@ Author: Alessandro Frau

*/
#include<iostream>
using namespace std;

int main(){
    int a,i=10,tot=0;
    cin>>a;
    while(0<a){
        tot += a%10;
        a= a/10; 
    }
    cout<<tot;
    return 0;
}