/*
@ Author: Alessandro Frau

*/
#include<iostream>
using namespace std;

int main(){
    int n,i;
    bool primo;
    primo = true;
    cin>>n;
    for(i=2;i<=n/2;i++){
        if(n%i == 0){
            primo = false;
        }
    }
    if(primo){
        cout<<"primo"<<endl;
    }else{
        cout<<"non_primo"<<endl;
    }
    return 0;
}