/*
@ Author: Alessandro Frau

*/
#include<iostream>
using namespace std;


struct listaCaratteri{
	char c;
	struct listaCaratteri *next;	
};

int equal_start(char str[], struct listaCaratteri *head){
	int i = 0;
	int equal = 1;
	struct listaCaratteri *aux = head;
	while(str[i] != '\0' && aux != NULL && equal){
		if(str[i] != aux->c){
			equal = 0;
		}
		i++;
		aux = aux->next;
	}
	if(!equal){
		return 0;
	}else{
		if(str[i] == '\0'){
			return 1;
		}else{
			return 0;
		}
	}
}

// passare la stringa "amar" in str
int occurrences(char str[], struct listaCaratteri *head){
	int tot = 0;
	struct listaCaratteri *aux = head;
	while(aux != NULL){
		tot += equal_start(str, aux);
		aux = aux->next;
	}
	return tot;
}

int main(){
    

    return 0;
}