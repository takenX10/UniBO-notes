int root5(int n){
    int a=1;
    do{
        a++;
    }while(a*a*a*a*a <= n);
    return a-1;
}

int log5(int n){
    int a=5,b=1;
    do{
        a*=5;
        b++;
    }while(a<=n);
    return b-1;
}