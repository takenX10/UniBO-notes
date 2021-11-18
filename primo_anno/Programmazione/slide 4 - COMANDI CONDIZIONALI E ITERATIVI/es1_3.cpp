/*
@ Author: Alessandro Frau
1. il valore ex può essere approssimato dalla somma
1 + x + x2/2! + x3/3! + . . . + xn/n!
scrivere un programma che prende x, prende n e stampa
l’approssimazione fino ad n di ex. Il programma stampa anche il valore
exp(x) dove exp è la funzione definita nella libreria cmath.
[SUGGERIMENTO: dichiarare n double per evitare overflow] 
*/
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double n,s;
    int i,x;
    cin>>x>>n;
    s = 1 + x;
    for(i=2;i<=n;i++){
        s = s + pow(x,i)/tgamma(i+1); // tgamma(i+1) = i!
    }

    cout<<"s: "<<s<<"\ne^x: "<<exp(x);
    return 0;
}