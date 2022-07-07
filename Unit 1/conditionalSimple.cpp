#include <iostream>
using namespace std;

int main(){
	int time = 12;
	if(time < 18){
		cout << "Good day.";
		if(time == 12){
			cout << "It's noon";
		}
	}
	else{
		cout << "Good evening.";
	}
}
