/*
@ Author: Alessandro Frau
2. scrivere un programma che prende n e stampa la seguente struttura di
altezza n:
scrivere due versioni del programma: una che usa cicli for, l’altra che
usa cicli while (c.f. triangolo di Tartaglia) 
*/

//    Cn,k = n!/(k!*(n-k)!) per ogni posizione k del triangolo nella riga n

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n,i,j;
    cin>>n;
    for(i=0;i<=n;i++){
        for(j=0;j<n-i;j++) cout<<"\t";
        for(j=0;j<=i;j++){
            cout<< tgamma(i+1) / (tgamma(j+1) * tgamma(i-j+1)) <<"\t\t";
        }
        cout<<endl;
    }
    return 0;
}