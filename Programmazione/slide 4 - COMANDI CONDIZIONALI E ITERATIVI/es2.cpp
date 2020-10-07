/*
@ Author: Alessandro Frau

2. scrivere un programma che prende un intero n, e calcola il fattoriale di
n (!0 =1 ; !n = 1*2*…*n)
*/
#include<iostream>
using namespace std;

int main(){
    int n,tot;
    tot = 1;
    cin>>n;
    if(!n){
        cout<<"1"<<endl;
    }else{
        for(int i=1;i<=n;i++){
            tot = tot * i;
        }
    }
    cout<<tot<<endl;

    return 0;
}