//Transpuesta de una matriz
#include <iostream>
using namespace std;

int rows;
int columns;

int main(){
	//get matrix size
	cout << "Write how many rows the matrix has: ";
	cin >> rows;
	cout << "\nWrite how many columns the matrix has: ";
	cin >> columns;
	
	//create matrix
	int matrix[rows][columns];
	
	//get values
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			cout << "\nWrite value (" << i << ", " << j << ")";
			cin >> matrix[i][j];
		}
	}
	
	//create transpose
	int transpose[columns][rows];
	for(int i = 0; i < columns; i++){
		for(int j = 0; j < rows; j++){
			transpose[i][j] = matrix[j][i];
		}
	}
	
	// print both
	cout << "\n";
	for(int i = 0; i < rows; i++){
		cout << "\n";
		for(int j = 0; j < columns; j++){
			 cout << matrix[i][j] << " ";  
		}
	}
	cout << "\n";
	for(int i = 0; i < columns; i++){
		cout << "\n";
		for(int j = 0; j < rows; j++){
			 cout << transpose[i][j] << " ";  
		}
	}
	
}
