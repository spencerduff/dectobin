#include <iostream>

using namespace std;

void dectobin(unsigned long long dec);
bool checkZero(unsigned long long dec, unsigned long long &remainder);

int main(){
	unsigned long long a = 0;
	char b = '/0';

	while (true){

		cout << "Enter a base10 number to convert to base2: ";
		cin >> a;

		dectobin(a); // 110
		cout << endl;

		cout << "Quit? (Y/N): ";
		cin >> b;
		if (b == 'Y' || b == 'y') return 0;

	}
	return 0;
}

void dectobin(unsigned long long dec){
	unsigned long long remainder = 0;
	if (dec == 0){
		return;
	}
	if (dec == 1){
		cout << '1';
		return;
	}

	if (checkZero(dec, remainder) == false){
		dectobin(dec - remainder);
		cout << '1';
	}
	else{
		dectobin(dec >> 1);
		cout << '0';
	}

}

bool checkZero(unsigned long long dec, unsigned long long &remainder){
	unsigned long long a = dec >> 1;
	unsigned long long b = a << 1;

	if (dec != b){
		remainder = dec - a;
		return false;
	}
	else return true;
}
