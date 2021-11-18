#include<iostream>
#include<cstring>
using namespace std;
#define dimensione_array 20

struct impianto_sciistico{
	char nome[dimensione_array];
	int costo;	
};

void copia_array(struct impianto_sciistico a[], struct impianto_sciistico b[], int n){
	for(int i = 0; i < n; i++){
		strcpy(a[i].nome, b[i].nome);
		a[i].costo = b[i].costo;
	}
}

class skipass{
	protected:
		char tipo;
		int numero_ingressi;
		int data;
		struct impianto_sciistico comprensorio_sciistico[dimensione_array];
	public:
		skipass(char t, struct impianto_sciistico insieme_impianti[dimensione_array], int numero_ingressi = 0, int data = 0){
			this->tipo = t;
			copia_array(this->comprensorio_sciistico, insieme_impianti, dimensione_array);
			this->data = data;
			this->numero_ingressi = numero_ingressi;
		}

		void accesso(char nome_impianto[dimensione_array], int data){
			if(this->tipo == 'g'){
				if(this->data == data){
					cout<<"accesso consentito"<<endl;
				}else{
					cout<<"accesso negato";
				}
			}else if(this->tipo == 'r'){
				int i=0;
				bool trovato = false;
				while(i<dimensione_array && !trovato){
					if(!strcmp(comprensorio_sciistico[i].nome, nome_impianto)){
						trovato = true;
					}
					i++;
				}
				if(trovato){
					if(comprensorio_sciistico[i-1].costo > this->numero_ingressi){
						cout<<"accesso negato"<<endl;
					}else{
						this->numero_ingressi -= comprensorio_sciistico[i-1].costo;
						cout<<"accesso consentito"<<endl;
					}
				}else{
					cout<<"accesso negato"<<endl;
				}
			}
		}

		void ricarica(int n, bool t){
			if(t){
				this->data = n;
			}else{
				this->numero_ingressi += n;
			}
		}
};


int main(){
	return 0;
}