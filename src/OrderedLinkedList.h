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

template <class T>
class OrderedLinkedList : public LinkedList<T>{
	public:
		void insertOrdered(node<T> * phead);
		void deleteNode(node<T> * phead);
		void searchNode(T* a[]);
		void listFlight(node<T> * phead);
};





#endif /* ORDEREDLINKEDLIST_H_ */
