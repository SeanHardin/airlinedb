/*
 * OrderedLinkedList.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Sean
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_

#include "Passenger.h"
#include "LinkedList.h"

bool noNumbers(string);

template <class T>
class OrderedLinkedList : public LinkedList<T>{
	public:
		template <typename U>
		friend void insertOrdered(LinkedList<U> * phead, T newData);
		template <typename U>
		friend void deleteNode(LinkedList<U> * phead);
		template <typename U>
		friend void searchNode(U *a[]);
		template <typename U>
		friend void listFlight(LinkedList<U> * phead);

};

template <typename T>
void insertOrdered(LinkedList<T> * phead){
	Passenger p;
	string temp;
	bool changed = false;
	while (!changed){
		cout << "Enter Passenger's first name:";
		getline(cin, temp);
		if (noNumbers(temp) && temp != ""){
			p.setFirstName(temp);
			changed = true;
		} else {
			cout << "A name cannot be nothing or have numbers." << '\n';
		}
	}
	changed = false;
	while (!changed){
		cout << "Enter Passenger's last name:";
		getline(cin, temp);
		if (noNumbers(temp) && temp != ""){
			p.setLastName(temp);
			changed = true;
		} else {
			cout << "A name cannot be nothing or have numbers." << '\n';
		}
	}
	changed = false;
	while (!changed){
		cout << "Enter passenger's address:";
		getline(cin, temp);
		if (temp != ""){
			p.setAddress(temp);
			changed = true;
		} else {
			cout << "Please enter a real address" << '\n';
		}
	}
	changed = false;
	while (!changed){
		cout << "enter passenger's phone number:";
		getline(cin, temp);
		if (temp != ""){
			p.setPhoneNo(temp);
			changed = true;
		} else {
			cout << "Please enter a real phone number" << '\n';
		}
	}

	node<T> *newNode = new node<T>;
	newNode->data = p;
	newNode->next = NULL;
	if(phead->head==NULL){
		phead->head = phead->last = newNode;
		phead->count++;
	}else{
		node<T> *current=phead->head;
		node<T> *ahead=current->next;
		if (ahead != NULL){//more than 1 element
			if (!(newNode->data > current->data)){//new<first
				newNode->next = current;
				phead->head = newNode;
				phead->count++;
			} else {//new>first element
				while (ahead != NULL && newNode->data > current->data){//iterating, end current=last
					if (!(newNode->data > ahead->data)){//new<ahead
						newNode->next = ahead;
						current->next = newNode;
						phead->count++;
					}
					current=ahead;
					ahead=ahead->next;
				}
				if (newNode->data > current->data){
					current->next = newNode;
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

template <typename T>
void deleteNode(LinkedList<T> * phead){
	node<T> *current = phead->head;
	bool deleted = false;
	if (current != NULL){
		node<T> *ahead = current->next;
		Passenger p;
		string temp;
		cout << "Enter Passenger's last name:";
		getline(cin, temp);
		while (!noNumbers(temp) || temp == ""){
			cout << "Nobody would have a name like that, try again." << '\n';
			cout << "Enter Passenger's last name:";
			getline(cin, temp);
		}
		p.setLastName(temp);
		cout << "Enter Passenger's first name:";
		getline(cin, temp);
		while (!noNumbers(temp) || temp == ""){
			cout << "Nobody would have a name like that, try again." << '\n';
			cout << "Enter Passenger's first name:";
			getline(cin, temp);
		}
		p.setFirstName(temp);
		if (p == current->data){
			phead->head = current->next;
			delete current;
			deleted = true;
			phead->count--;
			cout << p.getFirstName() << ' ' << p.getLastName() << " has been removed from the flight." << '\n';
		}
		while (ahead != NULL){
			if (p == ahead->data){
				current->next = ahead->next;
				delete ahead;
				deleted = true;
				phead->count--;
				cout << p.getFirstName() << ' ' << p.getLastName() << " has been removed from the flight." << '\n';
			}
			current = current->next;
			if (current != NULL){
				ahead = current->next;
			} else {
				ahead = NULL;
			}
		}
	} else {
		deleted = true;
		cout << "That flight is currently empty, you can't delete nothingness." << '\n';
	}
	if (!deleted){
		cout << "Nobody by that name was found" << '\n';
	}
}

template <typename T>
void searchNode(T *a[]){
	Passenger p;
	string temp;
	bool found = false;
	cout << "Enter Passenger's last name:";
	getline(cin, temp);
	while (!noNumbers(temp) || temp == ""){
		cout << "Nobody would have a name like that, try again." << '\n';
		cout << "Enter Passenger's last name:";
		getline(cin, temp);
	}
	p.setLastName(temp);
	cout << "Enter Passenger's first name:";
		getline(cin, temp);
		while (!noNumbers(temp) || temp == ""){
			cout << "Nobody would have a name like that, try again." << '\n';
			cout << "Enter Passenger's first name:";
			getline(cin, temp);
		}
		p.setFirstName(temp);
	for (int i = 0; i < 4; i++){
		node<Passenger> *current = a[i]->head;
		while ((current != NULL)){
			if (p == current->data){
				cout << "Flight Number: " << (100*(i+1)) << '\n';
				cout << "First name: " << current->data.getFirstName() << '\n';
				cout << "Last name: " << current->data.getLastName() << '\n';
				cout << "Address: " << current->data.getAddress() << '\n';
				cout << "Phone: " << current->data.getPhoneNo() << '\n';
				found = true;
			}
			current = current->next;
		}
	}
	if (!found)
		cout << "That person was not in any of our flights." << '\n';
}

template <typename T>
void listFlight(LinkedList<T> * phead){
	node<T> *current = phead->head;
	if (current == NULL){
		cout << "That flight is currently empty." << '\n';
	}
	while (current != NULL){
		cout << current->data;
		current = current->next;
	}

}

bool noNumbers(string s){
	bool temp = true;
	if (s.find('0') < 4294967295) temp=false;
	if (s.find('1') < 4294967295) temp=false;
	if (s.find('2') < 4294967295) temp=false;
	if (s.find('3') < 4294967295) temp=false;
	if (s.find('4') < 4294967295) temp=false;
	if (s.find('5') < 4294967295) temp=false;
	if (s.find('6') < 4294967295) temp=false;
	if (s.find('7') < 4294967295) temp=false;
	if (s.find('8') < 4294967295) temp=false;
	if (s.find('9') < 4294967295) temp=false;
	return temp;
}

#endif /* ORDEREDLINKEDLIST_H_ */
