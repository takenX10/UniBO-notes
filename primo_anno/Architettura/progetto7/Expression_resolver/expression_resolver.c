/*
Author: Alessandro Frau
Read README.md to have more info
*/
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>

//prende una stringa di numeri e restituisce un intero
int ascii_to_int(char c){
    int val = c - '0';
    return val;
}


int start(void){
    int val = 0;
    int val2 = 0;
    int first = 1;
    char operand;
    char c;
    do{
        c = getch();
        if((c >= '0' && c<= '9') || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '(' || c == ')' || c == '='){
            printf("%c",c);
            if(c >= '0' && c<= '9'){
                val = (val * 10) + ascii_to_int(c);
            }else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == ')' || c == '='){
                if(!first){
                    switch(operand){
                        case '+':
                            val2 = val2 + val;
                            break;
                        case '-':
                            val2 = val2 - val;
                            break;
                        case '*':
                            val2 = val2 * val;
                            break;
                        case '/':
                            val2 = val2 / val;
                            break;
                        case '%':
                            val2 = val2 % val;
                    }
                    if(c == ')' || c == '=') return val2;
                    val = 0;  
                }else{
                    val2 = val;
                    val = 0;
                    first = 0;
                }
                operand = c;
            }else if(c == '('){
                val = start();
            }
        }
    }while(c != '=' && c != ')');
    return val2;
}

void puliscischermo(void){
    if(system("cls")){
        system("clear");
    }
}

int main(){
    char c;
    int result;
    do{
        printf("EQUAZIONE: ");
        result = start();
        printf("%d\n",result);
        do{
            c = getch();
        }while(c != 13 && c != 27);
        puliscischermo();
    }while(c != 27);
    return 0;
}