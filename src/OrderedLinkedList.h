/*
 * OrderedLinkedList.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Sean
 *      header for ordered linked list, includes code for the
 *      operations needed for main to work.
 *
 *      originally tried pure template class, but had some issues
 *      so it is now only partially a template class. shouldn't affect
 *      functionality at all.
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_

#include "Passenger.h"//one of the issues with pure template class...
#include "LinkedList.h"

bool noNumbers(string&);//prototype for function to check if string has numbers

template <class T>
class OrderedLinkedList : public LinkedList<T>{//inherit line
	public:
		template <typename U>
		friend void insertOrdered(LinkedList<U> * phead);
		template <typename U>
		friend void deleteNode(LinkedList<U> * phead);
		template <typename U>
		friend void searchNode(U *pa[]);
		template <typename U>
		friend void listFlight(LinkedList<U> * phead);
};

template <typename T>//inserts into list alphabetically by last name
void insertOrdered(LinkedList<T> * phead){
	Passenger p;//compare passengers with each other, couldn't compare first name without doing this
	string temp;//user input string
	bool changed = 0;//bool to loop user until they input reasonable name
	while (!changed){
		cout << "Enter Passenger's first name:";
		getline (cin, temp);
		if (noNumbers(temp) && temp != ""){//wont take numbers or empty string
			p.setFirstName(temp);
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
			p.setLastName(temp);
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
			p.setAddress(temp);
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
			p.setPhoneNo(temp);
			changed = 1;
		} else {
			cout << "Please enter a real phone number" << '\n';
		}
	}

	node<T> *newNode = new node<T>;//new entry to linkedlist
	newNode->data = p;
	newNode->next = NULL;
	if(phead->head == NULL){//if list is empty
		phead->head = phead->last = newNode;
		phead->count++;
	}else{//list is not empty
		node<T> *current = phead->head;
		node<T> *ahead = current->next;
		if (ahead != NULL){//more than 1 element
			if (!(newNode->data > current->data)){//new<first
				newNode->next = current;
				phead->head = newNode;
				phead->count++;
			} else {//new>first element
				while (ahead != NULL && newNode->data > current->data){//new>current iterating, end current=last
					if (!(newNode->data > ahead->data)){//new<ahead
						newNode->next = ahead;
						current->next = newNode;
						phead->count++;
					}
					current=ahead;
					ahead=ahead->next;
				}
				if (newNode->data > current->data){//current is last element here, new comes after it
					current->next = phead->last = newNode;
					phead->count++;
				}
			}
		} else {//only 1 element
			if (newNode->data > current->data){//new>element
				current->next = newNode;
			} else {//new<element
				newNode->next = current;
				phead->head = newNode;
			}
			phead->count++;
		}
	}
}

template <typename T>//delete passenger from selected list
void deleteNode(LinkedList<T> * phead){
	node<T> *current = phead->head;//iterator
	bool deleted = 0;
	if (current != NULL){
		node<T> *ahead = current->next;
		Passenger p;//for simplicity's sake
		string temp;
		cout << "Enter Passenger's last name:";
		getline (cin, temp);
		while (!noNumbers(temp) || temp == ""){
			cout << "Nobody would have a name like that, try again." << '\n';
			cout << "Enter Passenger's last name:";
			getline (cin, temp);
		}
		p.setLastName(temp);
		cout << "Enter Passenger's first name:";
		getline (cin, temp);
		while (!noNumbers(temp) || temp == ""){
			cout << "Nobody would have a name like that, try again." << '\n';
			cout << "Enter Passenger's first name:";
			getline (cin, temp);
		}
		p.setFirstName(temp);
		if (p == current->data){//if first element of list
			phead->head = current->next;
			delete current;
			deleted = 1;
			phead->count--;
			if (phead->count == 0)//if deleting makes list empty
				phead->last = NULL;
			cout << p.getFirstName() << ' ' << p.getLastName() << " has been removed from the flight." << '\n';
		}
		while (ahead != NULL){//list has more elements to check
			if (p == ahead->data){//if any match
				current->next = ahead->next;
				if (ahead == phead->last)//if last changes
					phead->last = current;
				delete ahead;
				deleted = 1;
				phead->count--;
				cout << p.getFirstName() << ' ' << p.getLastName() << " has been removed from the flight." << '\n';
			}
			current = current->next;
			if (current != NULL){//failsafe in case ahead got deleted which would make current null
				ahead = current->next;
			} else {
				ahead = NULL;
			}
		}
	} else {
		deleted = 1;
		cout << "That flight is currently empty, you can't delete nothingness." << '\n';
	}
	if (!deleted){
		cout << "Nobody by that name was found" << '\n';
	}
}

template <typename T>//searches all lists for passenger
void searchNode(T *pa[]){
	Passenger p;
	string temp;
	bool found = 0;
	cout << "Enter Passenger's last name:";
	getline (cin, temp);
	while (!noNumbers(temp) || temp == ""){//until valid name
		cout << "Nobody would have a name like that, try again." << '\n';
		cout << "Enter Passenger's last name:";
		getline (cin, temp);
	}
	p.setLastName(temp);
	cout << "Enter Passenger's first name:";
		getline (cin, temp);
		while (!noNumbers(temp) || temp == ""){
			cout << "Nobody would have a name like that, try again." << '\n';
			cout << "Enter Passenger's first name:";
			getline (cin, temp);
		}
		p.setFirstName(temp);
	for (int i = 0; i < 4; i++){//for each flight number
		node<Passenger> *current = pa[i]->head;
		while (current != NULL){//iterate whole list
			if (p == current->data){//print data for any matches
				cout << "Flight Number: " << (100 * ( i + 1)) << '\n';//0 for 100, 1 for 200, etc
				cout << "First name: " << current->data.getFirstName() << '\n';
				cout << "Last name: " << current->data.getLastName() << '\n';
				cout << "Address: " << current->data.getAddress() << '\n';
				cout << "Phone: " << current->data.getPhoneNo() << '\n';
				found = 1;
			}
			current = current->next;
		}
	}
	if (!found)
		cout << "That person was not in any of our flights." << '\n';
}

template <typename T>//lists all passengers on a flight
void listFlight(LinkedList<T> * phead){
	node<T> *current = phead->head;
	if (current == NULL){//actually print message in case empty flight
		cout << "That flight is currently empty." << '\n';
	}
	while (current != NULL){//prints the passenger data for each entry
		cout << current->data;
		current = current->next;
	}

}

bool noNumbers(string& s){//checks if a string has no numbers
	bool temp = 1;
	if (s.find('0') < 4294967295) temp = 0;//if number 0 is found, return false
	if (s.find('1') < 4294967295) temp = 0;//etc
	if (s.find('2') < 4294967295) temp = 0;
	if (s.find('3') < 4294967295) temp = 0;
	if (s.find('4') < 4294967295) temp = 0;
	if (s.find('5') < 4294967295) temp = 0;
	if (s.find('6') < 4294967295) temp = 0;
	if (s.find('7') < 4294967295) temp = 0;
	if (s.find('8') < 4294967295) temp = 0;
	if (s.find('9') < 4294967295) temp = 0;
	return temp;
}

#endif /* ORDEREDLINKEDLIST_H_ */
