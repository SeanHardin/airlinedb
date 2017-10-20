/*
 * Passenger.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Sean
 *      passenger header, prototypes for the passenger class
 */
#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <iostream>
using namespace std;

class Passenger {
	string mfName;
	string mlName;
	string maddress;
	string mphoneNo;

public:
	string getFirstName();//definitions in cpp file.
	void setFirstName(string&);
	string getLastName();
	void setLastName(string&);
	string getAddress();
	void setAddress(string&);
	string getPhoneNo();
	void setPhoneNo(string&);
	friend bool operator>(Passenger&, Passenger&);
	friend bool operator==(Passenger&, Passenger&);
	friend ostream& operator<<(ostream& os, Passenger&);
};

#endif /* PASSENGER_H_ */
