/*
@ Author: Alessandro Frau

1. scrivere un programma che prende un intero n, e calcola la somma dei
numeri minori di n, 
*/
#include<iostream>
using namespace std;

int main(){
    int i,n,tot;
    tot=0;
    cin>>n;
    for (i=0; i<n; i++){
        tot = tot+i;
    }
    cout<<tot;
    return 0;
}
