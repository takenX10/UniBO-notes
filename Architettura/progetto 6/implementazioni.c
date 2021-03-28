#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include "implementazioni.h"
/*
Tutte le implementazioni sono state commentate nel file implementazioniAsm.txt
*/
FILE* andd(FILE *fp){
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M - 1\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = M&D\n\n");
    return fp;
}

FILE* orr(FILE *fp){
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M - 1\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = M|D\n\n");
    return fp;
}

FILE* add(FILE *fp){
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M - 1\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = D + M\n\n");
    return fp;
}

FILE* sub(FILE *fp){
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M - 1\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = M - D\n\n");
    return fp;
}

FILE* neg(FILE *fp){
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = -M\n\n");
    return fp;
}

FILE* nott(FILE *fp){
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = !M\n\n");
    return fp;
}

FILE* returnn(FILE *fp){
    fprintf(fp, "@5\n");
    fprintf(fp, "D = A\n");
    fprintf(fp, "@LCL\n");
    fprintf(fp, "A = M - D\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@R13\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@ARG\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@ARG\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = D + 1\n");
    fprintf(fp, "@LCL\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@FRAME\n");
    fprintf(fp, "M = D - 1\n");
    fprintf(fp, "@FRAME\n");
    fprintf(fp, "M = M - 1\n");
    fprintf(fp, "@FRAME\n");
    fprintf(fp, "M = M - 1\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@ARG\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@FRAME\n");
    fprintf(fp, "M = M - 1\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@LCL\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@R13\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "0;JMP\n\n");
    return fp;
}

FILE* eq(FILE *fp, struct label *head, int *counter){
    char label1[128], label2[128];
    newlabel(label1, head, counter);
    newlabel(label2, head, counter);
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M - 1\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "D = M - D\n");
    fprintf(fp, "@%s\n", label1);
    fprintf(fp, "D;JEQ\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = 0\n");
    fprintf(fp, "@%s\n",label2);
    fprintf(fp, "0;JMP\n");
    fprintf(fp, "(%s)\n", label1);
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = -1\n");
    fprintf(fp, "(%s)\n\n",label2);
    return fp;
}

FILE* gt(FILE *fp, struct label *head, int *counter){
    char label1[128], label2[128];
    newlabel(label1, head, counter);
    newlabel(label2, head, counter);
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M - 1\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "D = M - D\n");
    fprintf(fp, "@%s\n",label1);
    fprintf(fp, "D;JGT\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = 0\n");
    fprintf(fp, "@%s\n",label2);
    fprintf(fp, "0;JMP\n");
    fprintf(fp, "(%s)\n",label1);
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = -1\n");
    fprintf(fp, "(%s)\n\n",label2);   
    return fp;
}

FILE* lt(FILE *fp, struct label *head, int *counter){
    char label1[128], label2[128];
    newlabel(label1, head, counter);
    newlabel(label2, head, counter);
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M - 1\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "D = M - D\n");
    fprintf(fp, "@%s\n",label1);
    fprintf(fp, "D;JLT\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = 0\n");
    fprintf(fp, "@%s\n",label2);
    fprintf(fp, "0;JMP\n");
    fprintf(fp, "(%s)\n",label1);
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = -1\n");
    fprintf(fp, "(%s)\n\n",label2);
    return fp;
}

FILE* label(char string[], FILE *fp){
    char line[128], useless_string[128];
    split(string, useless_string, line, ' ');
    fprintf(fp, "(%s)\n\n", line);
    return fp; 
}

FILE* if_goto(char string[], FILE *fp){
    char line[128], useless_string[128];
    split(string, useless_string, line, ' ');
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M - 1\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@%s\n",line);
    fprintf(fp, "D;JGT\n\n");
    fprintf(fp, "D;JLT\n\n");
    return fp; 
}

FILE* gotoo(char string[], FILE *fp){
    char line[128], useless_string[128];
    split(string, useless_string, line, ' ');
    fprintf(fp, "@%s\n", line);
    fprintf(fp, "0;JMP\n\n");
    return fp; 
}

