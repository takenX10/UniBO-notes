#include<cstring>
#include<iostream>
using namespace std;

struct smartphone{
	string modello;
	string produttore;
	int prezzo;
	struct smartphone *next;
};

int nprod(struct smartphone *head, int price){
	struct smartphone *aux = head;
	int tot = 0;
	string currentProd = "";
	bool avanti;
	while(aux != NULL){
		if(aux->prezzo < price){
			tot++;
			currentProd = aux->produttore;
			avanti = true;
			while(aux != NULL && avanti){
				if(currentProd != aux->produttore){
					avanti = false;
				}else{
					aux = aux->next;
				}
			}
		}else{
			aux = aux->next;
		}
		
	}
	return tot;
}


struct smartphone* aggiungi_telefono(struct smartphone *head, int price, string productor, string model){
	struct smartphone *aux = head;
	struct smartphone *prev = NULL;
	struct smartphone *nuovo_telefono = new struct smartphone;
	nuovo_telefono->prezzo = price;
	nuovo_telefono->produttore = productor;
	nuovo_telefono->modello = model;
	nuovo_telefono->next = NULL;
	while(nuovo_telefono->produttore > aux->produttore && aux->next != NULL){
		prev = aux;
		aux = aux->next;
	}
	if(nuovo_telefono->produttore > aux->produttore){
		aux->next = nuovo_telefono;
	}else if(nuovo_telefono->produttore == aux->produttore){
		while(aux->prezzo > nuovo_telefono->prezzo && aux->next != NULL){
			aux = aux->next;
		}
		if(aux->prezzo > nuovo_telefono->prezzo){
			aux->next = nuovo_telefono;
		}else{
			if(prev == NULL){
				head = nuovo_telefono;
			}else{
				prev->next = nuovo_telefono;
			}
			nuovo_telefono->next = aux;
		}
	}else{
		if(prev == NULL){
			head = nuovo_telefono;
		}else{
			prev->next = nuovo_telefono;
		}
		nuovo_telefono->next = aux;
	}
	return head;
}