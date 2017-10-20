//============================================================================
// Name        : airlinedb.cpp
// Author      : Sean Hardin
// Version     :
// Copyright   : Your copyright notice
// Description : runs a flight database, users can add, delete
//				 search, list, and exit as prompted.
//
//				 i used my first assignment as the base for this so it looks similar.
//============================================================================
#include <iostream>
#include "OrderedLinkedList.h"
#include <string>
#include <sstream>


using namespace std;

int getFlightNumber();//prototype for function to save some space

int main(){

	cout << "***Sean Hardin's airline database application***"<< '\n';//introduction
	LinkedList<Passenger> *flights[4];//creates array of pointers for the LinkedLists
	for (int i = 0; i < 4; i++){//initialized each flight number
		flights[i] = new OrderedLinkedList<Passenger>;
	}
	cout << "Please choose an operation:" << '\n';//fluff for pseudo UI
	char userInput;//char to read command from user

	while (userInput!='Q' && userInput!= 'q'){//runs until user chooses to quit
		cout<<"A(Add)|S(Search)|D(Delete)|L(List)|Q(Quit)";//list of commands
		string complianceCheckString;//to use sstream/check length

		getline(cin, complianceCheckString);//get user input
		if (complianceCheckString.length()>1) {//if user inputs more than a char
			userInput = 'f';//FOR FAILURE TO COMPLY
		} else {
			stringstream complianceCheck;//to copy user input without prompting them again
			complianceCheck << complianceCheckString;
			complianceCheck>>userInput;//take whatever the user types and sets it in the character
		}
		int flightNumber;
		switch (userInput){//switch statement looks cleaner than nested if loops.
			case 'A' ://capital and lowercase letters for better usability, wasn't sure how to force capitals
			case 'a' :
				flightNumber = getFlightNumber();
				insertOrdered(flights[flightNumber]);//friend function that runs code to add an entry
				break;
			case 'S' ://I DISAGREE WITH THE SPACE BEFORE COLON.
			case 's' :
				searchNode(flights);//friend function to search
				break;
			case 'D' :
			case 'd' :
				flightNumber = getFlightNumber();
				deleteNode(flights[flightNumber]);//friend function to delete
				break;
			case 'L' :
			case 'l' :
				flightNumber = getFlightNumber();
				listFlight(flights[flightNumber]);//friend function to list entries
				break;
			case 'Q' ://doesn't run any extra code on quitting, included just to avoid the default case
			case 'q' ://leaving a bad message before ending program
				break;
			default://if user tries to type anything other than the listed commands
				cout << "Please enter only the letter for the option you want." << '\n';
		}
		if (userInput != 'q' && userInput != 'Q')//reset char so a \0 doesn't run previous operation again
			userInput = 'f';
	}

	for (int i = 0; i < 4; i++){//delete linkedlists after use
		delete flights[i];
	}
	cout << "Thank you for using my flight database!";//mostly a confirmation that the program ended successfully
	return 0;
}

int getFlightNumber(){//returns the index in flights for the flight number chosen
	string input;//to use sstream/check length
	while (true){
		cout << "Please enter the flight number (100, 200, 300, 400):";
		getline(cin, input);//get user input
		if (input == "100"){//ugly if elses cuz switch hates strings
			return 0;
		} else if (input == "200"){
			return 1;
		} else if (input == "300"){
			return 2;
		} else if (input == "400"){
			return 3;
		} else {
			cout << "That is not a valid flight number. Please try again." << '\n';
		}
	}
}
