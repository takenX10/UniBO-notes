/*
@ Author: Alessandro Frau

*/
#include<iostream>
using namespace std;

int recursive(int n){
    if(n==0){
        return 1;
    }else if(n<0){
        return 0;
    }
    return (recursive(n-1) * 2) + 1;
}

int iterative(int n){
    int tot=1;
    int i;
    if(n <0){
        return 0;  
    } 
    for(i=0;i<n;i++){
        tot = tot * 2 + 1;
    }
    return tot;
}

int main(){
    cout<<recursive(10)<<endl<<iterative(10);

    return 0;
}