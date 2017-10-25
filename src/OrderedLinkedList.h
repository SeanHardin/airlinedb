/*
 * OrderedLinkedList.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Sean
 *      header for ordered linked list. I have since turned this into
 *      a pure template class.
 *		actually didn't have to change too much to make it template only.
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_

#include "LinkedList.h"


template <class T>
class OrderedLinkedList : public LinkedList<T>{//inherit line
	public:
		void insertOrdered(T& data);
		bool deleteNode(T& data);//any problem with changing return type?
		T searchNode(T& data);
		void listFlight();
};

template <typename T>//inserts into list alphabetically by last name
void OrderedLinkedList<T>::insertOrdered(T& dat){
	node<T> *newNode = new node<T>;//new entry to linkedlist
	newNode->data = dat;
	newNode->next = NULL;
	if(this->head == NULL){//if list is empty
		this->head = this->last = newNode;
		this->count++;
	}else{//list is not empty
		node<T> *current = this->head;
		node<T> *ahead = current->next;
		if (ahead != NULL){//more than 1 element
			if (!(newNode->data > current->data)){//new<first
				newNode->next = current;
				this->head = newNode;
				this->count++;
			} else {//new>first element
				while (ahead != NULL && newNode->data > current->data){//new>current iterating, end current=last
					if (!(newNode->data > ahead->data)){//new<ahead
						newNode->next = ahead;
						current->next = newNode;
						this->count++;
					}
					current=ahead;
					ahead=ahead->next;
				}
				if (newNode->data > current->data){//current is last element here, new comes after it
					current->next = this->last = newNode;
					this->count++;
				}
			}
		} else {//only 1 element
			if (newNode->data > current->data){//new>element
				current->next = newNode;
			} else {//new<element
				newNode->next = current;
				this->head = newNode;
			}
			this->count++;
		}
	}
}

template <typename T>//delete passenger from selected list
bool OrderedLinkedList<T>::deleteNode(T& dat){
	node<T> *current = this->head;//iterator
	if (current != NULL){
		node<T> *ahead = current->next;
		if (dat == current->data){//if first element of list
			this->head = current->next;
			delete current;
			this->count--;
			if (this->count == 0)//if deleting makes list empty
				this->last = NULL;
			return 1;
		}
		while (ahead != NULL){//list has more elements to check
			if (dat == ahead->data){//if any match
				current->next = ahead->next;
				if (ahead == this->last)//if last changes
					this->last = current;
				delete ahead;
				this->count--;
				return 1;
			}
			current = current->next;
			if (current != NULL){//failsafe in case ahead got deleted which would make current null
				ahead = current->next;
			} else {
				ahead = NULL;
			}
		}
	} else {
		cout << "List is empty. You can't delete nothingness." << '\n' << '\n';
	}
	return 0;
}

template <typename T>//searches all lists for passed data
T OrderedLinkedList<T>::searchNode(T& dat){
	node<T> *current = this->head;
	while (current != NULL){//iterate whole list
		if (dat == current->data){//return data to be printed
			return current->data;
		}
		current = current->next;
	}
	return dat;//return passed value if no match
}

template <typename T>//lists all data in a list
void OrderedLinkedList<T>::listFlight(){
	node<T> *current = this->head;
	if (current == NULL){//actually print message in case empty flight
		cout << "That list is currently empty." << '\n';
	}
	while (current != NULL){//prints the list data for each entry
		cout << current->data;
		current = current->next;
	}

}

#endif /* ORDEREDLINKEDLIST_H_ */
