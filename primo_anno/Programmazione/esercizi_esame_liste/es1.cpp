/*
@ Author: Alessandro Frau

*/
#include<iostream>
#include<cstring>
using namespace std;

struct book{
    float price;
    int nc;
    string title;
    struct book *next;
};

int med(struct book *head){
    struct book *p=head;
    float med = 0;
    int acc=0;
    
    if(p==NULL) return 0;   // error handling

    while(p != NULL){
        acc++;
        med += p->price;
        p = p->next;
    }
    return (med/acc);
}

//assumiamo che il libro sia sempre presente nella lista
struct book* remove_element(struct book *head, string t){
    struct book *p = head;
    struct book *aux;
    if(p->title == t){
        head = p->next;
        delete(p);
    }else{
        while((p->next)->title != t){
            p = p->next;
        }
        aux = p->next;
        p->next = (p->next)->next;
        delete(aux);
    }
    return head;
}

//assumiamo che il libro sia sempre presente nella lista
struct book* compra_libro(struct book *head, string t){
    struct book *p=head;
    while(p->title != t){
        p = p->next;
    }
    p->nc--;
    if(!p->nc){
        head = remove_element(head, t);
    }
    return head;
}

string pmag(struct book *head){
    struct book *p = head;
    string mg = "";
    float pm=0;
    while(p != NULL){
        if(p->price > pm){
            pm = p->price;
            mg = p->title;
        }
        p = p->next;
    }
    return mg;
}

int main(){
    

    return 0;
}