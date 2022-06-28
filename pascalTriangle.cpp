#include <iostream>

/*Created by Jesus Javier Can Noh and Gabriel Islas Peraza*/
/*
Codigo que genera el triangulo de pascal con las filas dadas
Se utiliza una funcion recursiva que llama a los valores del triangulo de pascal de filas pasadas,
hsata llegar a valores de defecto de 1 en las orillas del triangulo.
*/

using namespace std;

void generatePascalTriangle(int rowAmount); //funcion que inicia todo

int generatePascalNumber(int row, int position); //generar cada numero del triangulo individualmente

int main(){
	int rows; //filas
	
	cout << "Escribe la cantidad de filas: ";
	cin >> rows; //recibir filas
	
	generatePascalTriangle(rows); //generar triangulo con las filas dadas
}

void generatePascalTriangle(int rowAmount){
	
	for(int i = 0; i < rowAmount; i++){ // generar la cantidad de filas
		
		for(int k = rowAmount-i; k > 0; k--){ // espacios para dejarlo simetrico (mas o menos)
			cout << " ";
		}
		
		int pascalRow[i + 1]; //crear array del tamaño de la fila que se esta generando
		for(int j = 0; j < i + 1; j++){ //ir a traves de la fila
			pascalRow[j] = generatePascalNumber(i, j); //generar numero en cada posicion
		}
		
		for(int j = 0; j < i + 1; j++){ //imprimir fila
			cout << pascalRow[j] << " ";
		}
		cout << "\n"; //siguiente linea
		
	}
}

int generatePascalNumber(int row, int position){ // necesito saber en que fila y en que posicion requiero el numero
	if(row == 0 || position == 0 || position == row){ // valores de 1 por defecto, en las orillas y en la cima
		return 1;
	}
	else{ //sumar los dos numeros de arriba
		return generatePascalNumber(row - 1, position - 1) + generatePascalNumber(row - 1, position);
	}
}
