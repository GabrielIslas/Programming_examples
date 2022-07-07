#include <iostream>
using namespace std;

int sum(int n);

int main(){
	int value;
	cout << "Insert number: ";
	cin >> 	value;
	cout << "\nSum is: " << sum(value);
	return 0;
}

int sum(int n){
	if(n == 1){
		return 1;
	}
	else{
		return n + sum(n-1); 
	}
}

