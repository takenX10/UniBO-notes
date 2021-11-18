#ifndef _MAIN_H_
#define _MAIN_H_


struct label{
    char name[128];
    struct label *next;
};

struct lineafile{
    char linea[128];
    struct lineafile *next;
};

// funzione che si occupa di prendere il file in input eliminando tutte le cose non necessarie
struct lineafile* prendi_file(char nomefile[]);

// funzione che si occupa di prendere tutte le label nel file .vm, servira' per il controllo delle label duplicate
struct label* prendi_label(struct lineafile *head2);

// funzione che si occupa di trovare le funzioni usate
struct label* find_used_functions(struct lineafile* head, struct lineafile *mypos, struct label *base);

// funzione che rimuove tutte le funzioni non usate, da chiamare dopo find_used_functions
struct lineafile* remove_dead_functions(struct lineafile *head, struct label *used);

// Funzione che parsa il file e scrive il file .asm
void parsefile(struct lineafile *head, struct label *label_head, int counter, char filename[]);

#endif // _MAIN_H_