/*
@ Author: Alessandro Frau
3.Scrivere un programma che implementa due pile utilizzando un solo array. In
particolare, dato un array di lunghezza L (L è una costante del programma) definire le
funzioni push1, pop1, is_empty1 e le funzioni push2, pop2, is_empty2 che
implementano sull’array le note funzioni sulle pile. Le funzioni push1 e push2
restituiscono un errore (overflow) solamente se l’array è pieno. (esame del 15/6/2012) 
*/
#include<iostream>
using namespace std;
#define L 10        // deve essere un intero pari, definisce la dimensione dell'array che contiene i due stack

bool is_empty1(int v[],int l){
    if (l > 0) return false;
    return true;
}

void push1(int v[], int &l, int n){
    if(l+1 > L/2 )
        cout<<"overflow"<<endl;
    else{
        v[l] = n;
        l++;
    }
}

void pop1(int v[], int &l){
    cout<<v[l-1]<<endl;
    l--;
}

bool is_empty2(int v[],int l){
    if (l > 0) return false;
    return true;
}

void push2(int v[], int &l, int n){
    if(l+1 > L/2)
        cout<<"overflow"<<endl;
    else{
        v[l+L/2] = n;
        l++;
    }
}

void pop2(int v[], int &l){
    cout<<v[L/2+l-1]<<endl;
    l--;
}

int main(){
    int stack[L];
    int length1 = 0, length2 = 0;
    cout<<is_empty1(stack,length1)<<endl;
    push1(stack, length1, 1);
    push1(stack, length1, 2);
    push1(stack, length1, 3);
    push1(stack, length1, 4);
    push1(stack, length1, 5);
    push1(stack, length1, 6);
    pop1(stack, length1);
    pop1(stack, length1);
    pop1(stack, length1);
    push2(stack, length2, 6);
    push2(stack, length2, 7);
    push2(stack, length2, 8);
    push2(stack, length2, 9);
    push2(stack, length2, 10);
    push2(stack, length2, 11);
    pop2(stack, length2);
    pop2(stack, length2);
    pop2(stack, length2);
    cout<<is_empty1(stack, length1)<<endl;
    return 0;
}