FILE* function(char string[], FILE *fp){
    char line1[128];
    char line2[128];
    split(string, line1, line2, ' ');
    split(line2, line1, line2, ' ');
    int nlocal = ascii_to_int(line2);
    fprintf(fp, "(%s)\n", line1);
    for(int i = 0;i<nlocal;i++){
        fprintf(fp, "@0\n");
        fprintf(fp, "D = A\n");
        fprintf(fp, "@SP\n");
        fprintf(fp, "A = M\n");
        fprintf(fp, "M = D\n");
        fprintf(fp, "@SP\n");
        fprintf(fp, "M = M + 1\n");
    }
    fprintf(fp, "\n");
    return fp; 
}

FILE* push(char string[], char filename[], FILE *fp){
    char line1[128], line2[128];
    char staticc[128];
    char other[5];
    split(string, line1, line2, ' ');
    split(line2, line1, line2, ' ');
    if(strcmp(line1, "constant") == 0){
        fprintf(fp, "@%s\n", line2);
        fprintf(fp, "D = A\n");
    }else if(strcmp(line1, "argument")==0){
        fprintf(fp, "@%s\n",line2);
        fprintf(fp, "D = A\n");
        fprintf(fp, "@ARG\n");
        fprintf(fp, "A = M + D\n");
        fprintf(fp, "D = M\n");
    }else if(strcmp(line1, "local")==0){
        fprintf(fp, "@%s\n",line2);
        fprintf(fp, "D = A\n");
        fprintf(fp, "@LCL\n");
        fprintf(fp, "A = M + D\n");
        fprintf(fp, "D = M\n");
    }else if(strcmp(line1, "static")==0){
        strcpy(staticc, filename);
        split(staticc, staticc, other, '.');
        strcat(staticc, ".");
        strcat(staticc, line2);
        fprintf(fp, "@%s\n",staticc);
        fprintf(fp, "D = M\n");
    }

    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M + 1\n\n");
    return fp;
}

FILE* pop(char string[], char filename[], FILE *fp){
    char line1[128], line2[128];
    char other[5];
    char staticc[128];
    split(string, line1, line2, ' ');
    split(line2, line1, line2, ' ');
    if(strcmp(line1, "argument") == 0){
        fprintf(fp, "@%s\n", line2);
        fprintf(fp, "D = A\n");
        fprintf(fp, "@ARG\n");
        fprintf(fp, "D = M + D\n");
    }else if(strcmp(line1, "local")==0){
        fprintf(fp, "@%s\n", line2);
        fprintf(fp, "D = A\n");
        fprintf(fp, "@LCL\n");
        fprintf(fp, "D = M + D\n");
    }else{
        strcpy(staticc, filename);
        split(staticc, staticc, other, '.');
        strcat(staticc, ".");
        strcat(staticc, line2);
        fprintf(fp, "@%s\n",staticc);
        fprintf(fp, "D = A\n");
    }
    fprintf(fp, "@5\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M - 1\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@5\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "M = D\n\n");
    return fp;
}

FILE* call(char string[], FILE *fp, struct label *head, int *counter){
    char label1[128];
    newlabel(label1, head, counter);
    char fname[128], nparam[128];
    split(string, fname, nparam, ' ');
    split(nparam, fname, nparam, ' ');
    fprintf(fp, "@%s\n", label1);
    fprintf(fp, "D = A\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M + 1\n");
    fprintf(fp, "@LCL\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M + 1\n");
    fprintf(fp, "@ARG\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M + 1\n");
    fprintf(fp, "@0\n");
    fprintf(fp, "D = A\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M + 1\n");
    fprintf(fp, "@0\n");
    fprintf(fp, "D = A\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M + 1\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@%s\n", nparam);
    fprintf(fp, "D = D - A\n");
    fprintf(fp, "@5\n");
    fprintf(fp, "D = D - A\n");
    fprintf(fp, "@ARG\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@LCL\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@%s\n", fname);
    fprintf(fp, "0;JMP\n");
    fprintf(fp, "(%s)\n\n", label1);
    return fp;
}
