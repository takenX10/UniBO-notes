/*
@ Author: Alessandro Frau
4. scrivere una funzione che inverte i nodi di una lista e ritorna il
puntatore alla testa della nuova lista.
*/
#include<iostream>
using namespace std;

struct list{
    int value;
    list *next;
};

list* tail_insert(list *head, int v){
    list *p,*p2;
    p2 = new list;
    p2->value = v;
    p2->next = NULL;
    p = head;
    if(p == NULL){
        head = p2;
    }else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = p2;
    }
    return head;
    
}

list* insert_head(list *head, int v){
    list *p;
    p = new list;
    p->value = v;
    p->next = head;
    return p;
}


list* inverti(list *head){
    list *new_head,*p;
    new_head = NULL;
    p = head;
    if (head == NULL){
        new_head = NULL;
    }else{
        while(p!=NULL){
            new_head = insert_head(new_head,p->value);
            p = p->next;
        }
    }
    
    return new_head;
}

void scrivi(list *head){
    list *p;
    p = head;
    while(p!=NULL){
        cout<<p->value<<endl;
        p = p->next;
    }
}

int main(){
    list *head,*head2;
    head = NULL;
    head = tail_insert(head,0);
    head = tail_insert(head,2);
    scrivi(head);
    head2 = inverti(head);
    scrivi(head2);
    return 0;
}