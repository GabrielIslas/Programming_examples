/* FILE MANAGMENT

Crear un programa que vaya leyendo las frases que el usuario teclea y las guarde en un fichero de texto llamado 
"User_Registrer.txt". Terminará el programa cuadno la frase introducida sea "fin"(esta frase no deberá guardarse en 
el fichero).

fichero ----> archivo (.tx.t, .dll, ...)
directorio ----> carpeta (documentos, videos, imagenes, ...) */

#include <stdio.h>
#include <string.h>

int main(){
	FILE* ptFichero; //creando un apuntador para el fichero
	char fin[]="fin"; //palabra de salida
	char frase [60]; //crear un array para los usuarios
	
	ptFichero = fopen("User_Register.txt", "wt"); //creando el archivo de texto
	printf("PROGRAMA PARA ESCRIBIR USUARIOS. \n Cuando quiera salir, escriba la palabra'fin'. \n\n");
	
	do{
		puts("\n Escriba una Frase: "); //Imprime esta linea en la terminal "puts"
		gets(frase); //guarda la frase esrita en el array
		if(strcmp(frase,fin) == 0){ //se compara el array de frase con la palabra fin para terminar el programa
			break;
		}
		fprintf(ptFichero, "%s \n", frase);
	}while(strcmp(frase, fin) != 0); 
	
	fclose(ptFichero);
	
	return 0;
}
