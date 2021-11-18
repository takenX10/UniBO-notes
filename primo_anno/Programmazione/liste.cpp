/*
@ Author: Alessandro Frau
// ESERCIZIO: IMPLEMENTARE UNA CODA CON LE OPERAZIONI: new_queue, empty_queue, enqueue, dequeue
// [OTTIMIZZATE L'USO DELLA MEMORIA ED EVITATE DI COPIARE ELEMENTI]
// [1,2,3,4,5, .... ]  ===> [ , ,3,  4, 5, 6, 7]
//  ^head   ^tail                ^head        ^tail
// mancano le descrizioni delle funzioni, suppongo che:

new_queue: funzione che inizializza una lista
empty_queue: funzione che azzera la lista
enqueue: funzione che aggiunge un elemento in testa / coda
dequeue: funzione che rimuove l'elemento in testa / coda
*/
#include<iostream>
using namespace std;

// sarebbe molto meglio procedere con allocazioni dinamiche di memoria, ma assumiamo di non potere e procediamo cosi:
#define size 10

// la soluzione e' abbastanza efficiente, new_queue, enqueue, e empty_queue hanno complessita O(n) e dequeue ha complessita O(1)
// e non occupa memoria extra 

struct coda{
    int next,previous,value;
    bool empty;
}; 

//trova il primo elemento vuoto nell'array
int find_empty(const coda t[]){             
    int i = 0;
    bool controllo = true;
    while(controllo)                    // utilizzo un bool perche' se mettessi direttamente t[i] nella condizione del 
        if(i<size)                      // while avrei un out of bound
            if(!t[i].empty)
                i++;
            else
                controllo = false;
        else{
            i = -1;
            controllo = false;
        }
    return i;
}

void new_queue(coda t[], int &head, int &tail){
    t[0].next = -1;
    t[0].previous = -2;                     // assumiamo che -1 sia testa e -2 sia coda
    head = tail = 0;                        // preciso che ci possono essere alcuni casi in cui testa e coda NON sono -1/-2
    int i;                                  // sarebbe necessario fixare se si volesse cercare head e tail direttamente nella lista
    for(i = 0; i < size; i++)               // ma per come ho strutturato il codice non cambia niente quindi non aggiungo controlli per fixare :)
        t[i].empty = true;                  // piu controlli => meno efficiente (negativo) && piu leggibile (positivo per il lettore del codice)
}

void empty_queue(coda t[], int &head, int &tail){   // non capisco il senso di aggiungere questa funzione, non fa nulla di diverso da new_queue
    new_queue(t,head,tail);                         // magari ha piu' senso con allocazione dinamica ma in questo caso mi sembra identica
}

void enqueue (coda t[], int &head, int &tail, int value, char pos){
    int emp;
    emp = find_empty(t);
    if(emp!= -1){
        if(pos == 'h'){
            t[emp] = {-1,head,value,false};
            if (emp!=head){
                t[head].next = emp;
                head = emp;
            }
        }else{
            t[emp] = {tail, -2, value, false};
            if(emp!=tail){
                t[tail].previous = emp;
                tail = emp;
            }
            
        }
    }
}

void dequeue(coda t[], int &head, int &tail, char pos){
    if(pos == 'h'){
        t[head].empty = true;
        t[t[head].previous].next = -1;
        head = t[head].previous;
    }else{
        t[tail].empty = true;
        t[t[tail].next].previous = -2;
        tail = t[tail].next;
    }
}

int main(){
    coda t[size];
    int head,tail;
    new_queue(t,head,tail);
    enqueue(t,head,tail,3,'h');
    enqueue(t,head,tail,4,'h');
    enqueue(t,head,tail,5,'h');
    dequeue(t,head,tail,'h');
    cout<<head;
    return 0;
}