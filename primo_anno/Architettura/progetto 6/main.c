/*
Author: Alessandro Frau
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include "main.h"
#include "custom_library.h"
#include "implementazioni.h"

// funzione che si occupa di prendere il file in input eliminando tutte le cose non necessarie
struct lineafile* prendi_file(char nomefile[]){
    FILE *fp;
    fp = fopen(nomefile, "r");
    struct lineafile *head = NULL;
    struct lineafile *aux = head;
    struct lineafile *prev = head;
    char c;
    while(!feof(fp)){
        aux = (struct lineafile*) malloc(sizeof(struct lineafile));
        aux->next = NULL;
        int i = 0;
        do{
            fscanf(fp,"%c", &c);
            if(c != '\n' && c != '/' && c != '\r' && !feof(fp)){
                if(c != ' ' || i != 0){
                    aux->linea[i] = c;
                    i++;
                }
            }else{
                aux->linea[i] = '\0';
            }
        }while(c != '\n' && c != '/' && c != '\r' && !feof(fp));
        if(i != 0){
            int length = strlen(aux->linea);
            int j = 1;
            while(aux->linea[length - j] == ' '){
                j++;
            }
            aux->linea[length-j+1] = '\0';
            if(head == NULL){
                head = aux;
                prev = aux;
            }else{
                prev->next = aux;
                prev = aux;
            }
        }else{
            while(c != '\n' && !feof(fp)){
                fscanf(fp, "%c", &c);
            }
            free(aux);
        }
        
    }
    fclose(fp);
    return head;
}

// funzione che si occupa di prendere tutte le label nel file .vm, servira' per il controllo delle label duplicate
struct label* prendi_label(struct lineafile *head2){
    struct lineafile *aux = head2;
    struct label *head = NULL;
    char label_name[128];
    while(aux != NULL){
        if(is_contained("label", aux->linea)){
            int i = 0;
            while(aux->linea[i] != ' ') i++;
            i++;
            int j = 0;
            while(aux->linea[i] != '\0'){
                label_name[j] = aux->linea[i];
                j++;
                i++;
            }
            label_name[j] = '\0';
            head = head_insert(head, label_name);
        }
        aux = aux->next;
    }
    return head;
}

// Funzione che parsa il file e scrive il file .asm
void parsefile(struct lineafile *head, struct label *label_head, int counter, char filename[]){
    FILE *fp;
    fp = fopen(filename, "w");
    struct lineafile *aux = head;
    fprintf(fp, "@256\n");
    fprintf(fp, "D = A\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = D\n");
    while(aux != NULL){
        if(start_with("and", aux->linea)){
            fp = andd(fp);
        }else if(start_with("or", aux->linea)){
            fp = orr(fp);
        }else if(start_with("push", aux->linea)){
            fp = push(aux->linea, filename, fp);
        }else if(start_with("pop", aux->linea)){
            fp = pop(aux->linea, filename, fp);
        }else if(start_with("add", aux->linea)){
            fp = add(fp);
        }else if(start_with("sub", aux->linea)){
            fp = sub(fp);
        }else if(start_with("neg", aux->linea)){
            fp = neg(fp);
        }else if(start_with("not", aux->linea)){
            fp = nott(fp);
        }else if(start_with("eq", aux->linea)){
            fp = eq(fp, label_head, &counter);
        }else if(start_with("gt", aux->linea)){
            fp = gt(fp, label_head, &counter);
        }else if(start_with("lt", aux->linea)){
            fp = lt(fp, label_head, &counter);
        }else if(start_with("label", aux->linea)){
            fp = label(aux->linea, fp);
        }else if(start_with("goto", aux->linea)){
            fp = gotoo(aux->linea, fp);
        }else if(start_with("if-goto", aux->linea)){
            fp = if_goto(aux->linea, fp);
        }else if(start_with("function", aux->linea)){
            fp = function(aux->linea, fp);
        }else if(start_with("call", aux->linea)){
            fp = call(aux->linea, fp, label_head, &counter);
        }else if(start_with("return", aux->linea)){
            fp = returnn(fp);
        }
        aux = aux->next;
    }


    fclose(fp);
}

int main(int argc, char *argv[]){
    int label_counter = 1;
    char nomefile[128];
    char ext[5];
    split(argv[1], nomefile, ext, '.');
    struct lineafile *head = prendi_file(argv[1]);
    struct label *label_head = prendi_label(head);
    parsefile(head, label_head, label_counter, strcat(nomefile, ".asm"));
    printf("\nDone!\n");
}

