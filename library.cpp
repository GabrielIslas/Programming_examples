#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <windows.h>


using namespace std;

int menu = true;

int cantidadLibros;

string** libros;

int columnas = 3;

void escribirLibros();

void leerArchivo();

void leerArray();

void buscarArchivo();

void buscarArchivoTitulo();

void buscarArchivoAutor();

void buscarArchivoAnio();

void buscarArchivoPosicion();

void buscarArray();

void buscarArrayTitulo();

void buscarArrayAutor();

void buscarArrayAnio();

void buscarArrayPosicion();

int main(){
	while(menu){
		system("cls");
		int opcion;
		cout << "Menu" << endl;
		cout << "1. Escribir libros" << endl;
		cout << "2. Leer archivo" << endl;
		cout << "3. Leer array de libros" << endl;
		cout << "4. Buscar libros en archivo" << endl;
		cout << "5. Buscar libros en array" << endl;	
		cout << "6. Salir" << endl;
		cin >> opcion;
		
		switch(opcion){
			case 1:
				escribirLibros();
				break;
			case 2:
				leerArchivo();
				break;
			case 3:
				leerArray();
				break;
			case 4:
				buscarArchivo();
				break;
			case 5:
				buscarArray();
				break;
			case 6:
				menu = false;
				system("cls");
				cout << "Gracias por usar el programa" << endl;
				break;
			default:
				system("cls");
				cout << "Elige una opcion valida" << endl;
				system("pause");
				break;
		}
	}
}

void escribirLibros(){
	//Definir arreglo de libros
	system("cls");
	string autor, titulo, anio;
	cout << "Escriba cuantos libros desea ingresar: ";
	cin >> cantidadLibros;
	libros = new string*[cantidadLibros];
	cin.ignore();
	//Recibir libros
	for(int i = 0; i < cantidadLibros; i++){
		system("cls");
		libros[i] = new string[columnas];
		cout << "Titulo " << i + 1 << ": ";
		getline(cin, titulo);
		cout << "Autor " << i + 1 << ": ";
		getline(cin, autor);
		cout << "Año " << i + 1 << ": ";
		getline(cin, anio);
		libros[i][0] = titulo;
		libros[i][1] = autor;
		libros[i][2] = anio;
	}
	//Escribir libros en archivo
	ofstream ficheroLibros;
	ficheroLibros.open("libros.txt");
	if(!ficheroLibros.is_open()){
		cout << "Error al crear el archivo";
	}
	else{
		for(int i = 0; i < cantidadLibros; i++){
			ficheroLibros << libros[i][0] << "|" << libros[i][1] << "|" << libros[i][2] << endl;
		}
		ficheroLibros.close();
	}
}

void leerArchivo(){
	system("cls");
	
	ifstream leerFichero;
	leerFichero.open("libros.txt");
	if(!leerFichero.is_open()){
		cout << "Error al abrir el archivo" << endl;
	}
	else{
		string linea, segmento;
		for(int i = 0; i < cantidadLibros; i++){
			getline(leerFichero, linea);
			stringstream lineaStream(linea);
			vector<string> segmentos;
			while(getline(lineaStream, segmento, '|')){
				segmentos.push_back(segmento);
			}
			cout << "Titulo " << i + 1 << ": " << segmentos.at(0) << endl;
			cout << "Autor " << i + 1 << ": " << segmentos.at(1) << endl;
			cout << "Año " << i + 1 << ": " << segmentos.at(2) << endl << endl;
		}
	}
	system("pause");
}

void leerArray(){
	system("cls");
	for(int i = 0; i < cantidadLibros; i++){
		cout << "Titulo " << i << ": " << libros[i][0] << endl;
		cout << "Autor " << i << ": " << libros[i][1] << endl;
		cout << "Año " << i << ": " << libros[i][2] << endl << endl;
	}
	system("pause");
}

void buscarArchivo(){
	int opcionBusquedaArchivo;
	system("cls");
	cout << "Como quiere buscar el libro?" << endl;
	cout << "1. Por titulo" << endl;
	cout << "2. Por autor" << endl;
	cout << "3. Por año" << endl;
	cout << "4. Por posicion" << endl;
	cin >> opcionBusquedaArchivo;
	switch(opcionBusquedaArchivo){
		case 1:
			buscarArchivoTitulo();
			break;
		case 2:
			buscarArchivoAutor();
			break;
		case 3:
			buscarArchivoAnio();
			break;
		case 4:
			buscarArchivoPosicion();
			break;
		default:
			cout << "Elija una opcion valida" << endl;
			break;
	}
	system("pause");
}

