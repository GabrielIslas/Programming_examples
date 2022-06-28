//incluir librerias



#include <iostream>
#include <iomanip>



using namespace std;



int main(){







int rows;
cout<<"How many rows do you want? \n"; cin>>rows; //solicitar e identificar #rows
cout<<endl;




for (int i = 0; i<rows; i++)
{
	for (int j = 0; j <(rows-i); j++) //declarando la naturalidad del numero
	{
		cout<<" ";
	
	}
	
	int n=1;
	
	for (int k = 0; k<=i; k++) //declarando la naturalidad de las lineas o columnas
	{
		cout<<" "<<n;
		n=n*(i-k)/(k+1);
	}
	cout<<"\n";
}









}
