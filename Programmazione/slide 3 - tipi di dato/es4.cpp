/*
4. scrivere un programma che prende in input 3 numeri interi e produce
in output una tabella con la differenza dei numeri a due a due.
*/
#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<"  | "<<a<<" | "<<b<<" | "<<c<<endl;
    cout<<a<<" | "<<a-a<<" | "<<a-b<<" | "<<a-c<<endl;
    cout<<b<<" | "<<b-a<<" | "<<b-b<<" | "<<b-c<<endl;
    cout<<c<<" | "<<c-a<<" | "<<c-b<<" | "<<c-c<<endl;
    return 0;
}