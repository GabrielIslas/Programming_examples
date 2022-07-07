#include <iostream>
using namespace std;

int arr[10];

int main(){
	for(int i = 0; i < 10; i++){
		cout << "Inserte numero " << i + 1 << ":" << endl;
		cin >> arr[i];
	}
	
	cout << "Numero 1: " << arr[0] << endl;
	cout << "Numero 5: " << arr[4] << endl;
	cout << "Numero 10: " << arr[9] << endl;
}
