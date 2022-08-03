#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <sstream> // Permite separar strings en secciones facilmente
#include <string>

using namespace std; 

// Variables
struct Item{
	string name;
	double price; 
	int quantity = 1;
};
bool menu = true;
vector<Item> Items; 
double sales=0;

// Funciones
void addItem ();
void writeItemsFromVector();
void seeItems();
void initializeItems();
void removeItem();
void cotization();
void sell();
void cashout();

int main() {
	initializeItems();
	double startingMoney;
	cout<<"Write your starting money: $";
	cin>>startingMoney;
	sales += startingMoney;
	while (menu)
	{
		system("cls");
		int option;
		cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>WELCOME!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl<<endl;
	    cout << "1. Cotization" << endl;
	    cout << "2. Cashout" << endl;
	    cout << "3. Sell" << endl;
	    cout << "4. Add item" << endl;
	    cout << "5. Remove item" << endl;
	    cout << "6. See items" << endl;
	    cout << "7. Exit" << endl;
	    cout << "Type the number option you want to perform: "<<endl;
		cin >> option;   
	    
	    switch (option)
	    {
	    	case 1:
	    		cotization();
	    		break;
	    	case 2:
	    		cashout();
				break;
			case 3: 
				sell();
				break; 
			case 4: 
				addItem();
				break; 
			case 5:
				removeItem();
				break;
			case 6: 
				seeItems();
				break; 
			case 7:
				system("cls");
				cout<<"Thank you for buying with us";
				menu = false;
				break;	
		}
	}
}

void addItem (){
	//Agregando al vector
	system("cls");
	Item item = Item();
	cout<<"Write the name of the item: "<<endl; 
	cin.ignore();
	getline(cin, item.name);
	
	cout<<"Write the price: "<<endl;
	cin>>item.price;
		
	Items.push_back(item);
	
	//Agregando al archivo
	writeItemsFromVector();
	cout<<"Item added"<<endl;
	system("pause");
}

void writeItemsFromVector(){
	ofstream writeItem;
	writeItem.open("items.txt");
	if(!writeItem.is_open()){
		cout<<"Error"<<endl;
	}
	else{
		for(int i=0; i<Items.size(); i++){
			writeItem<<Items[i].name<<"|"<<Items[i].price<<endl;		
		}	
		writeItem.close();
	}	
}

void seeItems(){
	system("cls");
	if (Items.empty()){
		cout<<"No items registered"<<endl;
	}
	else {
		for(int i=0; i<Items.size();i++){
			cout<<"......................................................................"<<endl;
			cout<<"Item "<<i+1<<": "<<Items[i].name<<endl;
			cout<<"Price: "<<Items[i].price<<endl;
			cout<<"......................................................................"<<endl<<endl;
		}
	}
	system("pause");
}

void initializeItems(){
	ifstream readItems;
	readItems.open("items.txt");
	if(!readItems.is_open()){
		cout<<"Error"<<endl;
	}
	else{
		for(string line; getline(readItems,line);){
			stringstream linestream(line);
			string segment;
			vector<string> segments;
			while(getline(linestream, segment, '|')){
				segments.push_back(segment);	
			}
			Item item = Item();
			item.name = segments.at(0);
			item.price = stod(segments.at(1));
			Items.push_back(item);
		}
		readItems.close();
	}
}

void removeItem(){
	system ("cls");
	string remove;
	bool found=false;
	cout<<"Which item do you want to remove? ";
	cin.ignore();
	getline(cin,remove);
	for(vector<Item>::iterator it = Items.begin();it != Items.end();it++){
		if((*it).name==remove){
			Items.erase(it);
			writeItemsFromVector();
			cout<<"item removed"<<endl;
			found = true;
			break;
		}
    }
    if(!found){
    	cout<<"Item not found"<<endl;
	}
	system("pause");
	
}

