/*
@ Author: Alessandro Frau

*/
#include<iostream>
using namespace std;

void non_multiplo(unsigned int n){
    int i;
    for(i = 0; i<n; i++){
        if(i%4 != 0 && i%2==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

void non_multiplo_iterativo(unsigned int n, int i = 0){
    if(i%4 != 0 && i%2==0){
        cout<<i<<" ";
    }
    if(i<n){
        non_multiplo_iterativo(n,i+1);
    }
}

struct lista_di_studenti{
    char nome[20], cognome[30];
    unsigned int numero_matricola;
    struct lista_di_studenti *next;
};

struct lista_di_studenti* remove_element(struct lista_di_studenti *head, int i){
    struct lista_di_studenti* aux = head;
    if(i == 0){
        head = head->next;
        delete(aux);
    }else{
        int j = 0;
        struct lista_di_studenti *aux2;
        while(j!=i-1){
            aux = aux->next;
            j++;
        }
        aux2 = aux->next;
        aux->next = aux2->next;
        delete(aux2);
    }
    return head;
}

struct lista_di_studenti* nuovaLista(struct lista_di_studenti* head){
    struct lista_di_studenti *aux = head;
    int i = 0;
    while(aux!= NULL){
        if(aux->numero_matricola%2!= 0 || aux->numero_matricola%4 == 0){
            aux = aux->next;
            head = remove_element(head,i);
        }else{
            aux = aux->next;
        }
        i++;  
    }
    return head;
}

#include<cmath>

class segmento{
    protected:
        double x,y,x2,y2;
    public:
        segmento(double x, double y, double x2, double y2){
            this->x = x;
            this->y = y;
            this->x2 = x2;
            this->y2 = y2;
        }
        double lunghezza(){
            return sqrt(pow(x-x2,2) + pow(y - y2,2));
        }
};

class segmenti_adiacenti: public segmento{
    protected:
        double x3,y3;
    public:
        segmenti_adiacenti(double x, double y, double x2, double y2, double x3, double y3):segmento(x,y,x2,y2){
            this->x3 = x3;
            this->y3 = y3;
        }
        double lunghezza(){
            return (segmento::lunghezza() + sqrt(pow(x2-x3,2) + pow(y2-y3,2)));
        }
        double lunghezza_primo(){
            return (segmento::lunghezza());
        }
        double lunghezza_secondo(){
            return  sqrt(pow(x2-x3,2) + pow(y2-y3,2)); 
        }

};

int main(){
    segmento a(1,1,3,1);
    segmenti_adiacenti b(1,1,1,3,3,3);
    cout<<b.lunghezza()<<endl;
    non_multiplo(8);
    non_multiplo_iterativo(8);
    return 0;
}