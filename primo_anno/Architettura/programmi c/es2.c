#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct list{
    char val;
    struct list *next;
}; 

struct list* makelist(struct list *head, char *caratteri){
    int i = 0;
    head = NULL;
    struct list *aux = head;
    for(i = 0; i < strlen(caratteri); i++){
        struct list *p = malloc(sizeof(struct list));
        p->next = NULL;
        p->val = caratteri[i];
        if(head == NULL){
            head = p;
            aux = head;
        }else{
            aux->next = p;
            aux = p;
        }
    }
    return head;
}

struct list* removel(struct list *head, int n){
    struct list *p = head;
    struct list *aux;
    if(n == 0){
        head = head->next;
        free(p);
    }else{
        for(int i=0;i<n-1;i++){
            p = p->next;
        }    
        aux = (p->next)->next;
        free(p->next);
        p->next = aux;
    }
    return head;
}

void printlist(struct list *head){
    struct list *p = head;
    while(p != NULL){
        printf("%c",p->val);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, char **argv){
    struct list *head;
    int n;
    if(argc>1){
        head = makelist(head, argv[1]);
        do{
            printf("inserisci indice carattere da eliminare:\t");
            scanf("%d",&n);
        }while(n<0 || n>strlen(argv[1]));
        head = removel(head, n);
        printlist(head);
    }else{
        printf("too few arguments\n");
    }
    return 0;
}

/*
int main(){
    struct list *head;
    char s[30];
    int n;
    printf("inserisci stringa: ");
    scanf("%s",&s);
    printf("%s",s);
    head = makelist(head, s);
    do{
        printf("inserisci indice carattere da eliminare:\t");
        scanf("%d",&n);
    }while(n<0 || n>strlen(s));
    head = removel(head, n);
    printlist(head);

    return 0;
}
*/
