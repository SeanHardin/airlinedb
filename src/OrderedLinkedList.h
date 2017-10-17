/*
 * OrderedLinkedList.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Sean
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_

#include "LinkedList.h"

struct OrderedNode : public node{

};

template <class T>
class OrderedLinkedList : public LinkedList{
	public:
		void insertOrdered(node * phead);
		void deleteNode(node * phead);
		void searchNode(T* a[]);
		void listFlight(node * phead);
};





#endif /* ORDEREDLINKEDLIST_H_ */
