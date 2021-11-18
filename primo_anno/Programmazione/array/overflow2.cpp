/*
- Author: Alessandro Frau

*/
#include<iostream>
#include <cstring>

using namespace std;

void auth(char name[10], char psw[], int length){
    int authentication = 0;
    cout<<sizeof(name)<<endl;
    cout<<name<<endl;
    cout<<name[10];

    if(strcmp( name, "admin" ) == 0 && strcmp( psw, "adminpass" ) == 0 ){
        authentication = 1;
    }


    if(authentication){
        cout << "Access granted\n";
        cout << (char)authentication;
    }else{
        cout << "Wrong username and password\n";
    }
}

int main(void){
    int len;
    char username[11];
    char password[10];

    cout<<"name ";
    cin>>username;

    auth(username,password,len);

    return 0;
}