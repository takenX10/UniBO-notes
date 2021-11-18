/*
Author: Alessandro Frau
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include "main.h"
#include "custom_library.h"

// ti permette di caricare il file in una lista, con un elemento per riga
// elimina in automatico spazi e commenti
// aggiunge gli elementi alla lista con un tail insert dinamico (non scorre tutta la lista per farlo, ma tiene traccia della posizione corrente)
struct filestrings* makelist(FILE *f){
    struct filestrings *head = NULL;
    struct filestrings *current = head;
    char c[128];
    unsigned int is_commented = 0, is_line_commented = 0, esci = 1;
    int currentpos = 0;
    do{
        fscanf(f,"%c",&c[currentpos]);
        if(c[currentpos] == '\n' || feof(f)){ //prossima riga
            if(feof(f)){        // in caso esci dal loop
                esci = 0;
                c[currentpos] = '\0';
            }         
            
            if(is_line_commented || currentpos == 0){          // serve per non aggiungere la linea se e' commentata in partenza o vuota
                is_line_commented = 0;
                currentpos = 0;
                is_commented = 0;
            }else{
                struct filestrings *newstring = malloc(sizeof(struct filestrings));
                c[currentpos] = '\0'; // significa che la stringa deve essere grande max 127 caratteri
                currentpos = 0;
                is_commented = 0;
                strcpy(newstring->line,c);
                newstring->next = NULL;
                if(current == NULL){
                    head = newstring;
                    current = newstring;
                }else{
                    current->next = newstring;
                    current = newstring;
                }
            }
            
        }else{
            if(c[currentpos] == '/'){
                is_commented = 1;
                if(currentpos == 0) is_line_commented = 1;
            }
            if(c[currentpos] != ' ' && c[currentpos] != '\r' &&!is_commented){
                currentpos++;
            } 
        } 
             
    }while(esci);

    return head;
}


// carica i simboli di default nella symbol table
struct symbols* load_default_symbols(){
    struct symbols *table = NULL;
    table = head_insert(table, "R0", 0);    
    table = head_insert(table, "R1", 1);
    table = head_insert(table, "R2", 2);
    table = head_insert(table, "R3", 3);
    table = head_insert(table, "R4", 4);
    table = head_insert(table, "R5", 5);
    table = head_insert(table, "R6", 6);
    table = head_insert(table, "R7", 7);
    table = head_insert(table, "R8", 8);
    table = head_insert(table, "R9", 9);
    table = head_insert(table, "R10", 10);
    table = head_insert(table, "R11", 11);
    table = head_insert(table, "R12", 12);
    table = head_insert(table, "R13", 13);
    table = head_insert(table, "R14", 14);
    table = head_insert(table, "R15", 15);
    table = head_insert(table, "SCREEN", 16384);
    table = head_insert(table, "KBD", 24567);
    table = head_insert(table, "SP", 0);
    table = head_insert(table, "LCL", 1);
    table = head_insert(table, "ARG", 2);
    table = head_insert(table, "THIS", 3);
    table = head_insert(table, "THAT", 4);
    return table;
}


// crea la tabella di simboli, con simboli di default e label presenti nel codice
struct symbols* symbol_table(struct filestrings **head){
    struct symbols *st;
    st = load_default_symbols();
    struct filestrings *current_position = *head;
    struct filestrings *previous_position =NULL;
    int i=0;
    char stringa[128];
    while(current_position != NULL){
        if(current_position->line[0] == '('){           // significa che e' un etichetta
            taglia_etichetta(current_position->line,stringa);
            st = head_insert(st, stringa,i);
            *head = remove_element(current_position,previous_position,*head);
            current_position = previous_position;
        }else{
            i++;
        }
        previous_position = current_position;
        current_position = current_position->next;
    }
    return st;
}

// traduce le A instruction
int Ainstruction(char line[], struct symbols **sym, int *valore_etichetta_corrente){
    int i;
    char stringa_etichetta[128];
    int final_value;
    i = 0;
    do{
        i++;
        stringa_etichetta[i-1] = line[i];
    }while(line[i] != '\0');

    if(line[1] != '-' && (line[1] < 48 || line[1] > 57)){ // non e' un numero, ma un etichetta
        
        if(contains(*sym,stringa_etichetta)){
            final_value = valore(*sym,stringa_etichetta);
        }else{           // nuova etichetta, va aggiunta
            *valore_etichetta_corrente = *valore_etichetta_corrente + 1;
            *sym = head_insert(*sym, stringa_etichetta, *valore_etichetta_corrente);
            final_value = *valore_etichetta_corrente;
        }

    }else{ // e' un numero

        final_value = ascii_to_int(stringa_etichetta);

    }
    return final_value;
}

// traduce la linea di codice assembler in codice macchina binario
void translate_line(char startline[16], struct symbols **sym,int *vec){
    char first[10], second[10],third[10];
    char line[17];
    line[16] = '\0';
    if(startline[0] == '@'){ // A-instruction
        int val = Ainstruction(startline, sym, vec);
        int_to_bin(val,startline);
    }else{  //C instruction
        line[0] = line[1] = line[2] = '1';
        split(startline,first,second,'=');
        if(second[0] == '\0'){
            strcpy(second, first);
            strcpy(first, "");
        }
        if(is_inside(first,'A')){
            line[10] ='1';
        }else{
            line[10] = '0';
        }
        if(is_inside(first,'D')){
            line[11] = '1';
        }else{
            line[11] = '0';
        }
        if(is_inside(first,'M')){
            line[12] = '1';
        }else{
            line[12] = '0';
        }
        
        if(is_inside(startline,';')){    //jump
            split(second,second,third,';');
            if(is_inside(third,'P')){
                line[13] = line[14] = line[15] = '1';
            }else if(is_inside(third,'N')){
                line[13] = line[15] = '1';
                line[14] = '0';
            }else{
                if(is_inside(third,'E')){
                    line[14] = '1';
                }else{
                    line[14] = '0';
                }
                if(is_inside(third,'G')){
                    line[15] = '1';
                }else{
                    line[15] = '0';
                }
                if(is_inside(third,'L')){
                    line[13] = '1';
                }else{
                    line[13] = '0';
                }
            }
        }else{ //no jump
            line[13] = line[14] = line[15] = '0';
        }
        if(is_inside(second,'M')){
            line[3] = '1';
        }else{
            line[3] = '0';
        }
        // c1 c2 c3 c4 c5 c6
        // il codice risulta piu efficiente e di facile espansione in seguito mettendo hard coded i controlli per ogni possibilita'
        // cosi' e' sufficiente implementare 15 if, altrimenti ne userei nettamente di piu
        if(!strcmp(second, "0")){ //0
            line[4] = line[6] = line[8] = '1';
            line[5] = line[7] = line[9] = '0';
        }else if(!strcmp(second, "1")){ //1
            line[4] = line[5] = line[6] = line[7] = line[8] = line[9] = '1';
        }else if(!strcmp(second, "-1")){ // -1
            line[4] = line[5] = line[6] = line[8] = '1';
            line[7] = line[9] = '0';
        }else if(!strcmp(second,"D")){
            line[6] = line[7] = '1';
            line[4] = line[5] = line[8] = line[9] = '0';
        }else if(!strcmp(second,"A") || !strcmp(second,"M")){
            line[4] = line[5] = '1';
            line[6] = line[7] = line[8] = line[9] = '0';
        }else if(!strcmp(second,"!D")){
            line[6] = line[7] = line[9] = '1';
            line[4] = line[5] = line[8] = '0';
        }else if(!strcmp(second,"!A") || !strcmp(second,"!M")){
            line[4] = line[5] = line[9] = '1';
            line[6] = line[7] = line[8] = '0';
        }else if(!strcmp(second,"-D")){
            line[6] = line[7] = line[8] = line[9] = '1';
            line[4] = line[5] ='0';
        }else if(!strcmp(second,"-A") || !strcmp(second, "-M")){
            line[4] = line[5] = line[8] = line[9] ='1';
            line[6] = line[7] = '0';
        }else if(!strcmp(second, "D+1")){
            line[5] = line[6] = line[7] = line[8] = line[9] = '1';
            line[4] = '0';
        }else if(!strcmp(second, "A+1") || !strcmp(second,"M+1")){
            line[4] = line[5] = line[7] = line[8] = line[9] = '1';
            line[6] = '0';
        }else if(!strcmp(second, "D-1")){
            line[6] = line[7] = line[8] = '1';
            line[4] = line[5] = line[9] = '0';
        }else if(!strcmp(second, "A-1") || !strcmp(second, "M-1")){
            line[4] = line[5] = line[8] = '1';
            line[6] = line[7] = line[9] = '0';
        }else if(!strcmp(second, "D+A") || !strcmp(second, "D+M")){
            line[8] = '1';
            line[4] = line[5] = line[6] = line[7] = line[9] = '0';
        }else if(!strcmp(second, "D-A") || !strcmp(second,"D-M")){
            line[5] = line[8] = line[9] = '1';
            line[4] = line[6] = line[7] = '0';
        }else if(!strcmp(second, "A-D") || !strcmp(second, "M-D")){
            line[7] = line[8] = line[9] = '1';
            line[4] = line[5] = line[6] = '0';
        }else if(!strcmp(second, "D&A")||!strcmp(second,"D&M")){
            line[4] = line[5] = line[6] = line[7] = line[8] = line[9] = '0';
        }else if(!strcmp(second, "D|A") || !strcmp(second,"D|M")){
            line[5] = line[7] = line[9] = '1';
            line[4] = line[6] = line[8] = '0';
        }
        strcpy(startline,line);  
    }
}


int main(int argc, char *argv[]){
    FILE *fp, *ff;
    struct filestrings *head = NULL; 
    int vec = 15; //valore etichetta corrente, serve quando vengono create nuove etichette nelle A-instruction
    if(argc < 2){
        printf("Usage: ./assembler filename.asm\n");
    }else{
        //apri file
        char name[100];
        char ext[10];
        split(argv[1], name, ext, '.');
        fp = fopen(strcat(name, ".asm"), "r");
        split(argv[1], name, ext, '.');
        ff = fopen(strcat(name, ".hack"),"w");
        //carica nella lista il file
        head = makelist(fp);
        //printlist(head);
        struct symbols *sym = symbol_table(&head);
        struct filestrings *currentline = head;
        while(currentline != NULL){
            //printf("%s:\t\t",currentline->line);
            translate_line(currentline->line, &sym, &vec);
            //printf("%s\n",currentline->line);
            fprintf(ff,"%s\n", currentline->line);
            currentline = currentline->next;
        }
    }
    
    
    return 0;

}