void buscarArchivoTitulo(){
	string titulo;
	cin.ignore();
	system("cls");
	cout << "Escribe el titulo del libro: ";
	getline(cin, titulo);
	
	ifstream buscarFicheroTitulo;
	buscarFicheroTitulo.open("libros.txt");
	if(!buscarFicheroTitulo.is_open()){
		cout << "Error al abrir al archivo" << endl;
	}
	else{
		string linea, segmento;
		bool encontrado = false;
		for(int i = 0; i < cantidadLibros; i++){
			getline(buscarFicheroTitulo, linea);
			stringstream lineaStream(linea);
			vector<string> segmentos;
			while(getline(lineaStream, segmento, '|')){
				segmentos.push_back(segmento);
			}
			if(titulo == segmentos.at(0)){
				if(!encontrado){
					cout << "Libros que coinciden con la busqueda:" << endl;
					encontrado = true;
				}
				cout << "Titulo " << i + 1 << ": " << segmentos.at(0) << endl;
				cout << "Autor " << i + 1 << ": " << segmentos.at(1) << endl;
				cout << "Año " << i + 1 << ": " << segmentos.at(2) << endl << endl;
			}
		}
		if(!encontrado){
			cout << "No se encontro ningun libro que coincida" << endl;
		}
	}
}

void buscarArchivoAutor(){
	string autor;
	cin.ignore();
	system("cls");
	cout << "Escribe el autor del libro: ";
	getline(cin, autor);
	
	ifstream buscarFicheroAutor;
	buscarFicheroAutor.open("libros.txt");
	if(!buscarFicheroAutor.is_open()){
		cout << "Error al abrir al archivo" << endl;
	}
	else{
		string linea, segmento;
		bool encontrado = false;
		for(int i = 0; i < cantidadLibros; i++){
			getline(buscarFicheroAutor, linea);
			stringstream lineaStream(linea);
			vector<string> segmentos;
			while(getline(lineaStream, segmento, '|')){
				segmentos.push_back(segmento);
			}
			if(autor == segmentos.at(1)){
					if(!encontrado){
						cout << "Libros que coinciden con la busqueda:" << endl;
						encontrado = true;
					}
					cout << "Titulo " << i + 1 << ": " << segmentos.at(0) << endl;
					cout << "Autor " << i + 1 << ": " << segmentos.at(1) << endl;
					cout << "Año " << i + 1 << ": " << segmentos.at(2) << endl << endl;
			}
		}
		if(!encontrado){
			cout << "No se encontro ningun libro que coincida" << endl;
		}
	}
}

void buscarArchivoAnio(){
	string anio;
	cin.ignore();
	system("cls");
	cout << "Escribe el año del libro: ";
	getline(cin, anio);
	
	ifstream buscarFicheroAnio;
	buscarFicheroAnio.open("libros.txt");
	if(!buscarFicheroAnio.is_open()){
		cout << "Error al abrir al archivo" << endl;
	}
	else{
		string linea, segmento;
		bool encontrado = false;
		for(int i = 0; i < cantidadLibros; i++){
			getline(buscarFicheroAnio, linea);
			stringstream lineaStream(linea);
			vector<string> segmentos;
			while(getline(lineaStream, segmento, '|')){
				segmentos.push_back(segmento);
			}
			if(anio == segmentos.at(2)){
					if(!encontrado){
						cout << "Libros que coinciden con la busqueda:" << endl;
						encontrado = true;
					}
					cout << "Titulo " << i + 1 << ": " << segmentos.at(0) << endl;
					cout << "Autor " << i + 1 << ": " << segmentos.at(1) << endl;
					cout << "Año " << i + 1 << ": " << segmentos.at(2) << endl << endl;
			}
		}
		if(!encontrado){
			cout << "No se encontro ningun libro que coincida" << endl;
		}
	}
}

