/*
@ Author: Alessandro Frau

*/
#include<iostream>
using namespace std;

void bubblesort_recursive(int v[], int n, int i = 0, int j = 0){
	if(v[j] > v[j+1]){
		int temp = v[j];
		v[j] = v[j+1];
		v[j+1] = temp;
	}
	if(j >= n-1){
		if(i < n-1){
			bubblesort_recursive(v,n,i+1,0);
		}
	}else{
		bubblesort_recursive(v,n,i,j+1);
	}
}


int main(){
    int v[] = {1,3,8, 3, 4, 1, 8, 6};
    bubblesort_recursive(v,8);
    return 0;
}