#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include "custom_library.h"


// printa la lista in output
void printlist(struct filestrings *head){
    struct filestrings *aux = head;
    while(aux != NULL){
        printf("%s\n",aux->line);
        aux = aux->next;
    }
}


// inserisce un elemento in testa alla lista
struct symbols* head_insert(struct symbols *head, char s[], int v){
    struct symbols *newhead = malloc(sizeof(struct symbols));
    newhead->next = head;
    newhead->value = v;
    strcpy(newhead->simbolo, s);
    return newhead;
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

// funzione che passata un etichetta e una stringa, mette il valore dell'etichetta all'interno delle
// parentesi nella stringa.
// es: s = (LABEL), alla fine della funzione final_string = LABEL 
void taglia_etichetta(char s[],char final_string[]){
    int i = 1;
    while(s[i]!=')'){
        final_string[i-1] = s[i];
        i++;
    }
    final_string[i-1] = '\0';
}


// rimuove un elemento da una lista, prende l'elemento da rimuovere, l'elemento precedente e la testa della lista
struct filestrings* remove_element(struct filestrings *current, struct filestrings *previous, struct filestrings *head){
    if(previous == NULL){
        struct filestrings *aux;
        aux = current->next;
        free(current);
        head = aux;
    } else{
        previous->next = current->next;
        free(current);
    }
    return head;
}

// controlla se il simbolo e' contenuto nella tabella
int contains(struct symbols *sym, char e[]){
    struct symbols *current = sym;
    int found = 0;
    while(current != NULL && !found){
        if(!strcmp(current->simbolo,e)){
            found = 1;
        }
        current = current->next;
    }
    return found;
}


// restituisce il valore del simbolo nella tabella, si presuppone che il simbolo sia presente (fare controllo con la funzione contains)
int valore(struct symbols *sym, char e[]){
    struct symbols *current = sym;
    while(strcmp(current->simbolo,e)){
        current = current->next;
    }
    return current->value;
}

// prende un intero e restituisce il valore in binario, padding per 16 bit
void int_to_bin(int n, char string[]){
    int i = 15;
    while(n != 0){
        if(n%2 ==0){
            string[i] = '0';
        }else{
            string[i] = '1';
        }
        n = n/2;
        i--;
    }
    for(;i>=0;i--){
        string[i] = '0';
    }
    string[16] = '\0';
}

// divide la prima stringa (l) in due stringhe (f e s) che gli vengono passate come parametri, nel primo carattere (c) che trova
// nella stringa l
// il carattere stesso viene rimosso
// se non trova il carattere l'intera stringa viene duplicata in f e s rimane vuota
void split(char l[], char f[], char s[], char c){
    int i = 0;
    int curr = 0;
    while(l[i] != c && l[i] != '\0'){
        f[curr] = l[i];
        curr ++;
        i++;
    }
    if(l[i] != c){
        s[0] = '\0';
    }else{
        f[curr] = '\0';
        curr = 0;
        i++;
        while(l[i] != '\0'){
            s[curr] = l[i];
            curr ++;
            i++;
        }
        s[curr] = '\0';
    }
}

// Verifica che un carattere (t) sia all'interno di una stringa (l)
// 1 = e' presente
// 0 = non e' presente
int is_inside(char l[], char t){
    int i = -1;
    int inside = 0;
    do{
        i++;
        if(l[i] == t){
            inside = 1;
        }
    }while(l[i] != t && l[i] != '\0');
    return inside;
}
