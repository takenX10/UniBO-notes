/*
@ Author: Alessandro Frau

*/
#include<iostream>
#include<time.h>
#include "library.h"
using namespace std;


void inserisci(int v[], int n){
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
}

void casuale(int v[],int n, int mas){
    srand(time(NULL));
    for(int i=0; i<n; i++){
        v[i] = rand() % mas;
    }
}

void stampa(int v[], int n){
    for(int i = 0; i < n; i++){
        cout<<v[i];
    }
}
void stampa_inverso(int v[], int n){
    for(int i = 0; i < n; i++){
        cout<<v[n-i-1];
    }
}

void inizializza(int v[], int n){
    for(int i = 0; i<n ; i++){
        v[i] = 0;
    }
}