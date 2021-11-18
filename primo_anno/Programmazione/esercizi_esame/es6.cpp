/*
@ Author: Alessandro Frau

*/
#include<iostream>
using namespace std;

void bubblesort(int v[], int length){
	int aux;
	for(int i = 0 ; i < length-1; i++){
		for(int j = i+1 ; j<length; j++){
			if(v[i] > v[j]){
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}

// non e' molto efficente
int maxcopie(int v[], int length){
	bubblesort(v, length);
	int current = 0;
	int currentn = 0;
	int max = 0;
	int maxn = 0;
	int prev = 0;
	for(int i = 0; i<length;i++){
		if(v[i] == prev){
			current = v[i];
			currentn++;
			prev = v[i];
		}else{
			currentn = 1;
			current = v[i];
			prev = current;

		}
		if(currentn > maxn){
				maxn = currentn;
				max = current;
		}
	}
	return max;
}

int main(){
    int v[] = {-1,0,0,-1,2,2,0};
    cout<<maxcopie(v,7);
    return 0;
}