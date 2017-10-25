/*
 * Passenger.cpp
 *
 *  Created on: Oct 17, 2017
 *      Author: Sean
 *      passenger class, code for passenger functions and
 *      operators is here.
 */
#include "Passenger.h"
#include <iostream>
using namespace std;

	Passenger::Passenger(){
		mfName = mlName = maddress = mphoneNo = "";
	}

	string Passenger::getFirstName(){//gets first name
		return mfName;
	}

	void Passenger::setFirstName(string& s){//sets first name
		mfName = s;
	}

	string Passenger::getLastName(){//gets last name
		return mlName;
	}

	void Passenger::setLastName(string& s){//sets last name
		mlName = s;
	}

	string Passenger::getAddress(){//gets address
		return maddress;
	}

	void Passenger::setAddress(string& s){//sets address
		maddress = s;
	}

	string Passenger::getPhoneNo(){//gets phone number
		return mphoneNo;
	}

	void Passenger::setPhoneNo(string& s){//sets phone number
		mphoneNo = s;
	}

	bool operator>(Passenger& p1, Passenger& p2){//compares 2 passengers by first and last name
		if (p1.mlName == p2.mlName)
			return p1.mfName >= p2.mfName;
		return p1.mlName > p2.mlName;
	}

	bool operator==(Passenger& p1, Passenger& p2){//compares if passengers share last name
		return (p1.mlName == p2.mlName) && (p1.mfName == p2.mfName);
	}

	ostream& operator<<(ostream& os, Passenger& p){//converts passenger to ostream
		os << p.getFirstName() << ' ' << p.getLastName() << " ["
				<< p.getAddress() << "] [" << p.getPhoneNo()
				<< "]" << '\n';
		return os;
	}

	void Passenger::createFullPassenger(){//to insert into list
		string temp;//user input string
		bool changed = 0;//bool to loop user until they input reasonable name
		while (!changed){
			cout << "Enter Passenger's first name:";
			getline (cin, temp);
			if (noNumbers(temp) && temp != ""){//wont take numbers or empty string
				setFirstName(temp);
				changed = 1;
			} else {
				cout << "A name cannot be nothing or have numbers." << '\n';
			}
		}
		changed = 0;
		while (!changed){
			cout << "Enter Passenger's last name:";
			getline (cin, temp);
			if (noNumbers(temp) && temp != ""){
				setLastName(temp);
				changed = 1;
			} else {
				cout << "A name cannot be nothing or have numbers." << '\n';
			}
		}
		changed = 0;
		while (!changed){
			cout << "Enter passenger's address:";
			getline (cin, temp);
			if (temp != ""){//wont take empty string
				setAddress(temp);
				changed = 1;
			} else {
				cout << "Please enter a real address" << '\n';
			}
		}
		changed = 0;
		while (!changed){
			cout << "enter passenger's phone number:";
			getline (cin, temp);
			if (temp != ""){
				setPhoneNo(temp);
				changed = 1;
			} else {
				cout << "Please enter a real phone number" << '\n';
			}
		}
	}

	void Passenger::createPassengerName(){//to compare name with full passenger
		string temp;//user input string
		bool changed = 0;//bool to loop user until they input reasonable name
		while (!changed){
			cout << "Enter Passenger's first name:";
			getline (cin, temp);
			if (noNumbers(temp) && temp != ""){//wont take numbers or empty string
				setFirstName(temp);
				changed = 1;
			} else {
				cout << "A name cannot be nothing or have numbers." << '\n';
			}
		}
		changed = 0;
		while (!changed){
			cout << "Enter Passenger's last name:";
			getline (cin, temp);
			if (noNumbers(temp) && temp != ""){
				setLastName(temp);
				changed = 1;
			} else {
				cout << "A name cannot be nothing or have numbers." << '\n';
			}
		}
	}

	bool Passenger::noNumbers(string& s){//checks if a string has no numbers
		bool temp = 1;
		double limit = 4.294967295*1000000000;
		if (s.find('0') < limit) temp = 0;//if number 0 is found, return false
		if (s.find('1') < limit) temp = 0;//etc
		if (s.find('2') < limit) temp = 0;
		if (s.find('3') < limit) temp = 0;
		if (s.find('4') < limit) temp = 0;
		if (s.find('5') < limit) temp = 0;
		if (s.find('6') < limit) temp = 0;
		if (s.find('7') < limit) temp = 0;
		if (s.find('8') < limit) temp = 0;
		if (s.find('9') < limit) temp = 0;
		return temp;
	}
