//============================================================================
// Name        : airlinedb.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//============================================================================
// Name        : airlinedb.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "OrderedLinkedList.h"
#include <string>
#include <sstream>

using namespace std;

int main(){

	cout << "***Sean Hardin's airline database application***"<< '\n';//introduction
	//node<Passenger> *flightNo;//creates the pointer for the array
	//phonebook = new contact[151450];//25 spaces over the initial number of entries
	//since the array initializes them all at once.
	string temp;//temporary string to read the text file
	string a,b,c;//temporary variables to hold the first name, last name, and number respectively

//	while (getline(readIn, temp)){//runs until getline finds no line
//		stringstream temp2;//initialize inside so data resets each loop
//		temp2<<temp;//converting string into stream, so far this was the only way i found to
//		//read the file with a loop without losing data or hardcoding the limit
//		temp2>>a>>b>>c;//stream values as described in initialization
//		a=a+' '+b;
//		phonebook[count].setName(a);//combines first and last name and sets the phonebook entry with it.
//		phonebook[count].setNumber(c);//sets the number
//		count++;//increment count for the next entry
//	}

	cout << "Please choose an operation:" << '\n';//fluff for pseudo UI
	char userInput;//char to read command from user

	while (userInput!='Q' && userInput!= 'q'){//runs until user chooses to quit
		cout<<"A(Add)|S(Search)|D(Delete)|L(List)|Q(Quit)";//list of commands
		string complianceCheckString;//to use sstream/check length
		stringstream complianceCheck;//to copy user input into string and char
		getline(cin, complianceCheckString);//get user input
		complianceCheck << complianceCheckString;
		complianceCheck>>userInput;//take whatever the user types and sets it in the character
		if (complianceCheckString.length()>1) {//if user inputs more than a char
			userInput = 'f';//FOR FAILURE TO COMPLY
		}

		cout << "Please enter the flight number:";

		switch (userInput){//switch statement looks cleaner than nested if loops.
			case 'A'://capital and lowercase letters for better usability, wasn't sure how to force capitals
			case 'a':
				//addEntry(phonebook, count);//friend function that runs code to add an entry
				break;
			case 'S':
			case 's':
				//searchEntry(phonebook, count);//friend function to search
				break;
			case 'D':
			case 'd':
				//deleteEntry(phonebook, count);//friend function to delete
				break;
			case 'L':
			case 'l':
				//listEntries(phonebook, count);//friend function to list entries
				break;
			case 'Q'://doesn't run any extra code on quitting, included just to avoid the default case
			case 'q'://leaving a bad message before ending program
				break;
			default://if user tries to type anything other than the listed commands
				cout << "Please enter only the letter for the option you want." << '\n';
		}
		if (userInput != 'q' && userInput != 'Q')//reset char so a \0 doesn't run previous operation again
			userInput = 'f';
	}
	cout << "Thank you for using my phonebook!";//mostly a confirmation that the program ended successfully
	return 0;
}
