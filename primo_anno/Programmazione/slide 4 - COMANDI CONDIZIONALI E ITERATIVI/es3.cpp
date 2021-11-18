/*
@ Author: Alessandro Frau
3. scrivere un programma che prende n e ritorna la parte intera della
radice quadrata di n
*/
#include<iostream>
using namespace std;

int main(){
    int a,i;
    i=1;
    cin>>a;
    while(i*i<=a){
        i++;
    }
    cout<<i-1;

    return 0;
}