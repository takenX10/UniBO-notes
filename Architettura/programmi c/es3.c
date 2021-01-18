#include<stdio.h>
#include<stdlib.h>


int main(int argc,char **argv){
    FILE *f1,*f2;
    int i = 0;
    char a;
    if(argc<3){
        printf("too few arguments\n");
        return -1;
    }
    f1 = fopen(argv[1],"r");
    f2 = fopen(argv[2],"w");

    if(f1 == NULL){
        printf("errore in apertura file\n");
        return -2;
    }

    while(!feof(f1)){
        do{
            fscanf(f1,"%c",&a);
            i++;
        }while(a != '\n' && a != ' ' && a != '\t' && !feof(f1));
        i--;
        if(i>0){
            fprintf(f2,"%d",i);
            if(a == '\n')
                fprintf(f2,"\n");
            else
                fprintf(f2,"%c",' ');
        }
        i = 0;
    }
    printf("done!\n");
    return 0;
}