#include <iostream>
#include <ios>
#include <limits>
using namespace std;

bool atmWorking = true;
int balance = 1000;
int option;

int main(){
	
	while(atmWorking){
		// print menu
		system("CLS"); // clears console
		cout << "Welcome to the ATM service" << endl;
		cout << "1. Check balance" << endl;
		cout << "2. Deposit" << endl;
		cout << "3. Withdraw" << endl;
		cout << "4. Exit" << endl;
		cout << "\nChoose the option that you require: ";
		
		// receive menu option, delete newline symbol
		cin >> option;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		
		//check the option required
		switch(option){
			case 1: // check balance
				system("CLS");
				cout << "Your balance is : $" << balance << "\n" << endl;
				cout << "Press Enter to continue" << endl;
				getchar(); // "Press Enter to continue" function
				break;
			case 2: // receive deposit
				int deposit;
				system("CLS");
				cout << "Write how much you want to deposit: ";
				cin >> deposit;
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				balance += deposit;
				cout << "\nYou deposited $" << deposit << ".\nYour balance is now $" <<  balance << ".\n" << endl;
				cout << "Press Enter to continue" << endl;
				getchar();
				break;
			case 3: // withdraw cash
				int withdraw;
				system("CLS");
				cout << "Write how much you want to withdraw: ";
				cin >> withdraw;
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				if(withdraw <= balance && withdraw > 0){
					balance -= withdraw;
					cout << "\nYou withdrew $" << withdraw << ".\nYour balance is now $" <<  balance << ".\n" << endl;
				}
				else{
					cout << "You don't have enough money" << endl;
				}
				cout << "Press Enter to continue" << endl;
				getchar();
				break;
			case 4: // close atm program
				cout << "Thank you for using our service." << endl;
				atmWorking = false;
				break;
			default: // option does not exist
				system("CLS");
				cout << "Not a valid option." << endl;
				cout << "Press Enter to continue" << endl;
				getchar();
				break;
				
		}
		
	
	}
	
}
