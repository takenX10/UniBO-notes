/*
@ Author: Alessandro Frau
4.Definire una funzione void parola(char str[],int n,char dest[]) che
prende come parametri un array str e un intero n e restituisce nel parametro dest la
parola corrispondente all’ennesima parola dentro str. Si assuma che una parola sia
una qualunque sequenza di caratteri diversi da spazio e che le parole siano separate
tra loro da uno o più spazi. In caso di errore la funzione restituisce la parola vuota.
(esame del 17/2/2012)
*/
#include<iostream>
using namespace std;

void parola(char str[],int array_size, int n,char dest[]){
    int count = 1;
    int i = 0, j=0;
    while(count<n && i+1 < array_size){
        if(str[i]==' ') count++;
        i++;
    }
    do{
        dest[j] = str[i];
        i++;
        j++;
    }while(str[i] != ' ' && i<array_size);
}

int main(){
    

    return 0;
}