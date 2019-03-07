//This is Project 4_1
//By Anna Collins


#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


//*****************************************************************
//*This is a program that will ask for a users password and       *
//*verify it with the following criteria                          *
//*Should be 6 characters long                                    *
//*Should have at least one uppercase and one lowercase           *
//*Should have at least 1 digit                                   *
//*****************************************************************

bool validateCase(char *, bool&, bool&);
bool validateDigit(char *, bool&);
bool validateLength(char *, bool&);
void correctPass(bool, bool, bool, bool);

int main() {

	//Variables 
	const int SIZE = 100;
	char password[SIZE];
	bool aDigit = false;
	bool aLower = false;
	bool aUpper = false;
	bool aLength = false;

	//Asking the user for input their password 
	cout << "This program will check your password, please enter your password: ";
	cin >> password;
	cout << endl;

	//Calling the functions 
	validateLength(password, aLength);
	validateDigit(password, aDigit);
	validateCase(password, aLower, aUpper);
	correctPass(aDigit, aLower, aUpper, aLength);
	system("pause");
}
//Function to test the length
bool validateLength(char* pass, bool& aLength) {
	int length;
	length = strlen(pass);
	if (length < 6) {
		cout << "The password needs to be at least 6 charcters long!" << endl;
			return false;
	}
	else
		aLength = true;	
}

//Function to test to make sure there is at least one digit
bool validateDigit(char* pass, bool& aDigit) {
	
	for (int i = 0; pass[i]; i++) {
		if (isdigit(pass[i])) {
			aDigit = true;
			return true;
		}	
	}
	if (aDigit == false) {
		cout << "Your password is lacking at least 1 digit!" << endl;
	}
}

//Function to test to make sure there is at least one uppercase and one lowercase letter
bool validateCase(char* pass, bool& aLower, bool& aUpper) {
	
	for (int i = 0; pass[i]; i++) {
		if (islower(pass[i])) {
			aLower = true;
		}
		if (isupper(pass[i])) {
			aUpper = true;
		}
	}

		if (aLower == false) {
			cout << "Your password is missing a lowercase letter!" << endl;
		}
		if (aUpper == false) {
			cout << "Your password is missing an uppercase letter!" << endl;
		}	
	return true;
}

//Function to call out correct if everything comes out right
void correctPass(bool aDigit, bool aLower, bool aUpper, bool aLength) {
	if (aDigit == true && aLower == true && aUpper == true && aLength == true) {
		cout << "Thank you, your password meets the requirements!" << endl;
	}
}
