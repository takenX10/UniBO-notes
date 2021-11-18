/*
@ Author: Alessandro Frau

*/
#include<iostream>
#include<time.h>
using namespace std;

int main(){
    srand(time(NULL));
    int a,r;
    r = rand() % 100 + 1;
    do{
        cin>>a;
        if(a>r)cout<<"troppo grande"<<endl;
        if(a<r)cout<<"troppo piccolo"<<endl;

    }while(a!=r);
    cout<<"giusto";
    return 0;
}