#include <stdio.h>

int main(){
	int arr[] = {1, 2, 3, 8, 5, 6};
	
	int n = 6;
	
	int key = 8;
	
	for(int i = 0; i < n; i++){
		if(arr[i] == key){
			printf("The position is: %d", i);
		}
	}
}
