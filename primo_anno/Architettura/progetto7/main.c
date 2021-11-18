/*
Author: Alessandro Frau
Progetto Bonus architettura degli elaboratori
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<dirent.h>
#include "main.h"
#include "custom_library.h"
#include "implementazioni.h"


// funzione che si occupa di prendere il file in input eliminando tutte le cose non necessarie
struct lineafile* prendi_file(char nomefile[]){
    DIR *d;
    FILE *fp;
    char filename[128];
    struct dirent *dir;
    struct lineafile *head = NULL;
    struct lineafile *aux = head;
    struct lineafile *prev = head;
    char c;
    int isDir, esci = 0;
    if(!is_contained(".vm", nomefile)){
        d = opendir(nomefile);
        isDir = 1;
        dir = readdir(d);
        strcpy(filename, dir->d_name);
    }else{
        isDir = 0;
        strcpy(filename, nomefile);
    }
    do{
        if(is_contained(".vm", filename)){
            fp = fopen(filename, "r");
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
        }
        printf("%s\n",filename);
        if(isDir){
            if((dir = readdir(d)) != NULL){
                strcpy(filename, nomefile);
                strcat(filename, "/");
                strcat(filename, dir->d_name);
            }else{
                closedir(d);
                esci++;
            }
        }else{
            esci++;
        }
    }while (!esci);
    aux = (struct lineafile*) malloc(sizeof(struct lineafile));
    strcpy(aux->linea, "call Sys.init 0");
    aux->next = head;
    head = aux;
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

// funzione che si occupa di trovare le funzioni usate
struct label* find_used_functions(struct lineafile* head, struct lineafile *mypos, struct label *base){
    char c;
    while(mypos != NULL){
        if(is_contained("call", mypos->linea)){
            if(!contenuto(mypos->linea, base)){
                if(base != NULL){
                    tail_insert(base, mypos->linea);            // aggiunge in coda cosi nelle chiamate ricorsive si riconosce gia se la funzione e' stata chiamata
                }else{
                    base = head_insert(base, mypos->linea);
                }
                base = find_used_functions(head, moveto(mypos->linea, head), base);
            }
        }else if(is_contained("return",mypos->linea)){
            return base;
        }
        mypos = mypos->next;
    }
}

// funzione che rimuove tutte le funzioni non usate, da chiamare dopo find_used_functions
struct lineafile* remove_dead_functions(struct lineafile *head, struct label *used){
    struct lineafile *aux = head;
    struct lineafile *prev = aux;
    int esci = 0;
    char part1[128], part2[128];
    while(aux != NULL){
        if(start_with("function", aux->linea)){
            split(aux->linea, part1, part2,' ');
            split(part2, part2, part1, ' ');
            if(!contenuto(part2, used)){
                esci = 0;
                prev->next = aux->next;
                free(aux);
                aux = prev->next;
                while(!esci){
                    if(aux == NULL){
                        esci++;
                    }else if(start_with("function", aux->linea) ){
                        esci++;
                    }else{
                        prev->next = aux->next;
                        free(aux);
                        aux = prev->next;
                    }
                }
            }else{
                prev = aux;
                if(aux != NULL)
                aux = aux->next;
            }
        }else{
            prev = aux;
            if(aux != NULL)
            aux = aux->next;
        }
    }
    return head;
}

// Funzione che parsa il file e scrive il file .asm
void parsefile(struct lineafile *head, struct label *label_head, int counter, char filename[]){
    FILE *fp;
    fp = fopen(filename, "w");
    struct lineafile *aux = head;
    char current_fname[128];
    strcpy(current_fname, filename);
    fprintf(fp, "@256\n");
    fprintf(fp, "D = A\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@Sys.init\n");
    fprintf(fp, "0;JMP\n");
    aux = aux->next;            // per togliere Sys.init chiamata due volte, serve per far riconoscere la call a find_used_function
    while(aux != NULL){
        if(start_with("and", aux->linea)){
            fp = andd(fp);
        }else if(start_with("or", aux->linea)){
            fp = orr(fp);
        }else if(start_with("push", aux->linea)){
            fp = push(aux->linea, filename, current_fname, fp);
        }else if(start_with("pop", aux->linea)){
            fp = pop(aux->linea, filename, current_fname, fp);
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
            fp = label(aux->linea, current_fname, fp);
        }else if(start_with("goto", aux->linea)){
            fp = gotoo(aux->linea, current_fname, fp);
        }else if(start_with("if-goto", aux->linea)){
            fp = if_goto(aux->linea, current_fname, fp);
        }else if(start_with("function", aux->linea)){
            fp = function(aux->linea, current_fname, fp);
        }else if(start_with("call", aux->linea)){
            fp = call(aux->linea, fp, label_head, &counter);
        }else if(start_with("return", aux->linea)){
            fp = returnn(fp);
        }
        aux = aux->next;
    }
    fp = default_implementations(fp);

    fclose(fp);
}

int main(int argc, char *argv[]){
    int label_counter = 1;
    char nomefile[128];
    char ext[5];
    strcpy(nomefile, argv[1]);
    struct lineafile *head = prendi_file(nomefile);
    struct label *label_head = prendi_label(head);
    struct label *used_functions = find_used_functions(head, head, NULL);
    head = remove_dead_functions(head, used_functions);
    if(is_contained(".vm", nomefile)){
        split(nomefile, nomefile, ext, '.');
    }
    parsefile(head, label_head, label_counter, strcat(nomefile, ".asm"));
    printf("\nDone!\n");
    return 0;
}
