#include<iostream>
using namespace std;

struct insieme_di_naturali{
	int n;
	struct insieme_di_naturali *next;	
};

struct insieme_di_naturali* unione(struct insieme_di_naturali *a, struct insieme_di_naturali *b){
	struct insieme_di_naturali *aux = a;
	if(a == NULL){
		return b;
	}
	while(aux->next != NULL){
		aux = aux->next;
	}
	aux->next = b;
	return a;
}

int contenuto(int n, struct insieme_di_naturali *head){
	int inside = 0;
	struct insieme_di_naturali *aux = head;
	while(!inside && aux != NULL){
		if(n == aux->n){
			inside ++;
		}
	}
	return inside;
}

struct insieme_di_naturali* intersezione(struct insieme_di_naturali *a, struct insieme_di_naturali *b){
	struct insieme_di_naturali *aux = a;
	struct insieme_di_naturali *nuova_lista;
	while(aux != NULL){
		if(contenuto(aux->n, b)){
			nuova_lista = head_insert(nuova_lista, aux->n);
		}
	}
	//qua si potrebbe liberare la memoria occupata dalle due liste a e b, dipende dalle specifiche
	return nuova_lista;
}