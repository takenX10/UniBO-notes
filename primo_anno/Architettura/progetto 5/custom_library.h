#ifndef CUSTOM_LIBRARY_H_   
#define CUSTOM_LIBRARY_H_
#include "main.h"

int is_inside(char l[], char t);

int ascii_to_int(char s[]);

int valore(struct symbols *sym, char e[]);

void split(char l[], char f[], char s[], char c);

void int_to_bin(int n, char string[]);

void taglia_etichetta(char s[],char final_string[]);

struct symbols* head_insert(struct symbols *head, char s[], int v);

void printlist(struct filestrings *head);

struct filestrings* remove_element(struct filestrings *current, struct filestrings *previous, struct filestrings *head);

int contains(struct symbols *sym, char e[]);

#endif