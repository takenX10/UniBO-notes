/*
@ Author: Alessandro Frau

*/
#include<iostream>
using namespace std;

int fibonacci(int tot, int i = 1, int n=1, int nm1=0){
    if(tot==0){
        return 0;  
    }
    if(tot==i)
        return n;
    return fibonacci(tot, i+1, n+nm1,n);
}


int main(){
    int n;
    cout<<"inserisci numero: ";
    cin>>n;
    for(int i=0;i < n; i++){
        cout<<fibonacci(i)<<" ";
    }
    return 0;
}