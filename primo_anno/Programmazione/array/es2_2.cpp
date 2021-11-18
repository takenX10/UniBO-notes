/*
@ Author: Alessandro Frau
2.Scrivere un programma che implementa una pila utilizzando un array (definire le
funzioni is_empty, push e pop; la funzione push ritorna overflow se l’array è pieno) 
*/
#include<iostream>
using namespace std;
#define stack_size 10

bool is_empty2(int v[],int l){
    if (l > 0) return false;
    return true;
}

void push(int v[], int &l, int n){
    if(l+1> stack_size)
        cout<<"overflow"<<endl;
    else{
        v[l] = n;
        l++;
    }
}

void pop(int v[], int &l){
    cout<<v[l-1]<<endl;
    l--;
}

int main(){
    int stack[stack_size];
    int length = 0;
    cout<<is_empty2(stack,length)<<endl;
    push(stack, length, 1);
    push(stack, length, 2);
    push(stack, length, 3);
    pop(stack, length);
    pop(stack, length);
    pop(stack, length);
    cout<<is_empty2(stack, length)<<endl;
    return 0;
}