void buscarArchivoPosicion(){
	cin.ignore();
	system("cls");
	int posicion;
	cout << "Escribe que libro quieres: ";
	cin >> posicion;
	ifstream buscarFicheroPosicion;
	buscarFicheroPosicion.open("libros.txt");
	if(!buscarFicheroPosicion.is_open()){
		cout << "Error al abrir el archivo" << endl;
	}
	else{
		string linea;
		for(int i = 0; i < posicion; i++){
			getline(buscarFicheroPosicion, linea);
		}
		stringstream lineaStream(linea);
		vector<string> segmentos;
		string segmento;
		while(getline(lineaStream, segmento, '|')){
			segmentos.push_back(segmento);
		}
		cout << "Titulo " << ": " << segmentos.at(0) << endl;
		cout << "Autor " <<  ": " << segmentos.at(1) << endl;
		cout << "Año " << ": " << segmentos.at(2) << endl << endl;
	}
}

void buscarArray(){
	int opcionBusquedaArchivo;
	system("cls");
	cout << "Como quiere buscar el libro?" << endl;
	cout << "1. Por titulo" << endl;
	cout << "2. Por autor" << endl;
	cout << "3. Por año" << endl;
	cout << "4. Por posicion" << endl;
	cin >> opcionBusquedaArchivo;
	switch(opcionBusquedaArchivo){
		case 1:
			buscarArrayTitulo();
			break;
		case 2:
			buscarArrayAutor();
			break;
		case 3:
			buscarArrayAnio();
			break;
		case 4:
			buscarArrayPosicion();
			break;
		default:
			cout << "Elija una opcion valida" << endl;
			break;
	}
	system("pause");
}

void buscarArrayTitulo(){
	string titulo;
	cin.ignore();
	system("cls");
	cout << "Escribe el titulo del libro: ";
	getline(cin, titulo);
	
	bool encontrado = false;
	for(int i = 0; i < cantidadLibros; i++){
		if(libros[i][0] == titulo){
			if(!encontrado){
				cout << "Libros que coinciden con la busqueda:" << endl;
				encontrado = true;
			}
			cout << "Titulo " << ": " << libros[i][0] << endl;
			cout << "Autor " <<  ": " << libros[i][1] << endl;
			cout << "Año " << ": " << libros[i][2] << endl << endl;
		}
	}
	if(!encontrado){
		cout << "No se encontro ningun libro que coincida" << endl;
	}
}

void buscarArrayAutor(){
	string autor;
	cin.ignore();
	system("cls");
	cout << "Escribe el autor del libro: ";
	getline(cin, autor);
	
	bool encontrado = false;
	for(int i = 0; i < cantidadLibros; i++){
		if(libros[i][1] == autor){
			if(!encontrado){
				cout << "Libros que coinciden con la busqueda:" << endl;
				encontrado = true;
			}
			cout << "Titulo " << ": " << libros[i][0] << endl;
			cout << "Autor " <<  ": " << libros[i][1] << endl;
			cout << "Año " << ": " << libros[i][2] << endl << endl;
		}
	}
	if(!encontrado){
		cout << "No se encontro ningun libro que coincida" << endl;
	}
}

void buscarArrayAnio(){
	string anio;
	cin.ignore();
	system("cls");
	cout << "Escribe el año del libro: ";
	getline(cin, anio);
	
	bool encontrado = false;
	for(int i = 0; i < cantidadLibros; i++){
		if(libros[i][2] == anio){
			if(!encontrado){
				cout << "Libros que coinciden con la busqueda:" << endl;
				encontrado = true;
			}
			cout << "Titulo " << ": " << libros[i][0] << endl;
			cout << "Autor " <<  ": " << libros[i][1] << endl;
			cout << "Año " << ": " << libros[i][2] << endl << endl;
		}
	}
	if(!encontrado){
		cout << "No se encontro ningun libro que coincida" << endl;
	}
}

void buscarArrayPosicion(){
	cin.ignore();
	system("cls");
	int posicion;
	cout << "Escribe que libro quieres: ";
	cin >> posicion;
	string *direccionLibro;
	direccionLibro = libros[posicion - 1];
	cout << "Titulo " << ": " << *(direccionLibro) << endl;
	cout << "Autor " <<  ": " << *(direccionLibro + 1) << endl;
	cout << "Año " << ": " << *(direccionLibro + 2) << endl << endl;
}


