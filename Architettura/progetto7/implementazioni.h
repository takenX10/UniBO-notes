#ifndef IMPLEMENTAZIONI_H_   
#define IMPLEMENTAZIONI_H
#include "main.h"
#include "custom_library.h"

FILE* default_implementations(FILE *fp);

FILE* andd(FILE *fp);

FILE* orr(FILE *fp);

FILE* add(FILE *fp);

FILE* sub(FILE *fp);

FILE* neg(FILE *fp);

FILE* nott(FILE *fp);

FILE* returnn(FILE *fp);

FILE* eq(FILE *fp, struct label *head, int *counter);

FILE* gt(FILE *fp, struct label *head, int *counter);

FILE* lt(FILE *fp, struct label *head, int *counter);

FILE* label(char string[],char current_fname[], FILE *fp);

FILE* if_goto(char string[], char current_fname[], FILE *fp);

FILE* gotoo(char string[], char current_fname[], FILE *fp); 

FILE* function(char string[], char current_fname[], FILE *fp);

FILE* push(char string[], char filename[], char current_fname[], FILE *fp);

FILE* pop(char string[], char filename[], char current_fname[], FILE *fp);

FILE* call(char string[], FILE *fp, struct label *head, int *counter);

#endif