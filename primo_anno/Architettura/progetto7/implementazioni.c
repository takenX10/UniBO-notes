#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include "implementazioni.h"
/*
Tutte le implementazioni sono state commentate nel file implementazioniAsm.txt
*/
FILE* default_implementations(FILE *fp){
    // per andare alla fine del programma in caso si arrivi a questa istruzione
    fprintf(fp, "@END_OF_THE_PROGRAM\n");
    fprintf(fp, "0;JMP\n");

    fprintf(fp, "(DEFAULT_CALL_IMPLEMENTATION)\n");
    fprintf(fp, "@R15\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "M = D \n");
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
    fprintf(fp, "@THIS\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M + 1\n");
    fprintf(fp, "@THAT\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M + 1\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@5\n");
    fprintf(fp, "D = D - A\n");
    fprintf(fp, "@R14\n");
    fprintf(fp, "D = D - M\n");
    fprintf(fp, "@ARG\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@LCL\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@R13\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "0;JMP\n");

    fprintf(fp, "(DEFAULT_RETURN_IMPLEMENTATION)\n");
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
    fprintf(fp, "AM = D - 1\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@THAT\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@FRAME\n");
    fprintf(fp, "AM = M - 1\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@THIS\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@FRAME\n");
    fprintf(fp, "AM = M - 1\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@ARG\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@FRAME\n");
    fprintf(fp, "AM = M - 1\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@LCL\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@R13\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "0;JMP\n");

    fprintf(fp, "(DEFAULT_LT_IMPLEMENTATION)\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "AM = M - 1\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "D = M - D\n");
    fprintf(fp, "@DEFAULT_LT_IF_IMPLEMENTATION\n");
    fprintf(fp, "D;JLT\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = 0\n");
    fprintf(fp, "@DEFAULT_LT_IF2_IMPLEMENTATION\n");
    fprintf(fp, "0;JMP\n");
    fprintf(fp, "(DEFAULT_LT_IF_IMPLEMENTATION)\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = -1\n");
    fprintf(fp, "(DEFAULT_LT_IF2_IMPLEMENTATION)\n");
    fprintf(fp, "@R13\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "0;JMP\n");

    fprintf(fp, "(DEFAULT_GT_IMPLEMENTATION)\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "AM = M - 1\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "D = M - D\n");
    fprintf(fp, "@DEFAULT_GT_IF_IMPLEMENTATION\n");
    fprintf(fp, "D;JGT\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = 0\n");
    fprintf(fp, "@DEFAULT_GT_IF2_IMPLEMENTATION\n");
    fprintf(fp, "0;JMP\n");
    fprintf(fp, "(DEFAULT_GT_IF_IMPLEMENTATION)\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = -1\n");
    fprintf(fp, "(DEFAULT_GT_IF2_IMPLEMENTATION)\n");
    fprintf(fp, "@R13\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "0;JMP\n");

    fprintf(fp, "(DEFAULT_EQ_IMPLEMENTATION)\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "AM = M - 1\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "D = M - D\n");
    fprintf(fp, "@DEFAULT_EQ_IF_IMPLEMENTATION\n");
    fprintf(fp, "D;JEQ\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = 0\n");
    fprintf(fp, "@DEFAULT_EQ_IF2_IMPLEMENTATION\n");
    fprintf(fp, "0;JMP\n");
    fprintf(fp, "(DEFAULT_EQ_IF_IMPLEMENTATION)\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = -1\n");
    fprintf(fp, "(DEFAULT_EQ_IF2_IMPLEMENTATION)\n");
    fprintf(fp, "@R13\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "0;JMP\n");

    fprintf(fp, "(END_OF_THE_PROGRAM)\n");
    fprintf(fp, "@END_OF_THE_PROGRAM\n");
    fprintf(fp, "0;JMP\n");
    return fp;
}

FILE* andd(FILE *fp){
    fprintf(fp, "@SP\n");
    fprintf(fp, "AM = M - 1\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "A = A - 1\n");
    fprintf(fp, "M = M&D\n");
    return fp;
}

FILE* orr(FILE *fp){
    fprintf(fp, "@SP\n");
    fprintf(fp, "AM = M - 1\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "A = A - 1\n");
    fprintf(fp, "M = M|D\n");
    return fp;
}

FILE* add(FILE *fp){
    fprintf(fp, "@SP\n");
    fprintf(fp, "AM = M - 1\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "A = A - 1\n");
    fprintf(fp, "M = D + M\n");
    return fp;
}

FILE* sub(FILE *fp){
    fprintf(fp, "@SP\n");
    fprintf(fp, "AM = M - 1\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "A = A - 1\n");
    fprintf(fp, "M = M - D\n");
    return fp;
}

FILE* neg(FILE *fp){
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = -M\n");
    return fp;
}

FILE* nott(FILE *fp){
    fprintf(fp, "@SP\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = !M\n");
    return fp;
}

FILE* returnn(FILE *fp){
    fprintf(fp, "@DEFAULT_RETURN_IMPLEMENTATION\n");
    fprintf(fp, "0;JMP\n");
    return fp;
}

FILE* eq(FILE *fp, struct label *head, int *counter){
    char label1[128];
    newlabel(label1, head, counter);
    fprintf(fp, "@%s\n", label1);
    fprintf(fp, "D = A\n");
    fprintf(fp, "@R13\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@DEFAULT_EQ_IMPLEMENTATION\n");
    fprintf(fp, "0;JMP\n");
    fprintf(fp, "(%s)\n",label1);
    return fp;
}

FILE* gt(FILE *fp, struct label *head, int *counter){
    char label1[128];
    newlabel(label1, head, counter);
    fprintf(fp, "@%s\n", label1);
    fprintf(fp, "D = A\n");
    fprintf(fp, "@R13\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@DEFAULT_GT_IMPLEMENTATION\n");
    fprintf(fp, "0;JMP\n");
    fprintf(fp, "(%s)\n",label1);
    return fp;
}

FILE* lt(FILE *fp, struct label *head, int *counter){
    char label1[128];
    newlabel(label1, head, counter);
    fprintf(fp, "@%s\n", label1);
    fprintf(fp, "D = A\n");
    fprintf(fp, "@R13\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@DEFAULT_LT_IMPLEMENTATION\n");
    fprintf(fp, "0;JMP\n");
    fprintf(fp, "(%s)\n",label1);
    return fp;
}

FILE* label(char string[],char current_fname[], FILE *fp){
    char line[128], useless_string[128];
    split(string, useless_string, line, ' ');
    strcpy(useless_string, current_fname);
    strcat(useless_string, ".");
    strcat(useless_string, line);
    strcpy(line, useless_string);
    fprintf(fp, "(%s)\n", line);
    return fp; 
}

FILE* if_goto(char string[], char current_fname[], FILE *fp){
    char line[128], useless_string[128];
    split(string, useless_string, line, ' ');
    strcpy(useless_string, current_fname);
    strcat(useless_string, ".");
    strcat(useless_string, line);
    strcpy(line, useless_string);
    fprintf(fp, "@SP\n");
    fprintf(fp, "AM = M - 1\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@%s\n",line);
    fprintf(fp, "D;JGT\n");
    fprintf(fp, "D;JLT\n");
    return fp; 
}

FILE* gotoo(char string[], char current_fname[], FILE *fp){
    char line[128], useless_string[128];
    split(string, useless_string, line, ' ');
    strcpy(useless_string, current_fname);
    strcat(useless_string, ".");
    strcat(useless_string, line);
    strcpy(line, useless_string);
    fprintf(fp, "@%s\n", line);
    fprintf(fp, "0;JMP\n");
    return fp; 
}

FILE* function(char string[], char current_fname[], FILE *fp){
    char line1[128];
    char line2[128];
    split(string, line1, line2, ' ');
    split(line2, line1, line2, ' ');
    strcpy(current_fname, line1);
    int nlocal = ascii_to_int(line2);
    fprintf(fp, "(%s)\n", line1);
    for(int i = 0;i<nlocal;i++){
        fprintf(fp, "@SP\n");
        fprintf(fp, "M = M + 1\n");
        fprintf(fp, "A = M - 1\n");
        fprintf(fp, "M = 0\n");
    }
    return fp; 
}

FILE* push(char string[], char filename[], char current_fname[], FILE *fp){
    char line1[128], line2[128];
    char staticc[128];
    char other[128];
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
        strcpy(staticc, current_fname);
        split(staticc, staticc, other, '.');
        strcat(staticc, ".");
        strcat(staticc, line2);
        fprintf(fp, "@%s\n",staticc);
        fprintf(fp, "D = M\n");
    }else if(strcmp(line1, "this")==0){
        fprintf(fp, "@THIS\n");
        fprintf(fp, "D = M\n");
        fprintf(fp, "@%s\n",line2);
        fprintf(fp, "A = D + A\n");
        fprintf(fp, "D = M\n");
    }else if(strcmp(line1, "that")==0){
        fprintf(fp, "@THAT\n");
        fprintf(fp, "D = M\n");
        fprintf(fp, "@%s\n",line2);
        fprintf(fp, "A = D + A\n");
        fprintf(fp, "D = M\n");
    }else if(strcmp(line1, "pointer")==0){
        fprintf(fp, "@3\n");
        fprintf(fp, "D = A\n");
        fprintf(fp, "@%s\n", line2);
        fprintf(fp, "A = D + A\n");
        fprintf(fp, "D = M\n");
    }else if(strcmp(line1, "temp")==0){
        fprintf(fp, "@5\n");
        fprintf(fp, "D = A\n");
        fprintf(fp, "@%s\n", line2);
        fprintf(fp, "A = D + A\n");
        fprintf(fp, "D = M\n");
    }
    fprintf(fp, "@SP\n");
    fprintf(fp, "M = M + 1\n");
    fprintf(fp, "A = M - 1\n");
    fprintf(fp, "M = D\n");
    return fp;
}

FILE* pop(char string[], char filename[], char current_fname[], FILE *fp){
    char line1[128], line2[128];
    char other[128];
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
    }else if(strcmp(line1, "static")==0){
        strcpy(staticc, current_fname);
        split(staticc, staticc, other, '.');
        strcat(staticc, ".");
        strcat(staticc, line2);
        fprintf(fp, "@%s\n",staticc);
        fprintf(fp, "D = A\n");
    }else if(strcmp(line1, "this")==0){
        fprintf(fp, "@THIS\n");
        fprintf(fp, "D = M\n");
        fprintf(fp, "@%s\n", line2);
        fprintf(fp, "D = D + A\n");
    }else if(strcmp(line1, "that")==0){
        fprintf(fp, "@THAT\n");
        fprintf(fp, "D = M\n");
        fprintf(fp, "@%s\n", line2);
        fprintf(fp, "D = D + A\n");
    }else if(strcmp(line1, "pointer")==0){
        fprintf(fp, "@3\n");
        fprintf(fp, "D = A\n");
        fprintf(fp, "@%s\n", line2);
        fprintf(fp, "D = D + A\n");
    }else if(strcmp(line1, "temp")==0){
        fprintf(fp, "@5\n");
        fprintf(fp, "D = A\n");
        fprintf(fp, "@%s\n", line2);
        fprintf(fp, "D = D + A\n");
    }
    fprintf(fp, "@13\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@SP\n");
    fprintf(fp, "AM = M - 1\n");
    fprintf(fp, "D = M\n");
    fprintf(fp, "@13\n");
    fprintf(fp, "A = M\n");
    fprintf(fp, "M = D\n");
    return fp;
}

FILE* call(char string[], FILE *fp, struct label *head, int *counter){
    char label1[128], label2[128];
    newlabel(label1, head, counter);
    newlabel(label2, head, counter);
    char fname[128], nparam[128];
    split(string, fname, nparam, ' ');
    split(nparam, fname, nparam, ' ');
    fprintf(fp, "@%s\n",label1);
    fprintf(fp, "D = A\n");
    fprintf(fp, "@R13\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@%s\n",nparam);
    fprintf(fp, "D = A\n");
    fprintf(fp, "@R14\n");
    fprintf(fp, "M = D\n");
    fprintf(fp ,"@%s\n",label2);
    fprintf(fp, "D = A\n");
    fprintf(fp, "@R15\n");
    fprintf(fp, "M = D\n");
    fprintf(fp, "@DEFAULT_CALL_IMPLEMENTATION\n");
    fprintf(fp, "0;JMP\n");
    fprintf(fp, "(%s)\n",label1);
    fprintf(fp, "@%s\n",fname);
    fprintf(fp, "0;JMP\n");
    fprintf(fp, "(%s)\n",label2);
    return fp;
}
