/*
@ Author: Alessandro Frau
scrivere una funzione che prende una lista di interi e stampa la
sequenza di interi memorizzata nella lista 
*/
#include<iostream>
using namespace std;

struct list{
    int value;
    list *next;
};

list* insert(list *head, int v){
    list *n;
    n = new list;
    n->value = v;
    n->next = head;
    return n;
}

void scrivi(list *head){
    list *p;
    p = head;
    while(p != NULL){
        cout<<p->value;
        p = p->next;
    }
}

int main(){
    list *head;
    head = NULL;
    head = insert(head,1);
    head = insert(head,2);
    scrivi(head);
    return 0;
}