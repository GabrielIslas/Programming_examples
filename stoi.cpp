#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int cols = 2; //el numero de columnas fijas
	
string** libros; //inicializando la matriz con punteros

int size;

void escribirArchivo();

void leerArchivo();

void encontrarLibro(int posicion);

int main(){
	
	cout<<"Cuantos libros desea ingresar?";
	
	string entrada; //declaro la variable de entrada
	
	getline(cin, entrada); //se asigna el valor ingresado
	
	size = stoi(entrada); //transformar la entrada "string" a "entero"
	
	libros = new string*[size]; //dasignar el numero de filas segun el usuario
	
	
	cout<<"Escriba la informacion de los libros: \n";
	string titulo,autor;
	
	for(int i=0; i<size; i++){
		libros[i] = new string[cols];
		cout<<"\n****** Libro"<<i+1<<"********\n";
		cout<<"Titulo: ";
		getline(cin,titulo);
		cout<<"Autores: ";
		getline(cin,autor); //se asigna el valor 
		libros[i][0] = titulo;
		libros[i][1] = autor;
	}
	
	/*escribir libros en un archivo*/
	escribirArchivo();
	
	/*leer libros en un archivo*/
	leerArchivo();
	
	/* encontrar libro en base a posicion con punteros */
	int posicion;
	cout << "Escribe que libro quieres: ";
	cin >> posicion;
	encontrarLibro(posicion);
	
	

	system("pause");
	return 0;
}

void escribirArchivo(){
	ofstream archivoLibros;
	archivoLibros.open("libros.txt");
	if(!archivoLibros.is_open()){
		cout << "Error al crear el archivo";
	}
	else{
		for(int i = 0; i < size; i++){
			archivoLibros << libros[i][0] << " " << libros[i][1] << endl;
		}
		archivoLibros.close();
	}
	
}

void leerArchivo(){
	string linea;
	ifstream archivoLibros;
	archivoLibros.open("libros.txt");
	if(!archivoLibros.is_open()){
		cout << "Error al abrir el archivo";
	}
	else{
		while(getline(archivoLibros, linea)){
			cout << linea << "\n";
		}
		archivoLibros.close();
	}
}

void encontrarLibro(int posicion){
	string *direccionLibro;
	direccionLibro = libros[posicion];
	cout << "El libro seleccionado es " + *(direccionLibro) + " de " + *(direccionLibro + 1) + "\n"; 
}

/*
group assignment: from the previus code, using pointers, you must ask the user which book the print
pointing the data of direction declared
*/