void cotization(){
	system("cls");
	vector<Item> buying;
	int option;
	bool menu = true;
	while(menu){
		system("cls");
		cout<<"***********************************************"<<endl;
		cout<<"* Choose an option                            *"<<endl;
		cout<<"*  1. Add item to shopping cart               *"<<endl;
		cout<<"*  2. Remove item from shopping cart          *"<< endl;
		cout<<"*  3. Total price                             *"<<endl;
		cout<<"*  4. Exit                                    *"<<endl;
		cout<<"***********************************************"<<endl;
		cin>>option;
		switch(option){
			case 1:
				{
					int product;
					int quantity;
					Item buyingItem;
					cout<<"What do you want to buy?"<<endl;
					for(int i=0; i<Items.size();i++){
						cout<<"Item "<<i+1<<": "<<Items[i].name<<endl;
						cout<<"Price: "<<Items[i].price<<endl<<endl;
					} 
					cin>>product;
					buyingItem = Items[product-1];
					cout<<"How many do you want?"<<endl;
					cin>>quantity;
					buyingItem.quantity = quantity;
					buying.push_back(buyingItem);
					cout << "Item added" << endl;
					system("pause");
					break;
				}
			case 2:
				{
					string remove;
					bool found = false;
					if(buying.empty()){
						cout << "You have no items" << endl;
						system("pause");
						break;
					}
					cout<<"What do you want to remove?"<<endl;
					cin.ignore();
					getline(cin, remove);
					for(vector<Item>::iterator it = buying.begin();it != buying.end();it++){
						if((*it).name==remove){
							int amountToRemove;
							cout<<"How many do you want to remove?"<<endl;
							cin>>amountToRemove;
							if((*it).quantity<=amountToRemove){
								Items.erase(it);
							}
							else if ((*it).quantity>amountToRemove) {
								(*it).quantity-=amountToRemove;
							}
							cout<<"item removed"<<endl;
							found = true;
							break;
						}
				    }
				    if(!found){
				    	cout<<"Item not found"<<endl;
					}
					system("pause");
					break;
				}
			case 3:
				{
					if(buying.empty()){
						cout<<"No items added yet"<<endl;
					}else{
						double subtotal=0;
						for(int i=0; i<buying.size();i++){
							subtotal += buying[i].price*buying[i].quantity;
						}
						double iva = subtotal*0.16;
						double total = subtotal + iva;
						
						cout<<"Subtotal: $"<<subtotal<<endl;
						cout<<"IVA: $"<<iva<<endl;
						cout<<"Total: $"<<total<<endl;
					}
					system("pause");
					break;
				}
			case 4:
				menu=false;
				break;		
		}
	}	
}

