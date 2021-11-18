#ifndef CUSTOM_LIBRARY_H_   
#define CUSTOM_LIBRARY_H_
#include "main.h"

struct label* head_insert(struct label *head, char name[]);

int is_contained(char a[], char b[]);

//controlla se la stringa b inizia con la stringa a
int start_with(char a[], char b[]);

// divide string nel primo carattere divisore, e mette la prima parte in a e la seconda in b
// presuppone che il carattere ci sia
void split(char string[], char *a, char *b, char divisore);

//prende una stringa di numeri e restituisce un intero
int ascii_to_int(char s[]);

void reverse_string(char s[]);

void int_to_ascii(int n, char s[]);

int exist(struct label *head, char string[]);

// crea una label non usata
void newlabel(char string[], struct label *head, int *counter);

struct lineafile* moveto(char str[], struct lineafile* head);

void merge_list(struct label *a, struct label *b);

int contenuto(char str[], struct label *lista);

void tail_insert(struct label *head, char str[]);

void printlist(struct lineafile *head);

void printlistalabel(struct label *head);

#endif