/*
1. scrivere un programma che prende in input un prezzo in
euro (inclusi centesimi) e stampa quante e quali monete
sono necessarie per pagarlo (con un numero minimo di
monete)
esempio: input: 15.74
 output: monete da 2 euro: 7
 monete da 1 euro: 1
 monete da 50 cent: 1
 monete da 20 cent: 1
 monete da 2 cent: 2 

*/

#include <iostream> 
using namespace std;

int main(){
    double a;
    int tot,resto;
    cin>>a;
    tot = a*100;
    cout<<tot;
    cout<<"monete da 2 euro: "<<tot/200<<endl;
    tot = tot%200;
    cout<<tot;
    cout<<"monete da 1 euro: "<<tot/100<<endl;
    tot = tot%100;
    cout<<tot;
    cout<<"monete da 50 cent: "<<tot/50<<endl;
    tot = tot%50;
    cout<<"monete da 20 cent: "<<tot/20<<endl;
    tot = tot%20;
    cout<<"monete da 10 cent: "<<tot/10<<endl;
    tot = tot%10;
    cout<<"monete da 5 cent: "<<tot/5<<endl;
    tot = tot%5;
    cout<<"monete da 2 cent: "<<tot/2<<endl;
    tot = tot%2;
    return 0;
}