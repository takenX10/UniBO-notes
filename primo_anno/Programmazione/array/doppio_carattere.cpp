/*
@ Author: Alessandro Frau

*/
#include<iostream>
#include<cmath>
using namespace std;
/*
int first_double(char s[], int n){
    int acc[26] = {0};
    int i=-1;
    do{
        i++;
        acc[(int)s[i]-'a']++;
    }while(acc[(int)s[i]-'a'] != 2 && i<n);
    if (i > n) i = -2;
    return i+1;
}

void getstring(char s[]){
    int i;
    bool correct;
    do{
        cin>>s;
        i = 0;
        correct = true;
        while(correct && i < strlen(s)){
            i++;
            if(s[i]>'z' || s[i]<'a') correct = false;
        }
    }while (!correct);
}
*/

bool valore2(int A[], int m, int l){
    int i,j;
    bool val = false;
    i=0;
    while(!val && i<l ){
        j=i+1;
        while(!val && j<l){
            if(abs(A[i]-A[j]==m)) val = true;
            j++;
        }
        i++;
    }
    return val;
}

int main(){
    int len,M;
    int v[30];
    bool tst;
    cin>>len;
    cin>>M;
    
    cin>>v;
    tst = valore2(v,M,len);
    return 0;
}