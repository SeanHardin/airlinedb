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
