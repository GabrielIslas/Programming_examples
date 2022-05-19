#include <iostream>
using namespace std;

int main(){
	cout << "Input time value: ";
	
	int time;
	string timePrint;
	cin >> time;
	
	if(time > 0 && time < 12){
		cout << "\nGood morning";
	}
	else if(time == 12){
		cout << "\nNoon";
	}
	else if(time > 12 && time <= 18){
		cout << "\nGood evening";
	}
	else if(time > 18 && time <= 23){
		cout << "\nGood night";
	} 
	else if(time == 0 || time == 24){
		cout << "\nMidnight";
	}
	else{
		cout << "24 hr format please";
	}
	
	/*
	if(time >= 0 && time <= 12){
		timePrint = (time == 12) ? "\nNoon" : ((time == 0) ? "\nMidnight" : "\nGood Morning");
		cout << timePrint;
	}
	*/
}
