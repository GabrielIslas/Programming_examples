#include <stdio.h>

int factorial(int n);


int main(){
	int prueba = 5;
	printf("%d", factorial(prueba));
}

int factorial(int n){
	if(n == 0){
		return 1;
	}
	else{
		return n * factorial(n-1);
	}
}
