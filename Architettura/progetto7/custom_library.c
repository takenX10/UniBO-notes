#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include "custom_library.h"

// esegue una inserimento in testa della stringa name nella lista passata
struct label* head_insert(struct label *head, char name[]){
    struct label *aux = (struct label *) malloc(sizeof(struct label));
    strcpy(aux->name, name);
    aux->next = head;
    return aux; 
}

// controlla se la stringa a e' contenuta nella stringa b
int is_contained(char a[], char b[]){
    int contenuto = 0;
    int lenA = strlen(a);
    int lenB = strlen(b);
    int j = 0;
    while(j + lenA <= lenB && !contenuto){
        int i = -1;
        contenuto = 1;
        do{
            i++;
            if(a[i] != b[j+i]){
                contenuto = 0;
            }
        }while(i < lenA - 1 && contenuto);
        j++;
    }
    return contenuto;
}

//controlla se la stringa b inizia con la stringa a
int start_with(char a[], char b[]){
    int start = 1;
    int i = -1;
    do{
        i++;
        if(a[i] != b[i]){
            start = 0;
        }
        
    }while(start && a[i+1] != '\0');
    return start;
}

// divide string nel primo carattere divisore, e mette la prima parte in a e la seconda in b
// presuppone che il carattere ci sia
void split(char string[], char *a, char *b, char divisore){
    int i = -1;
    int j = -1;
    do{
        i++;
        a[i] = string[i];
    }while(string[i] != divisore);
    a[i] = '\0';
    do{
        i++;
        j++;
        b[j] = string[i];
    }while(string[i] != '\0');
}

//prende una stringa di numeri e restituisce un intero
int ascii_to_int(char s[]){
    int len = strlen(s);
    int tot = 0;
    for(int i = 0;i < len;i++){
        tot += (int)pow(10,i)*(s[len-i-1]-48);
    }
    return tot;
}

// inverte una stringa
void reverse_string(char s[]){
    int i;
    int length = strlen(s);
    char aux[128];
    for( i = 0;i < length;i++){
        aux[i] = s[length-i-1];
    }
    aux[i] = '\0';
    strcpy(s,aux);
}

// trasforma un intero in una stringa
void int_to_ascii(int n, char s[]){
    int i = 0;
    while(n!=0){
        s[i] = '0' + n%10;
        n = n/10;
        i++;
    }
    s[i] = '\0';
    reverse_string(s);
}

// controlla se esiste la stringa string all'interno della lista head
int exist(struct label *head, char string[]){
    struct label *aux = head;
    int esiste = 0;
    while(aux != NULL && !esiste){
        if(strcmp(aux->name, string)==0){
            esiste++;
        }
        aux = aux->next;
    }
    return esiste;
}

// crea una label non usata
void newlabel(char string[], struct label *head, int *counter){
    int esiste;
    char numero[30];
    do{
        int_to_ascii(*counter, numero);
        strcpy(string, "LABEL");
        strcat(string, numero);
        esiste = exist(head, string);
        *counter = *counter + 1;
    }while(esiste);
}
