#include "Passenger.h"
#include <iostream>
using namespace std;

	string Passenger::getFirstName(){
		return fName;
	}

	void Passenger::setFirstName(string s){
		fName = s;
	}

	string Passenger::getLastName(){
		return lName;
	}

	void Passenger::setLastName(string s){
		lName = s;
	}

	string Passenger::getAddress(){
		return address;
	}

	void Passenger::setAddress(string s){
		address = s;
	}

	string Passenger::getPhoneNo(){
		return phoneNo;
	}

	void Passenger::setPhoneNo(string s){
		phoneNo = s;
	}

	bool operator>(Passenger& p1, Passenger& p2){
		return p1.lName >= p2.lName;
	}

	bool operator==(Passenger& p1, Passenger& p2){
		return (p1.lName == p2.lName) && (p1.fName == p2.fName);
	}

	ostream& operator<<(ostream& os, Passenger p){
		os << p.getFirstName() << ' ' << p.getLastName() << " ["
				<< p.getAddress() << "] [" << p.getPhoneNo()
				<< "]" << '\n';
		return os;
	}
