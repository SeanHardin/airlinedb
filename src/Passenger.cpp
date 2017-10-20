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
