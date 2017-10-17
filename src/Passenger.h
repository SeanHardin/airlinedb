/*
 * Passenger.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Sean
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <iostream>
using namespace std;

class Passenger {
	string fName;
	string lName;
	string address;
	string phoneNo;
public:
	string getFirstName();
	void setFirstName(string);
	string getLastName();
	void setLastName(string);
	string getAddress();
	void setAddress(string);
	string getPhoneNo();
	void setPhoneNo(string);
};




#endif /* PASSENGER_H_ */