void sell(){
	system("cls");
	vector<Item> buying;
	int option1;
	bool menu = true;
	while(menu){
		system("cls");
		cout<<"***********************************************"<<endl;
		cout<<"* Choose an option                            *"<<endl;
		cout<<"*  1. Add item to shopping cart               *"<<endl;
		cout<<"*  2. Remove item from shopping cart          *"<< endl;
		cout<<"*  3. Total price                             *"<<endl;
		cout<<"*  4. Buy                                     *"<<endl;
		cout<<"*  5. Exit                                    *"<<endl;
		cout<<"***********************************************"<<endl;
		cin>>option1;
		switch(option1){
			case 1:
				{
					int product;
					int quantity;
					Item buyingItem;
					cout<<"What do you want to buy?"<<endl;
					for(int i=0; i<Items.size();i++){
						cout<<"Item "<<i+1<<": "<<Items[i].name<<endl;
						cout<<"Price: "<<Items[i].price<<endl<<endl;
					} 
					cin>>product;
					buyingItem = Items[product-1];
					cout<<"How many do you want?"<<endl;
					cin>>quantity;
					buyingItem.quantity = quantity;
					buying.push_back(buyingItem);
					cout << "Item added" << endl;
					system("pause");
					break;
				}
			case 2:
				{
					string remove;
					bool found = false;
					if(buying.empty()){
						cout << "You have no items" << endl;
						system("pause");
						break;
					}
					cout<<"What do you want to remove?"<<endl;
					cin.ignore();
					getline(cin, remove);
					for(vector<Item>::iterator it = buying.begin();it != buying.end();it++){
						if((*it).name==remove){
							int amountToRemove;
							cout<<"How many do you want to remove?"<<endl;
							cin>>amountToRemove;
							if((*it).quantity<=amountToRemove){
								Items.erase(it);
							}
							else if ((*it).quantity>amountToRemove) {
								(*it).quantity-=amountToRemove;
							}
							cout<<"item removed"<<endl;
							found = true;
							break;
						}
				    }
				    if(!found){
				    	cout<<"Item not found"<<endl;
					}
					system("pause");
					break;
				}
			case 3:
				{
					if(buying.empty()){
						cout<<"No items added yet"<<endl;
					}else{
						double subtotal=0;
						for(int i=0; i<buying.size();i++){
							subtotal += buying[i].price*buying[i].quantity;
						}
						double iva = subtotal*0.16;
						double total = subtotal + iva;
						
						cout<<"Subtotal: $"<<subtotal<<endl;
						cout<<"IVA: $"<<iva<<endl;
						cout<<"Total: $"<<total<<endl;
					}
					system("pause");
					break;
				}
			case 4:
				{
					system("cls");
					if(buying.empty()){
						cout<<"No items added yet"<<endl;
					}
					else{
						int option2;
						string cardNumber;
						string accountNumber;
						cout<<"-----------------------------------"<<endl;
						cout<<"| Choose your payment method:     |"<<endl;
						cout<<"|  1. Cash                        |"<<endl;
						cout<<"|  2. Credit card                 |"<< endl;
						cout<<"|  3. Debit card                  |"<<endl;
						cout<<"-----------------------------------"<<endl;
						cin>>option2;
						if(option2==2||option2==3){
							cout<<"Insert your card number"<<endl;
							cin.ignore();
							getline(cin,cardNumber);
							accountNumber = cardNumber.substr(cardNumber.size()-4);
							cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
							cout<<"x                        x"<<endl;
							cout<<"x    Enter your NIP      x"<<endl;
							cout<<"x                        x"<<endl;
							cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
							
							getchar();
						}
						double subtotal=0;
						for(int i=0; i<buying.size();i++){
							subtotal += buying[i].price*buying[i].quantity;
						}
						double iva = subtotal*0.16;
						double total = subtotal + iva;
						
						ofstream ticket;
						ticket.open("ticket.txt");
						if(!ticket.is_open()){
							cout<<"Error"<<endl;
						}
						else{
							ticket<<"**************** Abarrotes GK ****************"<<endl;
							ticket<<"Name, Coyoacan, MEX, CDMX"<<endl;
							ticket<<"RFC: GKIC14071210, Av. Francisco Sosa"<<endl;
							ticket<<"Del. Cuauhtemoc C.P 97302"<<endl<<endl;
							ticket<<"Components and suggestions 01 800 314 23"<<endl<<endl;
							for(int i=0; i<buying.size(); i++){
								ticket<<buying[i].quantity<<" x "<<buying[i].name<<"  $"<<buying[i].price * buying[i].quantity<<endl;
							}	
							ticket<<"Subtotal:$ "<<subtotal<<endl;
							ticket<<"IVA:$ "<<iva<<endl;
							ticket<<"Total:$ "<<total<<endl<<endl;
							ticket<<"Payment method: ";
							switch(option2){
								case 1:{
									ticket<<"Cash"<<endl;
									sales += total;
									break;
								}
								
								case 2:{
									ticket<<"Credit card"<<endl;
									ticket<<"Account: **** "<<accountNumber<<endl;
									break;
								}
								case 3:{
									ticket<<"Debit card"<<endl;
									ticket<<"Account: **** "<<accountNumber<<endl;
									
									break;
								}
							}
							ticket<<"Check our online store at abarrotesGK.com.mx"<<endl;
							ticket.close();
							
							cout<<"Thank you for your purchase"<<endl;
						}
						
						
					}
					
					
					system("pause");
				}
				break;
			case 5:
				menu=false;
				break;		
		}
	}		
}

void cashout(){
	system("cls");
	double cash;
	cout<<".............................................................."<<endl;
	cout<<"...    Write the amount of money in the cash register      ..."<<endl;
	cout<<".............................................................."<<endl;
	cin>>cash;
	if(cash==sales){
		cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
		cout<<"^^         The amount of money is correct       ^^"<<endl;
		cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
	}
	else{
		cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
		cout<<"XXXX    The amount of money is incorrect     XXXX"<<endl;
		cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
	}
	system("pause");
}	
