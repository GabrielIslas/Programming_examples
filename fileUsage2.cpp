/* Crear struct que alamcene los siguientes datos de una persona:
Nombre
Edad
Ciudad de residencia

Pedir al usuario esos datos de una persona y guardarlos en un fichero llamado
"gente.dat". Cerrar el fichero, volverlo a abrir para lectura y mostrar los datos
que se habia guardado.
*/

/*Ampliar el programa anterior para que sea un array de structs, de forma que se puedan tener los datos de 10 personas.
Se debera pedir al usuarios las 10 personas y guardarlas. Entonces debemos escoger entre 1 y 10 e imprimir su info.
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	struct Persona{
		string nombre;
		int edad;
		string ciudad;
	};
	
	Persona gente[10]; 
	
	ofstream escribirFichero;
	escribirFichero.open("gente.dat");
	
	if(!escribirFichero.is_open()){
		cout << "Error al crear el archivo";
	}
	else{
		for(int i = 0; i < 10; i++){
			Persona persona = Persona();
			cout << "Nombre " << i + 1 << ": ";  
			getline(cin, persona.nombre);
			cout << "Edad " << i + 1 << ": ";
			cin >> persona.edad;
			cout << "Ciudad " << i + 1 << ": ";
			cin >> persona.ciudad;
			gente[i] = persona;
			escribirFichero << gente[i].nombre << endl << gente[i].edad << endl << gente[i].ciudad << endl << endl;
			cin.ignore();
		}
		escribirFichero.close();
		for(int i = 0; i < 10; i++){
			cout << gente[i].nombre << " " << gente[i].edad << " " << gente[i].ciudad << endl;
		}
		cout << endl;
	}
	
	ifstream leerFichero;
	string linea;
	leerFichero.open("gente.dat");
	if(!leerFichero.is_open()){
		cout << "No se pudo abrir el fichero";
	}
	else{
		for(int i = 0; i < 10; i++){
			getline(leerFichero, linea);
			gente[i].nombre = linea;
			getline(leerFichero, linea);
			gente[i].edad = stoi(linea);
			getline(leerFichero, linea);
			gente[i].ciudad = linea;
			getline(leerFichero, linea);	
		}
		leerFichero.close();
		for(int i = 0; i < 10; i++){
			cout << gente[i].nombre << " " << gente[i].edad << " " << gente[i].ciudad << endl;
		}
	}
	return 0;
}
