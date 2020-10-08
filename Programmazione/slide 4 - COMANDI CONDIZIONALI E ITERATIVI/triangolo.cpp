/*
@ Author: Alessandro Frau
crea un triangolo rettangolo di dimensione presa in input
*/
#include<iostream>
using namespace std;

int main(){
    int n,i,j;
    cin>>n;
    i=0;
    do{
        for(j=0;j<n-i;j++){
            cout<<" ";
        }
        for(j=0;j<=i*2;j++){
            cout<<"*";
        }
        cout<<endl;
        i++;
    }while(i<n);
    return 0;
}