/*
Author: Alessandro Frau
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct filestrings{
    char line[128];
    struct filestrings *next;
};

struct symbols{
    char simbolo[128];
    int value;
    struct symbols *next;
};


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
            if(c[currentpos] != ' ' && !is_commented){
                currentpos++;
            } 
        } 
             
    }while(esci);

    return head;
}

// printa la lista in output
void printlist(struct filestrings *head){
    struct filestrings *aux = head;
    while(aux != NULL){
        printf("%s\n",aux->line);
        aux = aux->next;
    }
}


struct symbols* head_insert(struct symbols *head, char s[], int v){
    struct symbols *newhead = malloc(sizeof(struct symbols));
    newhead->next = head;
    newhead->value = v;
    strcpy(newhead->simbolo, s);
    return newhead;
}

// carica i simboli di default nella symbol table
struct symbols* load_default_symbols(){
    struct symbols *table = NULL;
    char number[20];
    char s2[20];
    s2[0] = 'R';
    s2[1] = '\0';
    for(int i = 0;i<=16;i++){
        itoa(i,number,10);
        table = head_insert(table,strcat(s2,number),i);
        s2[0] = 'R';
        s2[1] = '\0';
    }
    table = head_insert(table, "SCREEN", 16384);
    table = head_insert(table, "KBD", 24567);
    table = head_insert(table, "SP", 0);
    table = head_insert(table, "LCL", 1);
    table = head_insert(table, "ARG", 2);
    table = head_insert(table, "THIS", 3);
    table = head_insert(table, "THAT", 4);
    return table;
}


// funzione che passata un etichetta e una stringa, mette il valore dell'etichetta all'interno delle
// parentesi nella stringa.
// es: s = (LABEL), alla fine della funzione final_string = LABEL 
void taglia_etichetta(char s[],char final_string[]){
    int i = 1;
    while(s[i]!=')'){
        final_string[i-1] = s[i];
        i++;
    }
    final_string[i-1] = '\0';
}

// rimuove un elemento da una lista, prende l'elemento da rimuovere, l'elemento precedente e la testa della lista
struct filestrings* remove_element(struct filestrings *current, struct filestrings *previous, struct filestrings *head){
    if(previous == NULL){
        struct filestrings *aux;
        aux = current->next;
        free(current);
        head = aux;
    } else{
        previous->next = current->next;
        free(current);
    }
    return head;
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

// controlla se il simbolo e' contenuto nella tabella
int contains(struct symbols *sym, char e[]){
    struct symbols *current = sym;
    int found = 0;
    while(current != NULL && !found){
        if(!strcmp(current->simbolo,e)){
            found = 1;
        }
        current = current->next;
    }
    return found;
}

// restituisce il valore del simbolo nella tabella, si presuppone che il simbolo sia presente (fare controllo con la funzione contains)
int valore(struct symbols *sym, char e[]){
    struct symbols *current = sym;
    while(strcmp(current->simbolo,e)){
        current = current->next;
    }
    return current->value;
}


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

        final_value = atoi(stringa_etichetta);

    }
    return final_value;
}

// prende un intero e restituisce il valore in binario, padding per 16 bit
void int_to_bin(int n, char string[]){
    int i = 15;
    while(n != 0){
        if(n%2 ==0){
            string[i] = '0';
        }else{
            string[i] = '1';
        }
        n = n/2;
        i--;
    }
    for(;i>=0;i--){
        string[i] = '0';
    }
    string[16] = '\0';
}

void split(char l[], char f[], char s[], char c){
    int i = 0;
    int curr = 0;
    while(l[i] != c && l[i] != '\0'){
        f[curr] = l[i];
        curr ++;
        i++;
    }
    if(l[i] != c){
        s[0] = '\0';
    }else{
        f[curr] = '\0';
        curr = 0;
        i++;
        while(l[i] != '\0'){
            s[curr] = l[i];
            curr ++;
            i++;
        }
        s[curr] = '\0';
    }
}

int is_inside(char l[], char t){
    int i = -1;
    int inside = 0;
    do{
        i++;
        if(l[i] == t){
            inside = 1;
        }
    }while(l[i] != t && l[i] != '\0');
    return inside;
}

void translate_line(char startline[16], struct symbols **sym,int *vec){
    int val;
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
    //just for debug
    argc = 2;
    /////////////
    if(argc < 2){
        printf("Usage: ./assembler filename.asm\n");
    }else{
        //apri file
        fp = fopen("Pong.asm", "r"); //cambia dopo debug                                                       //////////////////////////
        ff = fopen("Pong.hack","w");
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