/*
2. scrivere un programma che prende in input la lunghezza
di due cateti di un triangolo rettangolo e stampa la
lunghezza dell'ipotenusa
*/

#include <iostream>
#include<cmath>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    cout<<sqrt((a*a)+(b*b))<<endl;
    return 0;
}