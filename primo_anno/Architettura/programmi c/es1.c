#include <stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
    FILE *f1, *f2;
    char a;
    if(argc<3){
        printf("too few arguments\n");
    }else{
        f1 = fopen(argv[1],"r");
        f2 = fopen(argv[2],"w");
        fscanf(f1,"%c",&a);        
        while(!feof(f1)){
            printf("%c ",a);
            fprintf(f2,"%c",a);
            fscanf(f1,"%c",&a);
        }
        fclose(f1);
        fclose(f2);
        printf("\ndone\n");
    }
    return 0;

}