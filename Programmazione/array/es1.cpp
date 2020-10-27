/*
@ Author: Alessandro Frau

*/
#include<iostream>
#include<cmath>
using namespace std;
#define size 10

int main(){
    int v[size];
    int a,len,dec=0;
    cout<<"inserisci lunghezza numero"<<endl;
    cin>>len;
    for(a=0;a<len;a++){
        cin>>v[a];
    }
    for(a=0;a<len;a++){
        if(v[a]){
            dec+=pow(2,a);
        }
    }
    cout<<dec;
    return 0;
}