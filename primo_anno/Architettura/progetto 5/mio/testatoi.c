#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

int ascii_to_int(char s[]){
    int len = strlen(s);
    int tot = 0;
    for(int i = 0;i < len;i++){
        tot += (int)pow(10,i)*(s[len-i-1]-48);
    }
    return tot;
}
#define string_length 20

void reverse_string(char s[]){
    int i;
    int length = strlen(s);
    char aux[string_length];
    for( i = 0;i < length;i++){
        aux[i] = s[length-i-1];
    }
    aux[i] = '\0';
    strcpy(s,aux);
}

void int_to_ascii(int n, char s[]){
    int i = 0;
    while(n!=0){
        s[i] = '0' + n%10;
        n = n/10;
        i++;
    }
    reverse_string(s);
}


int main(){
    int n = 122;
    char s[20];
    int_to_ascii(n,s);
//    printf("%d\n",ascii_to_int("0920"));
    printf("%s\n",s);
    return 0;
}
