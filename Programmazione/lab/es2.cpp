/*
@ Author: Alessandro Frau

*/
#include<iostream>
#include<time.h>
using namespace std;

int main(){
    srand(time(NULL));
    int a,b,c;
    cin>>a>>b;
    c = rand() % 5;
    if(c==0)
        cout<<a%b;
    else
        if(c==1) 
            cout<<a+b;
        else
            if(c==2)
                cout<<a-b;
            else
                if(c==3)
                    cout<<a*b;
                else
                    if(c==4)
                        cout<<a/b;
    return 0;
}