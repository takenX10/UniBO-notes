/*
@ Author: Alessandro Frau

*/
#include<iostream>
using namespace std;
int lung(char v[]){
    int i = 0;
    while(v[i]!='\0'){
        i++;
    }
    return i;
}

void concat(char s1[], char s2[]){
    int n = lung(s1), n2 = lung(s2);
    for (int i = 0; i < n2; i++){
        s1[i + n] = s2[i];
    }
}

int main(){
    char st1[20], st2[5];
    cin>>st1;
    cin>>st2;
    concat(st1,st2);
    cout<<st1;
    return 0;
}