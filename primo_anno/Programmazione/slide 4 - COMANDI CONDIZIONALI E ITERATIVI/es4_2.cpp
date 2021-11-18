/*
@ Author: Alessandro Frau
scrivere un programma che prende un intero e stampa la
somma delle sue cifre
*/
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int a,s,i;
    s=0;
    i=1;
    cin>>a;
    a = abs(a);
    while(a>0){
        s = s + a%10;
        a = a/10;
    }
    cout<<s<<endl;
    return 0;
}