#include <stdio.h>

//Declare both values, floats to allow decimals
float n1, n2;

int main(){
	/* Receiving values */
	printf("Type first value: ");
	scanf("%f", &n1); //scanf for inputing values, declare the type and then the variable that will receive it
	printf("\nType second value: ");
	scanf("%f", &n2);
	
	/* Calculating everything */
	float sum = n1 + n2;
	float subtract = n1 - n2;
	float multiply = n1 * n2;
	float divide = n1 / n2;
	
	/* Print results */
	printf("\nN1 + N2 = %f", sum);
	printf("\nN1 - N2 = %f", subtract);
	printf("\nN1 * N2 = %f", multiply);
	printf("\nN1 / N2 = %f", divide);
	
	return 0;
}
