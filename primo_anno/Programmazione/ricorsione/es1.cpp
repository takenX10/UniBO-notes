/*
@ Author: Alessandro Frau

*/
#include<iostream>
using namespace std;

int recursive(char s[], int start=0){
    int a = 0;
    int end = 0;
    if(s[start]=='a'){
        a = 1;
    }
    if(s[start]!= '\0'){
        a += recursive(s, start + 1);
    }
    return a;
}


int main(){
    char stringa[10] = "aaaaa";
    cout<<recursive(stringa, 0);

    return 0;
}