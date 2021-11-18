/*
@ Author: Alessandro Frau

*/
#include<iostream>
using namespace std;

int nonzero(int v[], int length){
	int max_index = 0;
	int current_index = 0;
	int lsequenza_max = 0;
	int lsequenza_current = 0;
	for(int i = 0; i<length; i++){
		if(v[i] == 0){
			current_index = -1;
			lsequenza_current = 0;
		}else{
			if(current_index == -1){
				current_index = i;
			}
			lsequenza_current++;
			if(lsequenza_current > lsequenza_max){
				max_index = current_index;
				lsequenza_max = lsequenza_current;
			}
		}
	}
	return max_index;
}


int main(){
    
    int v[] = {0,1,0};
    cout<<nonzero(v,3);
    return 0;
}